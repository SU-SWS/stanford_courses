<?php

namespace Drupal\Tests\stanford_courses_importer\Kernel\Form;

use Drupal\Core\Form\FormState;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\stanford_courses_importer\Entity\CourseTag;
use Drupal\Tests\stanford_courses_importer\Kernel\HsCoursesImporterTestBase;

/**
 * Class HsCoursesImporterFormTest.
 *
 * @covers \Drupal\stanford_courses_importer\Form\CourseTagForm
 * @group stanford_courses_importer
 */
class CourseTagFormTest extends HsCoursesImporterTestBase {

  /**
   * Test the form class and its methods.
   */
  public function testForm() {
    $name = strtolower($this->randomMachineName());
    $tag_value = $this->randomString();
    $tag = $this->entityTypeManager->createInstance('su_course_tag', ['enforceIsNew' => TRUE]);

    /** @var \Drupal\stanford_courses_importer\Form\CourseTagForm $form_object */
    $form_object = $this->entityTypeManager->getFormObject('su_course_tag', 'add');
    $form = [];
    $form_state = new FormState();
    $form_object->setEntity($tag);
    $form = $form_object->form($form, $form_state);

    $this->assertArrayHasKey('label', $form);
    $this->assertArrayHasKey('id', $form);
    $this->assertArrayHasKey('tag', $form);

    $form_state->setValues([
      'label' => $name,
      'id' => $name,
      'tag' => $tag_value,
    ]);

    $form_object->submitForm($form, $form_state);
    $form_object->save($form, $form_state);

    $this->assertEquals($tag_value, $this->config('stanford_courses_importer.su_course_tag.' . $name)
      ->get('tag'));
    $messages = \Drupal::messenger()
      ->messagesByType(MessengerInterface::TYPE_STATUS);
    $this->assertStringContainsString('Created the', (string) $messages[0]);
    \Drupal::messenger()->deleteAll();

    $form_object->setEntity($this->courseTag);
    $form_object->save($form, $form_state);

    $messages = \Drupal::messenger()
      ->messagesByType(MessengerInterface::TYPE_STATUS);
    $this->assertStringContainsString('Saved the', (string) $messages[0]);
  }

}