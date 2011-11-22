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
    'description' => 'Imports course information from explorecourses.stanford.edu',
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
          'xpathparser:8' => 'concat(administrativeInformation/courseId,"-",subject,"-",code)',
          'xpathparser:9' => 'administrativeInformation/courseId',
          'xpathparser:10' => 'tags/tag/organization',
          'xpathparser:11' => 'tags/tag/name',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
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
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
          ),
        ),
        'allow_override' => 0,
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
          7 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_stanford_course_course_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_stanford_course_tag_org',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_stanford_course_tag_name',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
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

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'stanford_course_section_importer';
  $feeds_importer->config = array(
    'name' => 'Stanford Course Section Importer',
    'description' => 'Imports course sections from explorecourses.stanford.edu',
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
          'xpathparser:0' => 'classId',
          'xpathparser:2' => 'term',
          'xpathparser:3' => 'subject',
          'xpathparser:4' => 'code',
          'xpathparser:5' => 'units',
          'xpathparser:6' => 'sectionNumber',
          'xpathparser:7' => 'component',
          'xpathparser:8' => 'courseId',
          'xpathparser:9' => 'instructor/name',
          'xpathparser:10' => 'schedules/schedule/days',
          'xpathparser:11' => 'schedules/schedule/startDate',
          'xpathparser:12' => 'schedules/schedule/endDate',
          'xpathparser:15' => 'concat(subject,"-",classId)',
          'xpathparser:17' => 'schedules/schedule/location',
          'xpathparser:18' => 'schedules/schedule/startTime',
          'xpathparser:19' => 'schedules/schedule/endTime',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:15' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
        ),
        'context' => '//courses/course/sections/section',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:15' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'stanford_section',
        'input_format' => '1',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_stanford_section_term',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_stanford_section_subject',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_stanford_section_code',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_stanford_section_unit',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_stanford_section_number',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_stanford_section_component',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_stanford_section_course_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_stanford_section_instrctr',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_stanford_section_dow',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_stanford_section_dates:start',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_stanford_section_dates:end',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:15',
            'target' => 'title',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_stanford_section_location',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_stanford_section_time_strt',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_stanford_section_time_end',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['stanford_course_section_importer'] = $feeds_importer;

  return $export;
}
