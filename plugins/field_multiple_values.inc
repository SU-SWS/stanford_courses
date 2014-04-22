<?php
/**
 * @file
 * Feeds Tamper Plugin
 * Run values through some date math processing().
 */

/**
 * Plugin definition
 */
$plugin = array(
    'form' => 'stanford_courses_field_multiple_values_form',
    'callback' => 'stanford_courses_field_multiple_values_callback',
    'multi' => 'direct',
    'name' => 'Mulitple Values to Multiple Value Field',
    'category' => 'Field Collection',
);

/**
 * Implements hook_form().
 *
 * Returns a configuration form for the field_multiple_values feeds tamper plugin
 */
function stanford_courses_field_multiple_values_form($importer, $element_key, $settings) {
    $form = array();
    return $form;
}

/**
 * Callback function for feeds tamper datemath plugin. Processes input data into
 * a time and performs date math like 'add one day' to it.
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 * @return [type]              [description]
 */
function stanford_courses_field_multiple_values_callback($source, $item_key, $element_key, &$field, $settings) {

   $new_field = array();
   $values = array();

   if (is_array($field)) {
     foreach ($field as $section) {
         $values[] = new SimpleXMLElement($section);
     }
   }
    else {
        $values[] = new SimpleXMLElement($field);
    }

   $field = array();

   foreach($values as $k => $v) {

       foreach ($v->xpath('//instructor') as $instructor) {
          $field[$k][] = (string) $instructor->name;
       }

   }

}
