<?php

/**
 * @file
 *   Checkout pane hooks
 */


function commerce_socolissimo_pane_checkout_form($form, &$form_state, $checkout_pane, $order) {

  $pane_form = array();

  $line_item = commerce_socolissimo_get_shipping_line_item($order);

  if( $line_item->data['shipping_service']['shipping_method'] == 'socolissimo' ){

    $pane_form['iframe'] = array(
      '#markup' => '<iframe src="'.url('socolissimo/frame/'.$order->order_number).'" height="1100px" width="100%"></iframe>',
    );

  }

  return $pane_form;



}

/**
 * Checkout pane callback: show the selected shipping service on the review pane.
 */
function commerce_socolissimo_pane_review($form, $form_state, $checkout_pane, $order) {

  $line_item = commerce_socolissimo_get_shipping_line_item($order);



  if( $line_item ){

    $info = array(
      '#theme' => 'commerce_socolissimo_info',
      '#details' => $line_item->data['service_details'],
    );

    return drupal_render($info);
  }


}

