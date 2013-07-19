
<h3>SOColissimo</h3>

<table>

  <tr><th>key</th><th>value</th></tr>


<?php foreach($element['#details'] as $key => $value ) : ?>

  <tr><td><?php print $key; ?></td><td><?php print $value; ?></td>

<?php endforeach; ?>

</table>