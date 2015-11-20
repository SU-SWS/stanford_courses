<?php
/**
 * @file
 * stanford_courses_tag_translate2.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function stanford_courses_tag_translate_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_course_tag_human'
  $field_bases['field_s_course_tag_human'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_course_tag_human',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
