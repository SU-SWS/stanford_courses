<?php
/**
 * @file
 * stanford_courses.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_courses_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_course_advanced|field_collection_item|field_s_course_section_info|form';
  $field_group->group_name = 'group_s_course_advanced';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_s_course_section_info';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '15',
    'children' => array(
      0 => 'field_s_course_instructor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_course_advanced|field_collection_item|field_s_course_section_info|form'] = $field_group;

  return $export;
}
