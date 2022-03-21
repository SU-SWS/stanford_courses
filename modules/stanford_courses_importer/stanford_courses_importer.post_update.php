<?php

/**
 * @file
 * stanford_courses_importer.post_update.php
 */

use Drupal\migrate\MigrateMessage;
use Drupal\migrate_tools\MigrateExecutable;
use Drupal\Core\Config\FileStorage;

/**
 * Rollback courses, revert the migration config.
 */
function stanford_courses_importer_post_update_8001() {
  $migrations = hs_field_helpers_migration_list();
  /** @var \Drupal\migrate_plus\Entity\Migration $course_migration */
  $course_migration = $migrations['su_course_tags']['su_course_tags'];
  $log = new MigrateMessage();
  $executable = new MigrateExecutable($course_migration, $log);
  if (\Drupal::database()->schema()->tableExists('migrate_map_su_course_tags')) {
    $executable->rollback();
  }

  // Delete all machine readable.
  $terms = \Drupal::entityTypeManager()
    ->getStorage('taxonomy_term')
    ->loadTree('su_course_tags', 0, NULL, TRUE);
  /** @var \Drupal\taxonomy\Entity\Term $term */
  foreach ($terms as $term) {
    if (strpos($term->label(), '::') !== FALSE) {
      $term->delete();
    }
  }
}

/**
 * Drop the migrate table for courses.
 */
function stanford_courses_importer_post_update_8002() {
  $source = new FileStorage('../config/default');
  /** @var \Drupal\Core\Config\CachedStorage $config_storage */
  $config_storage = \Drupal::service('config.storage');
  $config_storage->write('migrate_plus.migration.su_course_tags', $source->read('migrate_plus.migration.su_course_tags'));

  // I added the course id & course code to source.ids. Anytime the ids are
  // added/deleted the table must be deleted so that it can be rebuilt with the
  // additional columns on the next import.
  \Drupal::database()->schema()->dropTable('migrate_map_su_course_tags');
  drupal_flush_all_caches();
}

/**
 * Import courses with new mapping.
 */
function stanford_courses_importer_post_update_8003() {
  $migrations = hs_field_helpers_migration_list();
  /** @var \Drupal\migrate_plus\Entity\Migration $course_migration */
  $course_migration = $migrations['su_course_tags']['su_course_tags'];
  $log = new MigrateMessage();
  $executable = new MigrateExecutable($course_migration, $log);
  $executable->import();
}
