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
}

/**
 * Implements hook_node_info().
 */
function stanford_courses_node_info() {
  $items = array(
    'stanford_course' => array(
      'name' => t('Stanford Course'),
      'base' => 'node_content',
      'description' => t('An academic course'),
      'has_title' => '1',
      'title_label' => t('Course Title'),
      'help' => '',
    ),
    'stanford_course_importer' => array(
      'name' => t('Stanford Course Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type to which you can attach Stanford Course Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This is a "meta" content type for importing course feeds from http://explorecourses.stanford.edu. See the help section at <strong>admin/help/stanford_courses</strong> for more information.'),
    ),
    'stanford_course_section' => array(
      'name' => t('Stanford Course Section'),
      'base' => 'node_content',
      'description' => t(' A <em>section</em> is an instance of a course, and includes instructor, academic quarter, date and time information, and so forth.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'stanford_course_section_importer' => array(
      'name' => t('Stanford Course Section Importer'),
      'base' => 'node_content',
      'description' => t('This is a meta content type to which you can attach Stanford Course Section Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('This is a "meta" content type for importing course section feeds from http://explorecourses.stanford.edu. See the help section at <strong>admin/help/stanford_courses</strong> for more information.'),
    ),
  );
  return $items;
}
