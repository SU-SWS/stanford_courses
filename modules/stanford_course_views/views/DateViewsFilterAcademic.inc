<?php
/**
 * @file
 * Academic date filter handler.
 */

/**
 * Class DateViewsFilterAcademic.
 */
class DateViewsFilterAcademic extends date_views_filter_handler_simple {

  /**
   * {@inheritdoc}
   */
  public function extra_options_submit($form, &$form_state) {
    unset($form_state['view']->stack);
    parent::extra_options_submit($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['exception'] = array(
      'contains' => array(
        'from' => array(
          'contains' => array(
            'month' => array('default' => 1),
            'day' => array('default' => 1),
          ),
        ),
        'to' => array(
          'contains' => array(
            'month' => array('default' => 1),
            'day' => array('default' => 1),
          ),
        ),
        'value' => array('default' => ''),
      ),
    );
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function operators() {
    $ops = parent::operators();
    unset($ops['between']);
    unset($ops['not between']);
    unset($ops['regular_expression']);
    return $ops;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['operator']['#type'] = 'select';
    $cal = cal_info(0);
    $days = range(0, 31);

    unset($days[key($days)]);
    unset($form['value']['min_group']);
    unset($form['value']['max_group']);
    $form['value']['min_group']['min']['#type'] = 'hidden';
    $form['value']['max_group']['max']['#type'] = 'hidden';
    unset($form['value']['value_group']['value']);
    $form['value']['value_group']['value_choose_input_type']['#type'] = 'hidden';
    $form['value']['value_group']['value_choose_input_type']['#value'] = 'relative';

    $form['exception'] = array(
      '#type' => 'fieldset',
      '#title' => t('Exception'),
    );

    $form['exception']['from'] = array(
      '#type' => 'fieldset',
      '#title' => t('From'),
      '#attributes' => array(
        'class' => array('views-left-50', 'clearfix'),
      ),
    );
    $form['exception']['from']['month'] = array(
      '#type' => 'select',
      '#title' => t('Month'),
      '#options' => $cal['months'],
      '#default_value' => $this->options['exception']['from']['month'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );
    $form['exception']['from']['day'] = array(
      '#type' => 'select',
      '#title' => t('Day'),
      '#options' => $days,
      '#default_value' => $this->options['exception']['from']['day'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );


    $form['exception']['to'] = array(
      '#type' => 'fieldset',
      '#title' => t('To'),
      '#attributes' => array(
        'class' => array('views-left-50', 'clearfix'),
      ),
    );
    $form['exception']['to']['month'] = array(
      '#type' => 'select',
      '#title' => t('Month'),
      '#options' => $cal['months'],
      '#default_value' => $this->options['exception']['to']['month'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );
    $form['exception']['to']['day'] = array(
      '#type' => 'select',
      '#title' => t('Day'),
      '#options' => $days,
      '#default_value' => $this->options['exception']['to']['day'],
      '#prefix' => '<div class="views-left-50">',
      '#suffix' => '</div>',
    );

    $form['exception']['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Relative Date during exception'),
      '#default_value' => $this->options['exception']['value'],
    );
  }

  /**
   * {@inheritdoc}
   */
  public function op_simple($field) {
    $this->exception();
    parent::op_simple($field);
  }

  /**
   * Helper function to determine if the current date is within the exception.
   *
   * @return bool
   *   Not in exception timeframe.
   */
  private function exception() {
    $exception = $this->options['exception'];
    if (!$exception['value'] || !$this->parseDate($exception['value'])) {
      return FALSE;
    }
    $from = $exception['from']['month'] . '/' . $exception['from']['day'];
    $to = $exception['to']['month'] . '/' . $exception['to']['day'];
    $current_date = date('n/j');


    if ($this->parseDate($to) - $this->parseDate($from) < 0) {
      // Spans over January 1st.
      $to += 60 * 60 * 24 * 365;
    }

    if ($this->parseDate($current_date) <= $this->parseDate($to) && $this->parseDate($current_date) >= $this->parseDate($from)) {
      $this->options['default_date'] = $exception['value'];
    }
  }

  /**
   * Helper function to attempt to parse a string as a date.
   *
   * @param string $date
   *   Date string.
   *
   * @return int
   *   Timestamp of the given date. 0 if it is unable to parse.
   */
  private function parseDate($date) {
    try {
      $d = new DateTime($date);
      return $d->getTimestamp();
    }
    catch (Exception $e) {
      return 0;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function can_expose() {
    return FALSE;
  }

}
