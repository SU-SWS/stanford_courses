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
 * Plugin implementation of the 'explore_courses_url' widget.
 *
 * @FieldWidget(
 *   id = "explore_courses_url",
 *   label = @Translation("ExploreCourses"),
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
      'api_version' => '',
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
    #$elements = parent::settingsForm($form, $form_state);
    #$elements['placeholder_url']['#access'] = FALSE;
    #$elements['placeholder_title']['#access'] = FALSE;
    $elements['api_version'] = [
      '#type' => 'textfield',
      '#title' => $this->t('API version'),
      '#required' => TRUE,
      '#default_value' => $this->getSetting('api_version'),
      '#access' => TRUE,
      '#element_validate' => [
        [$this, 'validateApi'],
      ],
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
  public function validateApi(array &$element, FormStateInterface $form_state, array &$complete_form) {
    $input = NestedArray::getValue($form_state->getValues(), $element['#parents']);

    if ($form_state::hasAnyErrors()) {
      return;
    }
    try {
      $response = $this->client->request('GET', 'search?view=xml-' . $input, ['base_uri' => 'https://explorecourses.stanford.edu/']);
      $response = (string) $response->getBody();
      $xml = new \SimpleXMLElement($response);
      // Do this as a string, since SimpleXMLElement doesn't like to cast to bools
      if ( (string) $xml->deprecated == 'true') {
        $form_state->setError($element, $this->t("That API version is deprecated. Newest version is: $xml->latestVersion"));
      }
    }
    catch (\Throwable $e) {
      \Drupal::logger('my_module')->notice(var_export($e, true));
      $form_state->setError($element, $this->t('There was a problem querying the ExploreCourses API.'));
    }
  }

  /**
   * {@inheritDoc}
   */
  public function settingsSummary() {
    $summary = [];
    if (empty($this->getSetting('api_version'))) {
      $summary[] = $this->t('No API version Provided');
    }
    else {
      $summary[] = $this->t('API version: @api_version', ['@api_version' => $this->getSetting('api_version')]);
    }
    return $summary;
  }

  /**
   * {@inheritDoc}
   */
  public function formElement(FieldItemListInterface $items, $delta, array $element, array &$form, FormStateInterface $form_state) {
    $element = parent::formElement($items, $delta, $element, $form, $form_state);

    $element['uri']['#access'] = TRUE;
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

      // Check to make sure the xml view is set to the API version we've specified.

      //foreach ($value['filters'] as &$filter_values) {
      //  if (is_array($filter_values)) {
     //     $filter_values = self::flattenValues($filter_values);
     //   }
      //}

      //$value['filters'] = array_filter($value['filters']);

      //if (empty($value['filters'])) {
      //  unset($values[$delta]);
      //  continue;
      //}

      // We may in the future have a configuration value
      // to include the "distinct"key to our API call.
      // This tries to find such a value,
      // and applies the key if it finds it.
      //if ($this->getSetting('select_distinct')) {
      //  $value['filters']['distinct'] = TRUE;
      //}

      //$value['uri'] = Url::fromUri(rtrim($this->getSetting('base_url'), '/') . '/api/2/events', ['query' => $value['filters']])
       // ->toString();

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
  //protected static function flattenValues(array $array): array {
  //  $return = [];
  //  array_walk_recursive($array, function ($a) use (&$return) {
  //    $return[] = $a;
  //  });
  //  return $return;
  //}

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
