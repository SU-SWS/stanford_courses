<?php
/**
 * @file
 * stanford_course_class_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function stanford_course_class_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_class_importer-xpathparser_16-rewrite';
  $feeds_tamper->importer = 'stanford_course_class_importer';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'http://explorecourses.stanford.edu/search?view=catalog&filter-coursestatus-Active=on&page=0&catalog=&q=[xpathparser:16]',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Rewrite';

  $export[$feeds_tamper->id] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_class_importer-xpathparser_16-urlencode_plugin';
  $feeds_tamper->importer = 'stanford_course_class_importer';
  $feeds_tamper->source = 'xpathparser:16';
  $feeds_tamper->plugin_id = 'urlencode_plugin';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'URL Encode';

  $export[$feeds_tamper->id] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_class_importer-xpathparser_19-find_replace_regex';
  $feeds_tamper->importer = 'stanford_course_class_importer';
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

  $export[$feeds_tamper->id] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_class_importer-xpathparser_27-find_replace_regex';
  $feeds_tamper->importer = 'stanford_course_class_importer';
  $feeds_tamper->source = 'xpathparser:27';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/<\\/organization>\\s{1,}<name>/',
    'replace' => '::',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Replace closing/opening tags with double-colon';

  $export[$feeds_tamper->id] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'stanford_course_class_importer-xpathparser_27-find_replace_regex_2';
  $feeds_tamper->importer = 'stanford_course_class_importer';
  $feeds_tamper->source = 'xpathparser:27';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/<\\/?organization>|<\\/?tag>|<\\/?name>|\\s{2,}/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Clean up additional XML';

  $export[$feeds_tamper->id] = $feeds_tamper;

  return $export;
}
