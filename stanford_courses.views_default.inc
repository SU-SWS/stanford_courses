<?php
/**
 * @file
 * stanford_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function stanford_courses_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'stanford_course_sections';
  $view->description = 'Sortable table View of all Stanford Course Section nodes ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Course Sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford Course Sections';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Academic Term */
  $handler->display->display_options['fields']['field_stanford_section_term']['id'] = 'field_stanford_section_term';
  $handler->display->display_options['fields']['field_stanford_section_term']['table'] = 'field_data_field_stanford_section_term';
  $handler->display->display_options['fields']['field_stanford_section_term']['field'] = 'field_stanford_section_term';
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_term']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_term']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_term']['field_api_classes'] = 0;
  /* Field: Content: Course */
  $handler->display->display_options['fields']['field_stanford_section_course']['id'] = 'field_stanford_section_course';
  $handler->display->display_options['fields']['field_stanford_section_course']['table'] = 'field_data_field_stanford_section_course';
  $handler->display->display_options['fields']['field_stanford_section_course']['field'] = 'field_stanford_section_course';
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_course']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_course']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_course']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_stanford_section_course']['field_api_classes'] = 0;
  /* Field: Content: Day(s) of Week */
  $handler->display->display_options['fields']['field_stanford_section_dow']['id'] = 'field_stanford_section_dow';
  $handler->display->display_options['fields']['field_stanford_section_dow']['table'] = 'field_data_field_stanford_section_dow';
  $handler->display->display_options['fields']['field_stanford_section_dow']['field'] = 'field_stanford_section_dow';
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dow']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dow']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dow']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_section_dow']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dow']['field_api_classes'] = 0;
  /* Field: Content: Instructor(s) */
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['id'] = 'field_stanford_section_instrctr';
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['table'] = 'field_data_field_stanford_section_instrctr';
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['field'] = 'field_stanford_section_instrctr';
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_instrctr']['field_api_classes'] = 0;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_stanford_section_location']['id'] = 'field_stanford_section_location';
  $handler->display->display_options['fields']['field_stanford_section_location']['table'] = 'field_data_field_stanford_section_location';
  $handler->display->display_options['fields']['field_stanford_section_location']['field'] = 'field_stanford_section_location';
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_location']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_location']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_section_location']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_location']['field_api_classes'] = 0;
  /* Field: Content: Start and End Dates */
  $handler->display->display_options['fields']['field_stanford_section_dates']['id'] = 'field_stanford_section_dates';
  $handler->display->display_options['fields']['field_stanford_section_dates']['table'] = 'field_data_field_stanford_section_dates';
  $handler->display->display_options['fields']['field_stanford_section_dates']['field'] = 'field_stanford_section_dates';
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dates']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dates']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_stanford_section_dates']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_dates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_section_dates']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_dates']['field_api_classes'] = 0;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_stanford_section_subject']['id'] = 'field_stanford_section_subject';
  $handler->display->display_options['fields']['field_stanford_section_subject']['table'] = 'field_data_field_stanford_section_subject';
  $handler->display->display_options['fields']['field_stanford_section_subject']['field'] = 'field_stanford_section_subject';
  $handler->display->display_options['fields']['field_stanford_section_subject']['label'] = 'Subject(s)';
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_subject']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_subject']['field_api_classes'] = 0;
  /* Field: Content: Time(s) */
  $handler->display->display_options['fields']['field_stanford_section_time']['id'] = 'field_stanford_section_time';
  $handler->display->display_options['fields']['field_stanford_section_time']['table'] = 'field_data_field_stanford_section_time';
  $handler->display->display_options['fields']['field_stanford_section_time']['field'] = 'field_stanford_section_time';
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_time']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_time']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_section_time']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_time']['field_api_classes'] = 0;
  /* Field: Content: Units */
  $handler->display->display_options['fields']['field_stanford_section_units']['id'] = 'field_stanford_section_units';
  $handler->display->display_options['fields']['field_stanford_section_units']['table'] = 'field_data_field_stanford_section_units';
  $handler->display->display_options['fields']['field_stanford_section_units']['field'] = 'field_stanford_section_units';
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_units']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_section_units']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_section_units']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_stanford_section_units']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_course_section' => 'stanford_course_section',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stanford-course-sections';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'stanford-course-sections/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $export['stanford_course_sections'] = $view;

  $view = new view;
  $view->name = 'stanford_courses';
  $view->description = 'Sortable table View of all Stanford Course nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Stanford Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stanford Courses';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Course Title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Academic Year */
  $handler->display->display_options['fields']['field_stanford_course_year']['id'] = 'field_stanford_course_year';
  $handler->display->display_options['fields']['field_stanford_course_year']['table'] = 'field_data_field_stanford_course_year';
  $handler->display->display_options['fields']['field_stanford_course_year']['field'] = 'field_stanford_course_year';
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_year']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_year']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_year']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_stanford_course_code']['id'] = 'field_stanford_course_code';
  $handler->display->display_options['fields']['field_stanford_course_code']['table'] = 'field_data_field_stanford_course_code';
  $handler->display->display_options['fields']['field_stanford_course_code']['field'] = 'field_stanford_course_code';
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_code']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_code']['field_api_classes'] = 0;
  /* Field: Content: General Education Requirement(s) */
  $handler->display->display_options['fields']['field_stanford_course_ger']['id'] = 'field_stanford_course_ger';
  $handler->display->display_options['fields']['field_stanford_course_ger']['table'] = 'field_data_field_stanford_course_ger';
  $handler->display->display_options['fields']['field_stanford_course_ger']['field'] = 'field_stanford_course_ger';
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_ger']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_ger']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_ger']['field_api_classes'] = 0;
  /* Field: Content: Section(s) */
  $handler->display->display_options['fields']['field_stanford_course_section']['id'] = 'field_stanford_course_section';
  $handler->display->display_options['fields']['field_stanford_course_section']['table'] = 'field_data_field_stanford_course_section';
  $handler->display->display_options['fields']['field_stanford_course_section']['field'] = 'field_stanford_course_section';
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_section']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_section']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_stanford_course_section']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_section']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_stanford_course_section']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_section']['field_api_classes'] = 0;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_stanford_course_subject']['id'] = 'field_stanford_course_subject';
  $handler->display->display_options['fields']['field_stanford_course_subject']['table'] = 'field_data_field_stanford_course_subject';
  $handler->display->display_options['fields']['field_stanford_course_subject']['field'] = 'field_stanford_course_subject';
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_stanford_course_subject']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_stanford_course_subject']['field_api_classes'] = 0;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stanford_course' => 'stanford_course',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'stanford-courses';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'stanford-courses/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $export['stanford_courses'] = $view;

  return $export;
}
