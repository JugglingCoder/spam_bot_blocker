<?php
/**
 * @file
 * Spam Bot Blocker Fail Page
 */
function spam_bot_blocker_fail_page() {
global $base_path;
$html = '';

// ===== START Capture IP ==============
if (isset($_SERVER["REMOTE_ADDR"])) {
  $ip = $_SERVER["REMOTE_ADDR"];
}
elseif ( isset($_SERVER["HTTP_X_FORWARDED_FOR"])) {
  $ip = $_SERVER["HTTP_X_FORWARDED_FOR"];
}
elseif ( isset($_SERVER["HTTP_CLIENT_IP"])) {
  $ip = $_SERVER["HTTP_CLIENT_IP"];
}
else{
  $ip = '';
}
// ===== END Capture IP =================

// ===== START Check the sbbdeny table
$q = "";
$q .= "SELECT i.ip AS bs_ip, i.timestamp AS bs_timestamp FROM {sbbdeny} i ";
$q .= "WHERE :ip = i.ip";
$result = db_query($q, array(':ip' => $ip));
// D7
// $spam_bot_blocker_purge_deny = variable_get('spam_bot_blocker_purge_deny', '');
// Actually... don't need the whole object here... just get 1 variable
$spam_bot_blocker_purge_deny = config_get('spam_bot_blocker.settings','purge_deny');
$spam_bot_blocker_purge_deny = time() - $spam_bot_blocker_purge_deny;
foreach ($result as $row) {
  $seconds_remaining = $row->bs_timestamp - $spam_bot_blocker_purge_deny;
} // End foreach

ob_start();
?>
<p>You have failed the CAPTCHA more times than this site Administrator allows.</p>
<?php if ($seconds_remaining > 60) { ?>
<p>You must wait "<b><?php echo spam_bot_blocker_seconds_to_time($seconds_remaining); ?></b>" before you can try submitting the form again.</p>
<?php
}
elseif ($seconds_remaining < 60 && $seconds_remaining > 0) {
?>
<p>You must wait less than a minute before you can try submitting the form again.</p>
<?php
}
else{
?>
<p>You may try submitting the form again. Please take care in answering the CAPTCHA correctly.</p>
<?php } ?>
<p><a href="<?php echo $base_path; ?>">Return Home</a></p>
<?php
$html .= ob_get_clean();
return $html;
}