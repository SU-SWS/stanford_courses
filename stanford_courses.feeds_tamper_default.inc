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
