<?php

/**
 * @file
 * Session expire configuration.
 */

function session_expire_settings() {
  // We want a count
  $session_count = db_select('sessions')
      ->countQuery()
      ->execute()
      ->fetchField();

  $form['session_expire_desc'] = array(
    '#markup' => t('This module requires cron to be correctly configured and running for Backdrop. You currently have @count rows in your sessions table.', array('@count' => $session_count)),
  );

  $period = backdrop_map_assoc(array(60, 300, 900, 1800, 3600, 7200, 10800, 21600, 43200, 86400, 172800, 259200, 604800, 1209600, 2419200), 'format_interval');
  $period['1000000000'] = t('Never');

  $form['session_expire_age'] = array(
    '#type' => 'select',
    '#title' => t('Age'),
    '#default_value' => config_get('session_expire.settings', 'session_expire_age'),
    '#options' => $period,
    '#description' => t('Delete sessions that have been idle for longer than the specified age.')
  );

  $form['#submit'][] = 'session_expire_settings_submit';

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for session expire configuration form.
 */
function session_expire_settings_submit($form, &$form_state) {
  config('session_expire.settings')
    ->set('session_expire_age', $form_state['values']['session_expire_age'])
    ->save();

  watchdog('session_expire', 'Session expire settings modified.', array(), WATCHDOG_INFO);
}
