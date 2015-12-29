<?php
/**
 * @file
 * Spam Bot Blocker Banned IP Page
 */
function spam_bot_blocker_banned_ips($form, &$form_state) {

global $base_path;
$html = '';

$ban_count = config_get('spam_bot_blocker.settings','max_fails_ban');

$q = "";
$q .= "SELECT i.ip AS bsip FROM {sbbban} i ";
$q .= "WHERE i.count >= " . $ban_count . "";
$result = db_query($q);
$count = $result->rowCount();
 
if($result) {
  if ($count > 0) {
  $array_ip = array();
    foreach ($result as $row) {
      $array_ip[$row->bsip] = $row->bsip;
    }
    ob_start();
    ?>
    <p>You can "<i>Investigate</i>" and get the "Location" of an IP by using one of these services if you like:</p>
    <ul>
      <li><a href="http://www.iplocation.net/" target="_blank">iplocation.net</a></li>
      <li><a href="http://www.ip2location.com/" target="_blank">ip2location.com</a></li>
      <li>... and many more.  Just do a search for "ip to location"</li>
    </ul>
    
    <?php
    $html = ob_get_clean();    

  $form['spam_bot_blocker_markup_1'] = array(
    '#title' => t('Instructions'),
    '#markup' => $html,
    '#weight' => 1,
  );
    
  $form['ips'] = array(
    '#title' => t('IP\'s Banned from submitting forms on this site'),
    '#description' => t('Check the IP\'s you would like to delete then click the "Delete" button below.'),
    '#type' => 'checkboxes',
    '#options' => $array_ip,
    '#weight' => 2,
  );  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#weight' => 15,
  );
  

    
  return $form;      

  }
  else{ // End if count greater than 0
    ob_start();
    ?>
    <p>No "Banned" IP's in the database</p>
    <?php
    $html = ob_get_clean();

    $form['spam_bot_blocker_markup_1'] = array(
      '#title' => t('Instructions'),
      '#markup' => $html,
      '#weight' => 1,
    );
    return $form;
  }
}
else{
  echo '<pclass="center">No DB "result"</p>';
}
}

//function spam_bot_blocker_banned_ips_validate($form, &$form_state) {
//}

function spam_bot_blocker_banned_ips_submit($form, &$form_state) {
$a = $form_state["values"]["ips"];
$array_delete = array();
foreach ($a as $b) {
  if ($b) {
    $array_delete[] = $b;
  }
}

foreach ($array_delete as $b) {
  // Delete all of same ip from fail table
  db_delete('sbbban')
  ->condition('ip', $b)
  ->execute();
}
//die();
backdrop_set_message('IP\'s removed from Spam Bot Blocker Banned Database');
backdrop_goto('admin/config/people/captcha/spam_bot_blocker/banned_ips');
}