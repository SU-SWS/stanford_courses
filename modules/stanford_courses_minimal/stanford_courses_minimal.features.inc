<?php
/**
 * @file
 * stanford_courses_minimal.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_courses_minimal_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function stanford_courses_minimal_node_info() {
  $items = array(
    'stanford_course_minimal_importer' => array(
      'name' => t('Minimal Course Importer'),
      'base' => 'node_content',
      'description' => t('This is a content type for importing the slimmed-down version of courses (no section information) from explorecourses.stanford.edu.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
