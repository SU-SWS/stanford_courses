<?php

/**
 * @file
 * Academic Term Sort handler.
 *
 * This filter allows views to Sort by academic term chronologically.
 */

/**
 * Class StanfordDateViewsSortCustom.
 */
class StanfordDateViewsSortCustom extends views_handler_sort {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $definitions = parent::option_definition();
    $values = $this->getValues();
    foreach ($values as $value) {
      $definitions['item_order'][$value]['weight'] = array('default' => 0);
    }
    return $definitions;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    foreach ($this->getSortedValues() as $weight => $value) {
      $form['item_order'][$value]['label'] = array(
        '#markup' => $value,
      );
      $form['item_order'][$value]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#default_value' => $weight,
      );
    }
    $form['#theme'] = 'stanford_date_views_sort_custom';
    $form['#attached']['css'][] = drupal_get_path('module', 'stanford_courses') . '/css/stanford_courses_views.admin.css';
  }

  /**
   * Get the values that can be used in the field.
   *
   * @return array
   *   Possible values of the field.
   */
  public function getValues() {
    $field = field_info_field($this->definition['field_name']);
    $items = array_keys($field['settings']['allowed_values']);
    asort($items);
    return $items;
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $order = $this->getSortedValues();

    $replace_string = '';
    foreach ($order as $weight => $value) {
      $weight = str_pad((string) $weight, 5, 0, STR_PAD_LEFT);
      if (!(int) $weight) {
        $replace_string = "replace(`{$this->real_field}`, '$value', '$weight-$value')";
      }
      else {
        $replace_string = "replace($replace_string, '$value', '$weight-$value')";
      }
    }

    if ($replace_string) {
      $this->query->add_orderby(NULL, $replace_string, $this->options['order'], 'courseTerm');
    }
  }

  /**
   * Get the values in a sorted order based on weight.
   *
   * @return array
   *   Ordered values.
   */
  public function getSortedValues() {
    $items = $this->options['item_order'];

    // If item weights haven't been set yet, use the initial definition.
    if (empty($items) || is_null($items)) {
      $definition = $this->option_definition();
      $items = $definition['item_order'];
    }

    $ordered_items = array();
    foreach ($items as $value => $weight) {
      $ordered_items[$value] = $weight['weight'];
    }
    asort($ordered_items);
    return array_keys($ordered_items);
  }

}
