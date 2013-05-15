<?php
/**
 * @file
 * stanford_courses.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function stanford_courses_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_16-explode';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '%s',
    'limit' => '',
    'real_separator' => ' ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode on space';
  $export['stanford_course_importer-xpathparser_16-explode'] = $feeds_tamper;

  return $export;
}
