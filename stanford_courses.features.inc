<?php
/**
 * @file
 * stanford_courses.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_courses_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_courses_node_info() {
  $items = array(
    'stanford_course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('A course includes information such as title, year, quarter, day(s) and time(s), etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'stanford_course_importer' => array(
      'name' => t('Course Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type to which you can attach Stanford Course Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
