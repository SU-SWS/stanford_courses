<?php
/**
 *
 */

function stanford_courses_tag_translate_settings() {
  $render = array();

  stanford_courses_tag_translate_get_translation_table();
  stanford_courses_tag_translate_get_translation_table();
  stanford_courses_tag_translate_get_translation_table();
  stanford_courses_tag_translate_get_translation_table();
  stanford_courses_tag_translate_get_translation_table();
  stanford_courses_tag_translate_get_translation_table();


  $render['tmp']["#markup"] = "<h2>" . t("Hi") . "</h2>";
  return $render;
}
