<?php
/**
 * @file Format date string using date().
 */

$plugin = array(
  'form' => 'stanford_courses_format_form',
  'callback' => 'stanford_courses_format_callback',
  'multi' => 'loop',
  'name' => 'Format date/time string',
  'category' => 'Date/time',
 );

function stanford_courses_format_form($importer, $element_key, $settings) {
  $form = array();
  $form['help']['#markup'] = t('Format a string using the !date function.', array('!date' => l('date()', 'http://www.php.net/manual/en/function.date.php')));
  $form['format']['#type'] = 'textfield';
  $form['format']['#title'] = t('Format string');
  if(isset($settings['format'])) {
    $form['format']['#default_value'] = $settings['format'];
  }
  $form['format']['#size'] = '60';
  $form['format']['#description'] = t('Enter the format you would like to use to output this string. See !datedocs for more information.', array('!datedocs' => l('the date() function documentation', 'http://www.php.net/manual/en/function.date.php'))); 

  
  return $form;
}

function stanford_courses_format_callback($source, $item_key, $element_key, &$field, $settings) {
  if(isset($settings['format'])) {
    $format = $settings['format'];
  }
  $field = date($format, $field);
}
