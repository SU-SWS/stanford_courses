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
  $context->tag = 'People';
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
        'views-2d9147be40cd77d32915a554bf315858' => array(
          'module' => 'views',
          'delta' => '2d9147be40cd77d32915a554bf315858',
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
  t('People');
  $export['courses_reference'] = $context;

  return $export;
}
