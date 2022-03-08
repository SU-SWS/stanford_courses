<?php

namespace Drupal\Test\stanford_courses_importer\Kernel;

use Drupal\KernelTests\Core\Entity\EntityKernelTestBase;

/**
 * Class CourseTagListBuilderTest.
 *
 * @covers \Drupal\stanford_courses_importer\CourseTagListBuilder
 * @group stanford_courses_importer
 */
class CourseTagListBuilderTest extends EntityKernelTestBase {

  /**
   * Tag List builder object.
   *
   * @var \Drupal\stanford_courses_importer\CourseTagListBuilder
   */
  protected $listBuilder;

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = ['system', 'stanford_courses_importer'];

  /**
   * {@inheritdoc}
   */
  protected function setUp(): void {
    parent::setUp();
    $this->listBuilder = $this->entityTypeManager->getListBuilder('hs_course_tag');
  }

  /**
   * Test the list builder header and row builder.
   */
  public function testListBuilder() {
    $header = $this->listBuilder->buildHeader();
    $this->assertArrayHasKey('label', $header);
    $this->assertArrayHasKey('id', $header);
    $entity = $this->entityTypeManager->createInstance('hs_course_tag', [
      'id' => $this->randomMachineName(),
      'label' => $this->randomString(),
      'tag' => $this->randomString(),
    ]);
    $entity->save();

    $row = $this->listBuilder->buildRow($entity);
    $this->assertArrayHasKey('label', $row);
    $this->assertArrayHasKey('id', $row);
  }

}
