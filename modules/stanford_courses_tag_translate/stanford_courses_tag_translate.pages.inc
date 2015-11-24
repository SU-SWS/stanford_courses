<?php
/**
 *
 */

/**
 * [stanford_courses_tag_translate_settings description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_settings() {
  $render = array();

  // Get the stuff out of the DB.
  $results = stanford_courses_tag_translate_get_translation_table();

  // If nothing there then provide some options.
  if (!$results) {

    $render["ttable"]["#markup"] = "<h3>" . t("No, translations found. Please start by !create or !import.",
      array(
        '!create' => l("creating one", "admin/config/stanford/courses/tag-translate/new"),
        '!import' => l("importing some defaults", "admin/config/stanford/courses/tag-translate/import"),
      )
    );
  }

  if ($results) {
    $render["ttable"] = stanford_courses_tag_translate_get_table_list($results);
  }

  return $render;
}

/**
 * Return a table render array of the results from the db.
 * @param  array  $results [description]
 * @return [type]          [description]
 */
function stanford_courses_tag_translate_get_table_list($results = array()) {
  $render = array();

  $render["#theme"] = "table";
  $render["#header"] = array("Tag", "Translation", "Operations");
  $rows = array();

  foreach ($results as $values) {

    $opts = "";
    $opts .= l(t("Edit"), "admin/config/stanford/courses/tag-translate/edit/" . $values->ctid);
    $opts .= " | ";
    $opts .= l(t("Delete"), "admin/config/stanford/courses/tag-translate/delete/" . $values->ctid);

    $rows[] = array($values->ctag, $values->chuman, $opts);

  }

  $render["#rows"] = $rows;
  return $render;
}


/**
 * [stanford_courses_tag_translate_new description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_new() {
  $render = array();
  drupal_set_title("Create new courses tag translation");

  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_fields_form");

  return $render;
}

/**
 * Create / Edit translate tag form.
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_courses_tag_translate_fields_form($form, &$form_state, $ftype = "new", $tobj = NULL) {

  $form["ctag"] = array(
    "#type" => 'textfield',
    "#description" => t("The tag used on explore courses. eg: ABC:defg"),
    "#default_value" => isset($tobj->ctag) ? $tobj->ctag : "",
    "#required" => TRUE,
  );

  $form["chuman"] = array(
    "#type" => 'textfield',
    "#description" => t("The human readable translation of the tag"),
    "#default_value" => isset($tobj->chuman) ? $tobj->chuman : "",
    "#required" => TRUE,
  );

  $form["ftype"] = array(
    '#type' => 'value',
    '#value' => $ftype,
  );

  // If on the edit form pass along the ctid.
  if (isset($tobj->ctid)) {
    $form["ctid"] = array(
      '#type' => 'value',
      '#value' => $tobj->ctid,
    );
  }

  $form["submit"] = array(
    '#type' => "submit",
    "#value" => t("Save"),
  );

  return $form;
}


/**
 * Create / Edit translate tag form.
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function stanford_courses_tag_translate_fields_form_validate(&$form, &$form_state) {
  $values = $form_state["values"];

  if ($values['ftype'] == "new") {

    $result = db_select('stanford_courses_tag', 'sct')
            ->fields('sct')
            ->condition("ctag", check_plain($values["ctag"]))
            ->execute();

    if ($result->rowCount()) {
      form_set_error("ctag", t("Translation for that tag already exists. There can only be one translation per tag."));
    }

  }

}

/**
 * Create / Edit translate tag form.
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function stanford_courses_tag_translate_fields_form_submit(&$form, &$form_state) {
  $values = $form_state["values"];

  $insert = array(
    "ctag" => strtoupper(filter_xss($values["ctag"])),
    "chuman" => filter_xss($values['chuman']),
    "ctid" => filter_xss($values['ctid']),
  );

  if ($values["ftype"] == "new") {
    drupal_write_record("stanford_courses_tag", $insert);
  }
  else {
    drupal_write_record("stanford_courses_tag", $insert, "ctid");
  }

  drupal_set_message("Tag translation was saved successfully", "status");
}


/**
 * [stanford_courses_tag_translate_edit description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_edit($ctid) {
  $render = array();

  if (!is_numeric($ctid)) {
    drupal_set_message("Invalid course tag translation id.", "error");
    return drupal_not_found();
  }

  $tobj = stanford_courses_tag_translate_get_translation($ctid);

  if (!$tobj) {
    drupal_set_message("Invalid course tag translation id.", "error");
    return drupal_not_found();
  }

  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_fields_form", "edit", $tobj);

  return $render;
}

/**
 * [stanford_courses_tag_translate_delete description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_delete_form($form, &$form_state, $ctid) {

  if (!is_numeric($ctid)) {
    drupal_set_message("Invalid course tag translation id.", "error");
    drupal_not_found();
    exit();
  }

  $tobj = stanford_courses_tag_translate_get_translation($ctid);

  if (!$tobj) {
    drupal_set_message("Invalid course tag translation id.", "error");
    drupal_not_found();
    exit();
  }

  $form["ctid"] = array(
    "#type" => "value",
    "#value" => $ctid,
  );

  $question = t("Are you sure you want to remove this tag translation");
  $path = "admin/config/stanford/courses/tag-translate";
  $description = t("This action cannot be un-done. Choose wisely.");
  $yes = t("Yes, delete this forever");

  $form = confirm_form($form, $question, $path, $description, $yes);

  return $form;
}

/**
 * [stanford_courses_tag_translate_delete_form_submit description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_courses_tag_translate_delete_form_submit($form, &$form_state) {
  $values = $form_state["values"];
  $ctid = check_plain($values["ctid"]);
  db_delete("stanford_courses_tag")
    ->condition("ctid", $ctid)
    ->execute();

  drupal_set_message("Tag translation was successfully removed.", "status");
  drupal_goto("admin/config/stanford/courses/tag-translate");
}

/**
 * [stanford_courses_tag_translate_import description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_import() {
  $render = array();

  // Caution:
  drupal_set_message("WARNING: Importing new values will empty and replace all existing values. This action is not recoverable.", "warning");

  // Get basic form block.
  $render["theform"] = drupal_get_form("stanford_courses_tag_translate_export_form");
  // Done done delta 58.
  return $render;
}

/**
 * [stanford_courses_tag_translate_import_validate description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_courses_tag_translate_import_form_validate($form, &$form_state) {
  $values = $form_state["values"];
  $json = filter_xss($values["txtxprt"]);
  $decode = drupal_json_decode($json);
  if (!$decode) {
    form_set_error("txtxprt", "Invalid input code. Please check the integrity of the export.");
  }
}

/**
 * [stanford_courses_tag_translate_import_submit description]
 * @param  [type] $form        [description]
 * @param  [type] &$form_state [description]
 * @return [type]              [description]
 */
