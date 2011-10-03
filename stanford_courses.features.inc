<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function stanford_courses_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function stanford_courses_node_info() {
  $items = array(
    'stanford_course' => array(
      'name' => t('Stanford Course'),
      'module' => 'features',
      'description' => t('An academic course'),
      'has_title' => '1',
      'title_label' => t('Course Title'),
      'has_body' => '1',
      'body_label' => t('Course Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function stanford_courses_views_api() {
  return array(
    'api' => '2',
  );
}
