<?php
/**
 * @file
 * stanford_courses_tag_translate2.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function stanford_courses_tag_translate_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_course-field_s_course_tag_human'
  $field_instances['node-stanford_course-field_s_course_tag_human'] = array(
    'bundle' => 'stanford_course',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The human readable translation for the tags coming in from explore courses.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_course_tag_human',
    'label' => 'Tag: Human',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'content_editor_text_format' => 'content_editor_text_format',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'content_editor_text_format' => array(
              'weight' => -10,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Tag: Human');
  t('The human readable translation for the tags coming in from explore courses.');

  return $field_instances;
}
