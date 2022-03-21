<?php

namespace Drupal\stanford_courses_importer\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBase;

/**
 * Defines the Course Tag Translation entity.
 *
 * @ConfigEntityType(
 *   id = "su_course_tag",
 *   label = @Translation("Course Tag Translation"),
 *   handlers = {
 *     "view_builder" = "Drupal\Core\Entity\EntityViewBuilder",
 *     "list_builder" = "Drupal\stanford_courses_importer\CourseTagListBuilder",
 *     "form" = {
 *       "add" = "Drupal\stanford_courses_importer\Form\CourseTagForm",
 *       "edit" = "Drupal\stanford_courses_importer\Form\CourseTagForm",
 *       "delete" = "Drupal\stanford_courses_importer\Form\CourseTagDeleteForm"
 *     },
 *     "route_provider" = {
 *       "html" = "Drupal\stanford_courses_importer\CourseTagHtmlRouteProvider",
 *     },
 *   },
 *   config_prefix = "su_course_tag",
 *   admin_permission = "administer site configuration",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "canonical" = "/admin/structure/migrate/su_course_tag/{su_course_tag}",
 *     "add-form" = "/admin/structure/migrate/su_course_tag/add",
 *     "edit-form" = "/admin/structure/migrate/su_course_tag/{su_course_tag}/edit",
 *     "delete-form" = "/admin/structure/migrate/su_course_tag/{su_course_tag}/delete",
 *     "collection" = "/admin/structure/migrate/su_course_tag"
 *   },
 *   config_export = {
 *     "id",
 *     "label",
 *     "tag"
 *   }
 * )
 */
class CourseTag extends ConfigEntityBase implements CourseTagInterface {

  /**
   * The Course Tag Translation ID.
   *
   * @var string
   */
  protected $id;

  /**
   * The course tag from explorecourses.stanford.edu.
   *
   * @var string
   */
  protected $label;

  /**
   * The translated text.
   *
   * @var string
   */
  protected $tag;

  /**
   * {@inheritdoc}
   */
  public function tag() {
    return $this->tag;
  }

}
