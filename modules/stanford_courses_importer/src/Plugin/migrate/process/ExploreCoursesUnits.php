<?php

namespace Drupal\stanford_courses_importer\Plugin\migrate\process;

use Drupal\migrate\ProcessPluginBase;
use Drupal\migrate\MigrateExecutableInterface;
use Drupal\migrate\Row;

/**
 * Provides a 'ExploreCoursesUnits' migrate process plugin.
 *
 * @MigrateProcessPlugin(
 *  id = "explore_courses_units"
 * )
 */
class ExploreCoursesUnits extends ProcessPluginBase {

  /**
   * {@inheritdoc}
   */
  public function transform($value, MigrateExecutableInterface $migrate_executable, Row $row, $destination_property) {
    // input should be a concatenated string of two numbers with a dash
    if (!is_string($value) || !str_contains($value, '-')) {
      return '';
    }
    // check to see if the minimum number of units is different from the maximum number of units

    $units_array = explode('-', $value);
    if (count($units_array) != 2) {
      throw new \Exception('The number of minimum or maximum units is missing.');
    }

    if ((int)$units_array[0] != (int)$units_array[1]) {
      // The min and max differ.
      return $value;
    }
    // The min and max are equal, so just return one of them.
    return $units_array[0];
  }

}