<?php

namespace Drupal\Tests\stanford_courses_importer\Kernel;

use Drupal\KernelTests\Core\Entity\EntityKernelTestBase;

/**
 * Class HsCoursesImporterTestBase.
 *
 * @group stanford_courses_importer
 */
abstract class HsCoursesImporterTestBase extends EntityKernelTestBase {

  /**
   * Course tag entity.
   *
   * @var \Drupal\stanford_courses_importer\Entity\CourseTag
   */
  protected $courseTag;

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = [
    'system',
    'stanford_courses_importer',
  ];

  /**
   * {@inheritdoc}
   */
  protected function setUp(): void {
    parent::setUp();
    $name = $this->randomMachineName();
    $this->courseTag = $this->entityTypeManager->createInstance('su_course_tag', [
      'id' => strtolower($name),
      'label' => $name,
      'tag' => $this->randomString(),
    ]);
    $this->courseTag->save();

    $table_definition = [
      'description' => 'Test table',
      'fields' => [
        'source_ids_hash' => [
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'default' => '',
        ],
        'sourceid1' => [
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'default' => '',
        ],
        'hash' => [
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'default' => '',
        ],
      ],
    ];
    \Drupal::database()
      ->schema()
      ->createTable('migrate_map_su_course_tags', $table_definition);
  }

}