<?php
/**
 * @file
 * Feeds Tamper Plugin to take one string and translate it into another based
 * on a table in the database...
 *
 *  This is a pretty simple plugin. It does a straight compare to what is
 *  provided in $field to keys in the database.
 *
 */

/**
 * Plugin definition
 */
$plugin = array(
  'form' => 'stanford_courses_tag_translate_tamper_form',
  'callback' => 'stanford_courses_tag_translate_tamper_callback',
  'multi' => 'loop',
  'name' => 'Translate into human readable values',
  'category' => 'Other',
 );

/**
 * Implements hook_form().
 *
 * Returns a configuration form for this plugin. But there is none as I decided
 * to move the interface to its own part as it was too complicated/large
 * for the plugin form page.
 *
 */
function stanford_courses_tag_translate_tamper_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Translate these results. You can configure the translation set at !link', array("!link" => l("the configuration page.", "admin/config/stanford/courses/tag-translate")));
  return $form;
}

/**
 * Process the value for a possible human readable version.
 *
 * @param  [type] $source      [description]
 * @param  [type] $item_key    [description]
 * @param  [type] $element_key [description]
 * @param  [type] $field       [description]
 * @param  [type] $settings    [description]
 */
function stanford_courses_tag_translate_tamper_callback($source, $item_key, $element_key, &$field, $settings) {

  // Get the translation table. Don't worry this function is cached.
  $translates = stanford_courses_tag_translate_get_translation_table();
  $index = strtoupper($field);

  // If not in the translation table set to the default value.
  if (!isset($translates[$index])) {
    $default = variable_get("stanford_courses_tag_translation_tag_default", "");

    if ($default == "[original]") {
      return;
    }

    $index_key = array_search($field, $source->items[$item_key][$element_key]);
    unset($source->items[$item_key][$element_key][$index_key]);
    $field = FALSE;

    return;
  }

  // Make the adjustment.
  $field = t(check_plain($translates[$index]->chuman));
}
