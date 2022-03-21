<?php

namespace Drupal\stanford_courses_importer\Form;

use Drupal\Core\Entity\EntityForm;
use Drupal\Core\Form\FormStateInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Database\Connection;

/**
 * Class CourseTagForm.
 */
class CourseTagForm extends EntityForm {

  /**
   * Database connection service.
   *
   * @var \Drupal\Core\Database\Connection
   */
  protected $database;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('database')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function __construct(Connection $database) {
    $this->database = $database;
  }

  /**
   * {@inheritdoc}
   */
  public function form(array $form, FormStateInterface $form_state) {
    $form = parent::form($form, $form_state);

    /** @var \Drupal\stanford_courses_importer\Entity\CourseTagInterface $su_course_tag */
    $su_course_tag = $this->entity;
    $form['label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Explore Courses Tag'),
      '#maxlength' => 255,
      '#default_value' => $su_course_tag->label(),
      '#description' => $this->t("Machine tag name from explorecourses.stanford.edu."),
      '#required' => TRUE,
    ];

    $form['id'] = [
      '#type' => 'machine_name',
      '#default_value' => $su_course_tag->id(),
      '#machine_name' => [
        'exists' => '\Drupal\stanford_courses_importer\Entity\CourseTag::load',
      ],
      '#disabled' => !$su_course_tag->isNew(),
    ];

    $form['tag'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Translated Tag'),
      '#default_value' => $su_course_tag->tag(),
      '#required' => TRUE,
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $su_course_tag = $this->entity;
    $status = $su_course_tag->save();
    $this->invalidateHashes();

    switch ($status) {
      case SAVED_NEW:
        $this->messenger()->addMessage($this->t('Created the %label Course Tag Translation.', [
          '%label' => $su_course_tag->label(),
        ]));
        break;

      default:
        $this->messenger()->addMessage($this->t('Saved the %label Course Tag Translation.', [
          '%label' => $su_course_tag->label(),
        ]));
    }
    $form_state->setRedirectUrl($su_course_tag->toUrl('collection'));
  }

  /**
   * Invalidates migration hashes.
   */
  protected function invalidateHashes() {
    if ($this->database->schema()->tableExists('migrate_map_su_course_tags')) {
      $this->database->update('migrate_map_su_course_tags')
        ->fields(['hash' => ''])
        ->execute();
    }
  }

}