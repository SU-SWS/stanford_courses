<?php
/**
 * @file
 * stanford_courses_minimal.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_courses_minimal_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_stanford_course_minimal_importer';
  $strongarm->value = array();
  $export['menu_options_stanford_course_minimal_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_stanford_course_minimal_importer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_stanford_course_minimal_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_stanford_course_minimal_importer';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_stanford_course_minimal_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_stanford_course_minimal_importer';
  $strongarm->value = '0';
  $export['node_preview_stanford_course_minimal_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_stanford_course_minimal_importer';
  $strongarm->value = 0;
  $export['node_submitted_stanford_course_minimal_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_stanford_course_minimal_importer_pattern';
  $strongarm->value = 'course-minimal-importers/[node:title]';
  $export['pathauto_node_stanford_course_minimal_importer_pattern'] = $strongarm;

  return $export;
}
