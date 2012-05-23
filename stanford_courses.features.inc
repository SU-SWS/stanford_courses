<?php
/**
 * @file
 * Defines Features for the Stanford Courses module.
 */

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
    'stanford_course_importer' => array(
      'name' => t('Stanford Course Importer'),
      'module' => 'features',
      'description' => t('This is a meta content type to which you can attach Stanford Course Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => 'This is a "meta" content type for importing course feeds from http://explorecourses.stanford.edu. See the help section at <strong>admin/help/stanford_courses</strong> for more information.',
    ),
    'stanford_course_section_importer' => array(
      'name' => t('Stanford Course Section Importer'),
      'module' => 'features',
      'description' => t('This is a meta content type to which you can attach Stanford Course Section Importer feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => 'This is a "meta" content type for importing course section feeds from http://explorecourses.stanford.edu. See the help section at <strong>admin/help/stanford_courses</strong> for more information.',
    ),
    'stanford_section' => array(
      'name' => t('Stanford Course Section'),
      'module' => 'features',
      'description' => t(' A <em>section</em> is an instance of a course, and includes instructor, academic quarter, date and time information, and so forth.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
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
