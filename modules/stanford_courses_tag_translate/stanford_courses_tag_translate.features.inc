<?php
/**
 * @file
 * stanford_courses_tag_translate2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_courses_tag_translate_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}
