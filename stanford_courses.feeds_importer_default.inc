<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function stanford_courses_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'stanford_course_importer';
  $feeds_importer->config = array(
    'name' => 'Stanford Course Importer',
    'description' => 'An importer from the Stanford Explore Courses Feed',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'description',
          'xpathparser:4' => 'code',
          'xpathparser:5' => 'gers',
          'xpathparser:6' => 'subject',
          'xpathparser:7' => 'year',
          'xpathparser:8' => 'concat(title,"-",subject,"-",year,"-",code)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
        ),
        'context' => '//courses/course',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'stanford_course',
        'input_format' => '1',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_stanford_course_code',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_stanford_course_ger',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_stanford_course_subject',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_stanford_course_year',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:8',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'author' => 0,
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['stanford_course_importer'] = $feeds_importer;


  return $export;
}
