<?php
/**
 * @file
 * Feeds Tamper Plugin
 * Completely remove all existing data prior to saving new data. DANGER!
 */

/**
 * Plugin definition
 */
$plugin = array(
    'callback' => 'stanford_courses_truncate_field_values_callback',
    'multi' => 'direct',
    'name' => 'Truncate Field Data (DANGER!)',
    'category' => 'Other',
);


/**
 * Callback function for feeds tamper truncate_field_values plugin.
 * Deletes all existing data in a field prior to adding the new feed data.
 * Good for when getting duplicate and additional data on fields.
 *
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 * @return [type]              [description]
 */
function stanford_courses_truncate_field_values_callback($source, $item_key, $element_key, &$field, $settings) {

   $field = array();

}
