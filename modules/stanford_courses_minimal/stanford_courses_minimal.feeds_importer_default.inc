<?php
/**
 * @file
 * stanford_courses_minimal.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function stanford_courses_minimal_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'stanford_course_minimal_importer';
  $feeds_importer->config = array(
    'name' => 'Course (Class) Importer',
    'description' => 'A slimmed-down version of the Stanford Course Importer, that does not import section information.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'concat(administrativeInformation/courseId,"-",subject,"-",code,"-",year)',
          'xpathparser:1' => 'title',
          'xpathparser:2' => 'description',
          'xpathparser:3' => 'year',
          'xpathparser:4' => 'gers',
          'xpathparser:5' => 'subject',
          'xpathparser:6' => 'code',
          'xpathparser:7' => 'administrativeInformation/courseId',
          'xpathparser:16' => 'concat(subject,code)',
          'xpathparser:19' => 'code',
          'xpathparser:26' => 'grading',
          'xpathparser:27' => 'tags/tag',
        ),
        'rawXML' => array(
          'xpathparser:27' => 'xpathparser:27',
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:16' => 0,
          'xpathparser:19' => 0,
          'xpathparser:26' => 0,
        ),
        'context' => '//courses/course',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:16' => 0,
            'xpathparser:19' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_s_course_year',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_s_course_ger',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_s_course_subject',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_s_course_code',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_s_course_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_s_course_ec_link:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_s_course_code_integer',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_s_course_grading',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_s_course_ec_tag',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'authorize' => 1,
        'skip_hash_check' => 1,
        'bundle' => 'stanford_course',
      ),
    ),
    'content_type' => 'stanford_course_minimal_importer',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['stanford_course_minimal_importer'] = $feeds_importer;

  return $export;
}
