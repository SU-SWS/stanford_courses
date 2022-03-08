<?php

namespace Drupal\stanford_courses\Plugin\Field\FieldWidget;

use Drupal\Component\Utility\NestedArray;
use Drupal\Core\Cache\CacheBackendInterface;
use Drupal\Core\Field\FieldDefinitionInterface;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Render\Element\Url as UrlElement;
use Drupal\Core\Url;
use Drupal\link\Plugin\Field\FieldWidget\LinkWidget;
use GuzzleHttp\ClientInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Plugin implementation of the 'localist_url' widget.
 *
 * @FieldWidget(
 *   id = "localist_url",
 *   label = @Translation("Localist"),
 *   field_types = {
 *     "link"
 *   }
 * )
 */
class ExploreCoursesUrlWidget extends LinkWidget {

  /**
   * Http Client Service.
   *
   * @var \GuzzleHttp\ClientInterface
   */
  protected $client;

  /**
   * Caching service.
   *
   * @var \Drupal\Core\Cache\CacheBackendInterface
   */
  protected $cache;

  /**
   * Caching key
   *
   * @var String
   */
  protected $cache_key;

  /**
   * {@inheritDoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $plugin_id,
      $plugin_definition,
      $configuration['field_definition'],
      $configuration['settings'],
      $configuration['third_party_settings'],
      $container->get('http_client'),
      $container->get('cache.default')
    );
  }

  /**
   * {@inheritDoc}
   */
  public static function defaultSettings() {
    $settings = [
      'base_url' => '',
      'select_distinct' => FALSE,
    ];
    return $settings + parent::defaultSettings();
  }

  /**
   * {@inheritDoc}
   */
  public function __construct($plugin_id, $plugin_definition, FieldDefinitionInterface $field_definition, array $settings, array $third_party_settings, ClientInterface $client, CacheBackendInterface $cache) {
    parent::__construct($plugin_id, $plugin_definition, $field_definition, $settings, $third_party_settings);
    $this->client = $client;
    $this->cache = $cache;
    $this->cache_key = 'explorecourses';
  }

  /**
   * {@inheritDoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    $elements = parent::settingsForm($form, $form_state);
    $elements['placeholder_url']['#access'] = FALSE;
    $elements['placeholder_title']['#access'] = FALSE;

    $elements['api_version'] = [
      '#type' => 'text',
      '#title' => $this->t('API version'),
      '#required' => TRUE,
      '#default_value' => $this->getSetting('api_version'),
    ];
    return $elements;
  }

  /**
   * Validate the given domain has a localist API response.
   *
   * @param array $element
   *   Url form element.
   * @param \Drupal\Core\Form\FormStateInterface $form_state
   *   Current form state object.
   * @param array $complete_form
   *   Complete form.
   */
  public function validateUrl(array &$element, FormStateInterface $form_state, array &$complete_form) {
    $input = NestedArray::getValue($form_state->getValues(), $element['#parents']);
    if ($form_state::hasAnyErrors()) {
      return;
    }
    try {
      $response = $this->client->request('GET', '/api/2/events', ['base_uri' => $input]);
      $response = json_decode((string) $response->getBody(), TRUE);

      if (!is_array($response)) {
        throw new \Exception('Invalid response');
      }
    }
    catch (\Throwable $e) {
      $form_state->setError($element, $this->t('URL is not a Localist domain.'));
    }
  }

  /**
   * {@inheritDoc}
   */
  public function settingsSummary() {
    $summary = [];
    if (empty($this->getSetting('base_url'))) {
      $summary[] = $this->t('No Base URL Provided');
    }
    else {
      $summary[] = $this->t('Base URL: @url', ['@url' => $this->getSetting('base_url')]);
    }
    return $summary;
  }

  /**
   * {@inheritDoc}
   */
  public function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    $element = parent::formElement($items, $delta, $element, $form, $form_state);

    $element['uri']['#access'] = FALSE;
    $element['title']['#access'] = FALSE;
    $element['attributes']['#access'] = FALSE;
    $item = $items[$delta];


    return $element;
  }

  /**
   * {@inheritDoc}
   */
  public function massageFormValues(array $values, array $form, FormStateInterface $form_state) {

    foreach ($values as $delta => &$value) {

      foreach ($value['filters'] as &$filter_values) {
        if (is_array($filter_values)) {
          $filter_values = self::flattenValues($filter_values);
        }
      }

      $value['filters'] = array_filter($value['filters']);

      if (empty($value['filters'])) {
        unset($values[$delta]);
        continue;
      }

      $value['filters']['days'] = '365';
      $value['filters']['pp'] = '100';

      // We may in the future have a configuration value
      // to include the "distinct"key to our API call.
      // This tries to find such a value,
      // and applies the key if it finds it.
      if ($this->getSetting('select_distinct')) {
        $value['filters']['distinct'] = TRUE;
      }

      $value['uri'] = Url::fromUri(rtrim($this->getSetting('base_url'), '/') . '/api/2/events', ['query' => $value['filters']])
        ->toString();

    }
    return parent::massageFormValues($values, $form, $form_state);
  }

  /**
   * Flatten a multidimensional array.
   *
   * @param array $array
   *   The array to flatten.
   *
   * @return array
   *   Flattened array.
   */
  protected static function flattenValues(array $array): array {
    $return = [];
    array_walk_recursive($array, function ($a) use (&$return) {
      $return[] = $a;
    });
    return $return;
  }

  /**
   * Call the ExploreCourses API and return the data in array format.
   *
   * @param string $uri
   *   API endpoint.
   *
   * @return array
   *   API response data.
   *
   * @see https://developer.localist.com/doc/api
   */
  public function fetchExploreCoursesData($uri): array {
    if ($cache = $this->cache->get($this->cache_key . ":" . $uri)) {
      return $cache->data;
    }
    try {
      $response = $this->client->request('GET', "/api/2/$uri?pp=$count&page=$page", ['base_uri' => $this->getSetting('base_url')]);
      return json_decode((string) $response->getBody(), TRUE);
    }
    catch (\Throwable $e) {
      return [];
    }
    $this->cache->set($this->cache_key . ":" . $uri, $data, time() + 60 * 60 * 24);
    return $data;
  }

}
