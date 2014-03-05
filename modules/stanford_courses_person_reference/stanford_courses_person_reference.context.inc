<?php
/**
 * @file
 * stanford_courses_person_reference.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function stanford_courses_person_reference_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'courses_reference';
  $context->description = 'A list of courses taught by a person.';
  $context->tag = 'Courses';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'stanford_person' => 'stanford_person',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-314278560b13258b4cf909ef7feab5ac' => array(
          'module' => 'views',
          'delta' => '314278560b13258b4cf909ef7feab5ac',
          'region' => 'sidebar_second',
          'weight' => '49',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A list of courses taught by a person.');
  t('Courses');
  $export['courses_reference'] = $context;

  return $export;
}
