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
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_10-find_replace_regex';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\s{1,1000}/',
    'replace' => ' ',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace whitespace via regex';
  $export['stanford_course_importer-xpathparser_10-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_10-trim';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'trim';
  $feeds_tamper->settings = array(
    'mask' => '',
    'side' => 'trim',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Trim whitespace from beginning and end';
  $export['stanford_course_importer-xpathparser_10-trim'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_12-format_plugin';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'format_plugin';
  $feeds_tamper->settings = array(
    'format' => 'g:ia',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Format date/time string';
  $export['stanford_course_importer-xpathparser_12-format_plugin'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_12-strtotime';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:12';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['stanford_course_importer-xpathparser_12-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_15-substr_plugin';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:15';
  $feeds_tamper->plugin_id = 'substr_plugin';
  $feeds_tamper->settings = array(
    'start' => '0',
    'length' => '4',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Substring';
  $export['stanford_course_importer-xpathparser_15-substr_plugin'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_16-rewrite';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://explorecourses.stanford.edu/search?view=catalog&filter-coursestatus-Active=on&page=0&catalog=&q=[xpathparser:16]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';
  $export['stanford_course_importer-xpathparser_16-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_16-urlencode_plugin';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'urlencode_plugin';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'URL Encode';
  $export['stanford_course_importer-xpathparser_16-urlencode_plugin'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_17-strtotime';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:17';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['stanford_course_importer-xpathparser_17-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_17-subtract_two_weeks';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:17';
  $feeds_tamper->plugin_id = 'math';
  $feeds_tamper->settings = array(
    'operation' => 'subtraction',
    'value' => '1209600',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Subtract two weeks';
  $export['stanford_course_importer-xpathparser_17-subtract_two_weeks'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_19-find_replace_regex';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:19';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/[^0-9]/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Strip letters';
  $export['stanford_course_importer-xpathparser_19-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_20-format_plugin';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:20';
  $feeds_tamper->plugin_id = 'format_plugin';
  $feeds_tamper->settings = array(
    'format' => 'g:ia',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Format date/time string';
  $export['stanford_course_importer-xpathparser_20-format_plugin'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_20-strtotime';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:20';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['stanford_course_importer-xpathparser_20-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_importer-xpathparser_9-substr_plugin';
  $feeds_tamper->importer = 'stanford_course_importer';
  $feeds_tamper->source = 'xpathparser:9';
  $feeds_tamper->plugin_id = 'substr_plugin';
  $feeds_tamper->settings = array(
    'start' => '10',
    'length' => '',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Substring';
  $export['stanford_course_importer-xpathparser_9-substr_plugin'] = $feeds_tamper;

  return $export;
}
