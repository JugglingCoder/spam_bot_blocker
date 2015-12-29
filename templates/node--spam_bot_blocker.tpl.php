<?php
// Simple "Node Access" without other modules... you can remove this if you like
if($node->type == 'spam_bot_blocker'){
  if($user->uid == 1){
    $access = true;
  }else{
    $access = false;
  }
}
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print implode(' ', $classes); ?> clearfix"<?php print backdrop_attributes($attributes); ?>>
  <div class="node-inner">
    <div class="spam_bot_wrap">
<?php
if($access){
if (
$view_mode == 'full' ||
$view_mode == 'print'
) {
$bs_image = $node->field_sbb_image['und']['0']['uri'];
// D7 Method
//$bs_image = theme('image_style', array('style_name' => 'spam_bot_blocker_image', 'path' => $bs_image, 'getsize' => FALSE, 'attributes' => array('class' => '','style' => 'max-width:100%;')));
$bs_image = theme('image_style', array('style_name' => 'spam_bot_blocker_image', 'uri' => $bs_image, 'alt' => 'Challenge Image', 'title' => 'Challenge Image', 'attributes' => array('class' => '','style' => 'max-width:100%;')));
?>

<div id="sbb_wrapper">
	<div id="sbb_html_col2">
		<p class="sbb_col_header_p sbb_center"><span class="sbb_col_header sbb_center">Question Image</span></p>
		<?php echo $bs_image; ?>
	</div>
	<div id="sbb_html_col3">
      <h4>Question</h4>
      <p><?php echo $node->field_sbb_question['und']['0']['value']; ?></p>
      <h4>Possible Answers</h4>
      <p><?php echo $node->field_sbb_possible_answers['und']['0']['value']; ?></p>
      <h4>Correct Answer</h4>
      <p><?php echo $node->field_sbb_correct_answer['und']['0']['value']; ?></p>
	</div>
	<div style="clear:both;"></div>
</div>
<?php
}
}
else{
  echo '<p>Sorry, no content on this page</p>';
}
?>
    </div><!-- bs_generic_wrapper -->
	</div> <!-- /node-inner -->
</div> <!-- /node-->