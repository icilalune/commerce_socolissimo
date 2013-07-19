<?php

/**
 * @file
 * SOColissimo API base functions
 */

/**
 * Compute the message SHA-1 signature
 *
 * @see commerce_socolissimo_signature_out()
 * @see commerce_socolissimo_signature_in()
 *
 * @param array $params
 *   associative array of message values
 * @param string $sha_key
 *   hash salt
 * @param array $sign_keys
 *   keys of params array to include in signature calculation
 * @return string
 *   the message SHA-1 signature
 */
function commerce_socolissimo_signature($params, $sha_key, $sign_keys){
  foreach($params as $key => $value){
     $up_params[strtoupper($key)] = $value;
   }
   $params = $up_params;
   $components = array();

   foreach($sign_keys as $key){
     $key = strtoupper($key);
     if(array_key_exists($key,$up_params)){
         if( !empty($up_params[$key]) || $up_params[$key] === 0 ){
           $components[] = $up_params[$key];
         }
     }
   }
   $components[] = $sha_key;
   return sha1(implode('', $components));
}

/**
 * Compute the message SHA-1 for outgoing requests
 *
 * @param array $params
 *   associative array of message values
 * @param string $sha_key
 *   hash salt
 * @return string
 *   the message SHA-1 signature
 */
function commerce_socolissimo_signature_out($params, $sha_key) {
  return commerce_socolissimo_signature($params, $sha_key,
    array('pudoFOId', 'ceName', 'dyPreparationTime', 'dyForwardingCharges',
      'trClientNumber', 'trOrderNumber', 'orderId', 'numVersion', 'ceCivility',
      'ceFirstName', 'ceCompanyName', 'ceAdress1', 'ceAdress2', 'ceAdress3',
      'ceAdress4', 'ceZipCode', 'ceTown', 'ceEntryPhone', 'ceDeliveryInformation',
      'ceEmail', 'cePhoneNumber', 'ceDoorCode1', 'ceDoorCode2', 'dyWeight',
      'trFirstOrder', 'trParamPlus', 'trReturnUrlKo', 'trReturnUrlOk',
    )
  );
}

/**
 * Compute the message SHA-1 for incoming returns
 *
 * @param array $params
 *   associative array of message values
 * @param string $sha_key
 *   hash salt
 * @return string
 *   the message SHA-1 signature
 */
function commerce_socolissimo_signature_in($params, $sha_key) {
  return commerce_socolissimo_signature($params, $sha_key,
    array('PUDOFOID', 'CENAME', 'DYPREPARATIONTIME', 'DYFORWARDINGCHARGES',
      'TRCLIENTNUMBER', 'TRORDERNUMBER', 'ORDERID', 'CECIVILITY', 'CEFIRSTNAME',
      'CECOMPANYNAME', 'CEADRESS1', 'CEADRESS2', 'CEADRESS3', 'CEADRESS4',
      'CEZIPCODE', 'CETOWN', 'DELIVERYMODE', 'CEDELIVERYINFORMATION', 'CEEMAIL',
      'CEPHONENUMBER', 'CEDOORCODE1', 'CEDOORCODE2', 'CEENTRYPHONE',
      'TRPARAMPLUS', 'TRADERCOMPANYNAME', 'ERRORCODE', 'ERR_CENAME',
      'ERR_CEFIRSTNAME', 'ERR_CECOMPANYNAME', 'ERR_CEADRESS1', 'ERR_CEADRESS2',
      'ERR_CEADRESS3', 'ERR_CEADRESS4', 'ERR_CETOWN', 'ERR_CEDOORCODE1',
      'ERR_CEDOORCODE2', 'ERR_CEENTRYPHONE', 'ERR_CEDELIVERYINFORMATION',
      'ERR_CEEMAIL', 'ERR_CEPHONENUMBER', 'ERR_TRCLIENTNUMBER',
      'ERR_TRORDERNUMBER', 'ERR_TRPARAMPLUS', 'ERR_CECIVILITY', 'ERR_DYWEIGHT',
      'ERR_DYPREPARATIONTIME', 'TRRETURNURLKO',
    )
  );
}