function stanford_courses_tag_translate_import_form_submit($form, &$form_state) {
  $values = $form_state["values"];
  $json = filter_xss($values["txtxprt"]);
  $decode = drupal_json_decode($json);

  // Remove existing ones.
  db_truncate("stanford_courses_tag")->execute();

  // Add new ones.
  foreach($decode as $key => $value) {
    $insert = array("ctag" => $key, "chuman" => $value);
    drupal_write_record("stanford_courses_tag", $insert);
  }

  drupal_set_message("Import successfull", "status");
  drupal_goto("admin/config/stanford/courses/tag-translate");

}

/**
 * [stanford_courses_tag_translate_export description]
 * @return [type] [description]
 */
function stanford_courses_tag_translate_export() {
  $render = array();

  $results = stanford_courses_tag_translate_get_translation_table();

  if (empty($results)) {
    $render["tmp"]["#markup"] = "<h3>" . t("Nothing to export.") . "</h3>";
    return $render;
  }

  $xport_values = array();
  foreach ($results as $key => $values) {
    $xport_values[$key] = $values->chuman;
  }

  $xport_code = drupal_json_encode($xport_values);
  $xport_code = str_replace("{\"", "{\n\"", $xport_code);
  $xport_code = str_replace("\"}", "\"\n}", $xport_code);
  $xport_code = str_replace("\":\"", "\": \"", $xport_code);
  $xport_code = preg_replace("\",\"", ",\n", $xport_code);

  $render['theform'] = drupal_get_form("stanford_courses_tag_translate_export_form", $xport_code);
  unset($render["theform"]["submit"]);

  return $render;
}

/**
 * [stanford_courses_tag_translate_export_form description]
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function stanford_courses_tag_translate_export_form($form, &$form_state, $default_value) {

  $form["txtxprt"] = array(
    "#type" => "textarea",
    "#title" => t("Export code"),
    "#default_value" => $default_value,
    "#rows" => 30,
  );

  // Add submit button.
  $form["submit"] = array(
    "#type" => "submit",
    "#value" => "Import",
  );

  // Add submit and validate hooks.
  $form["#validate"][] = "stanford_courses_tag_translate_import_form_validate";
  $form["#submit"][] = "stanford_courses_tag_translate_import_form_submit";

  return $form;
}
