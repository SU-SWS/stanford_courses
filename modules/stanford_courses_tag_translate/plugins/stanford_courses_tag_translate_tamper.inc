<?php
/**
 * @file
 * Feeds Tamper Plugin to take one string and translate it into another based
 * on a table in the database...
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
 * Returns a configuration form for this plugin
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
 * @return [type]              [description]
 */
function stanford_courses_tag_translate_tamper_callback($source, $item_key, $element_key, &$field, $settings) {

  // Get the translation table. Don't worry this function is cached.
  $translates = stanford_courses_tag_translate_get_translation_table();
  $index = strtolower($field);

  // If not in the translation table just leave the value alone.
  if (!isset($translates[$index])) {
    return;
  }

  $field = t(check_plain($translates[$index]->chuman));

}
