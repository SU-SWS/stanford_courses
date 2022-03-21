<?php

namespace Drupal\Test\stanford_courses_importer\Unit\Entity;

use Drupal\stanford_courses_importer\Entity\CourseTag;
use Drupal\Tests\UnitTestCase;

/**
 * Class CoursesControllerTest.
 *
 * @covers \Drupal\stanford_courses_importer\Entity\CourseTag
 * @group stanford_courses_importer
 */
class CourseTagTest extends UnitTestCase {

  /**
   * Test the Course controller methods.
   */
  public function testCourseController() {
    $tag_string = $this->getRandomGenerator()->string();
    $tag = new CourseTag([
      'id' => $this->randomMachineName(),
      'label' => $this->randomMachineName(),
      'tag' => $tag_string,
    ], 'su_course_tag');
    $this->assertEquals($tag_string, $tag->tag());
  }

}
