<?php
/**
 * @file
 * stanford_courses.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function stanford_courses_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'stanford_course_importer';
  $feeds_importer->config = array(
    'name' => 'Course Importer',
    'description' => 'Imports course information from explorecourses.stanford.edu',
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
          'xpathparser:8' => 'concat(sections/section/subject,"-",sections/section/code,"-",sections/section/courseId)',
          'xpathparser:9' => 'sections/section/term',
          'xpathparser:10' => 'sections/section/schedules/schedule[1]/days',
          'xpathparser:11' => 'sections/section/schedules/schedule[1]/location',
          'xpathparser:12' => 'sections/section/schedules/schedule[1]/startTime',
          'xpathparser:20' => 'sections/section/schedules/schedule[1]/endTime',
          'xpathparser:13' => 'tags/tag/organization',
          'xpathparser:14' => 'tags/tag/name',
          'xpathparser:15' => 'sections/section/term',
          'xpathparser:16' => 'concat(subject,code)',
          'xpathparser:17' => 'sections/section/schedules/schedule[1]/startDate',
          'xpathparser:18' => 'sections/section/schedules/schedule[1]/endDate',
          'xpathparser:19' => 'code',
          'xpathparser:21' => 'sections/section/sectionNumber',
          'xpathparser:22' => 'sections/section/component',
          'xpathparser:23' => 'sections/section/classId',
          'xpathparser:24' => 'sections/section',
          'xpathparser:25' => 'sections/section/units',
          'xpathparser:26' => 'grading',
        ),
        'rawXML' => array(
          // Return raw XML. See $feeds_tamper->source = 'xpathparser:24' in
          // stanford_courses.feeds_tamper_default.inc.
          'xpathparser:24' => 'xpathparser:24',
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
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
          'xpathparser:20' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:25' => 0,
          'xpathparser:26' => 0,
        ),
        'context' => '//courses/course',
        'exp' => array(
          'errors' => 1,
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
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:20' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
            'xpathparser:25' => 0,
            'xpathparser:26' => 0,
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
            'source' => 'xpathparser:8',
            'target' => 'field_s_course_scid',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_s_course_section_info:field_s_course_term',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_s_course_section_info:field_s_course_dow',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_s_course_section_info:field_s_course_location',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_s_course_section_info:field_s_course_time',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_s_course_section_info:field_s_course_time_end',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_s_course_tag_org',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_s_course_tag_name',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_s_course_section_info:field_s_course_section_year',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_s_course_ec_link:url',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_s_course_section_info:field_s_course_section_dates:start',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_s_course_section_info:field_s_course_section_dates:end',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_s_course_code_integer',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_s_course_section_info:field_s_course_section_number',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_s_course_section_info:field_s_course_component',
            'unique' => FALSE,
          ),
          23 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_s_course_section_info:field_s_course_section_class_id',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_s_course_section_info:field_s_course_instructor',
            'unique' => FALSE,
          ),
          25 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_s_course_section_info:field_s_course_units',
            'unique' => FALSE,
          ),
          26 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_s_course_grading',
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
    'content_type' => 'stanford_course_importer',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['stanford_course_importer'] = $feeds_importer;

  return $export;
}
