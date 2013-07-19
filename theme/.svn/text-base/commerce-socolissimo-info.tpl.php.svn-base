<span>

<?php   $delivery_mode_details = array(
    'DOM' => 'Livraison à domicile',
    'RDV' => 'Livraison sur rendez-vous',
    'BPR' => 'Retrait en bureau de Poste',
    'A2P' => 'Retrait en point PickUp',
    'MRL' => 'Retrait en point Mondial Relay',
    'CIT' => 'Retrait en consigne Cityssimo',
    'ACP' => 'Retrait en Agence Colis',
    'CDI' => 'Retrait en Centre Courrier',
  );
?>
<strong>
<?php print $delivery_mode_details[$element['#details']['DELIVERYMODE']]; ?>
</strong>
<br/>
<?php print implode(' ', array(
  $element['#details']['CEFIRSTNAME'],
  $element['#details']['CENAME'],
)); ?>
</span>
<?php switch($element['#details']['DELIVERYMODE']) : ?>
<?php case 'DOM': ?>
    <?php $lines = array('CECOMPANYNAME','CEADRESS1','CEADRESS2','CEADRESS3','CEADRESS4'); ?>
<?php break;?>
<?php case 'BPR': ?>
    <?php $lines = array('PRNAME','PRCOMPLADRESS','PRADRESS1','PRADRESS2','PRTOWN','PRZIPCODE'); ?>
<?php break;?>
<?php endswitch;?>

<?php foreach( $lines as $line):?>
<?php if( !empty($element['#details'][$line])): ?>
<br/><span><?php print $element['#details'][$line]; ?></span>
<?php endif; ?>
<?php endforeach; ?>
<br/><span>
<?php print implode(' ', array(
  $element['#details']['CEZIPCODE'],
  $element['#details']['CETOWN'],
)); ?>
</span>


