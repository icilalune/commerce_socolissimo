<?php

/**
 * @file
 * Module administration UI
 */

/**
 * Form callback for managing SOColissimo account settings.
 */
function commerce_socolissimo_service_edit_page($form, &$form_state, $name){

  $form['socolissimo_'.$name.'_key'] = array(
    '#title' => 'Encryption Key',
    '#type' => 'textfield',
    '#default_value' => variable_get('socolissimo_'.$name.'_key'),
  );

  $form['socolissimo_'.$name.'_id'] = array(
    '#title' => 'Identifier',
    '#type' => 'textfield',
    '#default_value' => variable_get('socolissimo_'.$name.'_id'),
  );

  $form['#submit'][] = 'commerce_socolissimo_service_edit_page_submit';

  return system_settings_form($form);

}

/**
 * Implements hook_submit().
 */
function commerce_socolissimo_service_edit_page_submit(&$form, &$form_state){
  $form_state['redirect'] = 'admin/commerce/config/shipping/services/socolissimo';
}