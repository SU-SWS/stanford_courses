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
  $field_group->identifier = 'group_coursenum_group|node|stanford_course|default';
  $field_group->group_name = 'group_coursenum_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_course';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Course Number Group',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_course_code',
      1 => 'field_s_course_subject',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Course Number Group',
      'instance_settings' => array(
        'classes' => 'group-coursenum-group field-group-div course-number summary',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_coursenum_group|node|stanford_course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_morelink_group|node|stanford_course|default';
  $field_group->group_name = 'group_morelink_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'More Link Group',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_course_ec_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'More Link Group',
      'instance_settings' => array(
        'classes' => 'group-morelink-group field-group-div more-link',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_morelink_group|node|stanford_course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_course_advanced|node|stanford_course|form';
  $field_group->group_name = 'group_s_course_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '15',
    'children' => array(
      0 => 'field_s_course_code_integer',
      1 => 'field_s_course_ec_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-course-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_course_advanced|node|stanford_course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_postcard_content|node|stanford_course|default';
  $field_group->group_name = 'group_s_postcard_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Postcard Content',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'group_coursenum_group',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Postcard Content',
      'instance_settings' => array(
        'classes' => 'group-s-postcard-content field-group-div postcard-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_postcard_content|node|stanford_course|default'] = $field_group;

  return $export;
}
