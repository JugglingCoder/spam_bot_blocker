<?php
/**
 * @file
 * Spam Bot Blocker Admin Page
 */

function spam_bot_blocker_admin_settings() {
global $base_path;
$form = array();
$html = '';
ob_start();
?>
<p>"<b>Spam Bot Blocker</b>" General settings.</p>
<p>This information can be seen anytime by accessing the "<a href="<?php echo $base_path; ?>admin/config/people/captcha/spam_bot_blocker">Configuration > People > CAPTCHA > Spam Bot Blocker</a>" menu item. Be sure to read the "<a href="<?php echo $base_path; ?>admin/config/people/captcha/spam_bot_blocker/help">Help Tab</a>" for lots of good help on how to use this module</p>
</ul>
<?php
$html = ob_get_clean();

// Instead of:
// '#default_value' => config_get('spam_bot_blocker.settings','fails'),
// Grab all the config variables from the file at once
$config = config('spam_bot_blocker.settings');

$bs_field = 'spam_bot_blocker_markup_1';
$form[$bs_field] = array(
  '#title' => t('Instructions'),
  '#markup' => $html,
  '#weight' => 1,
);

$form['spam_bot_blocker_fails'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => '1 time',
  2 => '2 times',
  3 => '3 times',
  4 => '4 times',
  5 => '5 times',
  ),
  '#title' => t('Maximum Fails Allowed'),
  '#description' => t('This is the amount of times the user (IP address) is allowed to "Fail" the CAPTCHA before being "Denied" usage of the form.'),
  '#default_value' => $config->get('fails'),
  '#weight' => 6
);

$form['spam_bot_blocker_purge_deny'] = array(
  '#type' => 'select',
  '#options' => array(
  90 => '1 minute',
  300 => '5 minutes',
  1800 => '30 minutes',
  3600 => '1 hour',
  10800 => '3 hours',
  86400 => '1 Day',
  604800 => '1 Week',
  2592000 => '1 Month',
  ),
  '#title' => t('Denied Wait Time'),
  '#description' => t('If the CAPTCHA is failed the amount of times set above in the "Maximum Fails Allowed " field, this is the "Amount of Time" that user (IP address) will be blocked from any forms with the Spam Bot Blocker CAPTCHA attached.'),
  '#default_value' => $config->get('purge_deny'),
  '#weight' => 7
);

$form['spam_bot_blocker_redirect_type'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => 'Standard',
  2 => 'Own URL',
  ),
  '#title' => t('Denied Re-Direct Type'),
  '#description' => t('If a user (IP address) exceeds the "Maximum Fails Allowed", this is the URL to where that user (IP address) is Re-Directed.<br>"Standard" - Re-Directs to a page that tells them they have been denied access to the form and lets them know how long they have to wait (you can view it here <a href="' . $base_path . 'spam_bot_blocker/fail">Blocked Page</a> <b>Note:</b> this page does use a DB call with data from the blocked user so viewing it without data will show a "PHP time() notice" and will not be able to see "how long" they have to wait).<br>"Own URL" - You enter your own Re-Direct URL in the "Deny Re-Direct URL" field below.'),
  '#default_value' => $config->get('redirect_type'),
  '#weight' => 8
);

$form['spam_bot_blocker_redirect'] = array(
  '#type' => 'textfield',
  '#title' => t('Denied Re-Direct URL'),
  '#description' => t('if "Own URL" in the field "Deny Re-Direct Type" above, the URL the user (IP address) is redirected to (FULL PATH).'),
  '#default_value' => $config->get('redirect'),
  '#weight' => 9
);

$form['spam_bot_blocker_use_honey'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => 'Yes',
  2 => 'No',
  ),
  '#title' => t('Use integrated "HoneyPot"'),
  '#description' => t('Do you want to use the integrated "HoneyPot"?'),
  '#default_value' => $config->get('use_honey'),
  '#weight' => 10
);

$form['spam_bot_blocker_honey_name'] = array(
  '#type' => 'textfield',
  '#title' => t('"HoneyPot" Field Name'),
  '#description' => t('Type a field "Name" for the "HoneyPot" field. 1 word, no spaces, alpha-numeric characters ONLY. Don\'t use a same name as one of your form fields!!'),
  '#default_value' => $config->get('honey_name'),
  '#weight' => 11
);

$bs_field = 'spam_bot_blocker_markup_2';
$form[$bs_field] = array(
  '#title' => t('Permanent Ban Feature'),
  '#markup' => '<hr /><h4>The settings below allow you to permanently ban IP\'s.</h4><p>Note that by using the "Banned IP\'s" tab, you can also "un-ban" these permanently banned IP\'s if you like.</p>',
  '#weight' => 12,
);

$form['spam_bot_blocker_use_ban'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => 'Yes',
  2 => 'No',
  ),
  '#title' => t('Use the "Permanent Ban" feature?'),
  '#description' => t('If you select "Yes", users (IP addresses) where the count is equal to or greater than the "Maximum "Denied" count before Ban" set below will be permanently banned from filling out ANY forms that have the Spam Bot Blocker attached to them.'),
  '#default_value' => $config->get('use_ban'),
  '#weight' => 13
);

$form['spam_bot_blocker_max_fails_ban'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => '1 times',
  2 => '2 times',
  3 => '3 times',
  4 => '4 times',
  5 => '5 times',
  ),
  '#title' => t('Maximum "Denied" count before Ban'),
  '#description' => t('This is the amount of times the user (IP address) is allowed to be "Denied" (see above) before being "Permanently Blocked" from usage of the form.'),
  '#default_value' => $config->get('max_fails_ban'),
  '#weight' => 14
);

$form['spam_bot_blocker_redirect_ban_type'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => 'Standard',
  2 => 'Own URL',
  3 => 'Random YouTube Video',
  ),
  '#title' => t('Permanent Ban Re-Direct Type'),
  '#description' => t('This is <b>ALSO</b> the Re-Direct URL for bots that have filled in the "Honeypot" field (if that feature is being used).<br>"Standard" - Just a generic page that says they have been permanently blocked (you can view it here <a href="' . $base_path . 'spam_bot_blocker/ban">Permanently Blocked Page</a>)<br>"Own URL" - You enter your own Re-Direct URL in the "Permanent Ban Re-Direct URL" field below.<br>"Random YouTube Video" - Re-Directs to a random YouTube Video.'),
  '#default_value' => $config->get('redirect_ban_type'),
  '#weight' => 15
);

$form['spam_bot_blocker_redirect_ban'] = array(
  '#type' => 'textfield',
  '#title' => t('Permanent Ban Re-Direct URL'),
  '#description' => t('If "Own URL" is selected above for "Permanent Ban Re-Direct Type" enter the FULL PATH in the field below.'),
  '#default_value' => $config->get('redirect_ban'),
  '#weight' => 16
);

$bs_field = 'spam_bot_blocker_markup_3';
$form[$bs_field] = array(
  '#title' => t('Development'),
  '#markup' => '<hr /><h4>Development Settings</h4>',
  '#weight' => 17,
);

$form['spam_bot_blocker_expose_errors'] = array(
  '#type' => 'select',
  '#options' => array(
  0 => 'No',
  1 => 'Yes',
  ),
  '#title' => t('Expose Errors'),
  '#description' => t('Expose additional errors that might be useful in debugging. You can turn this on and review your form (not logged in) for errors but when your done you should turn it off.'),
  '#default_value' => $config->get('expose_errors'),
  '#weight' => 18
);

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 19
	);
	
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save Configuration')
	);

// Backdrop Method
// return system_settings_form($form);
// BackDrop Method uses a "Submit Handler" > spam_bot_blocker_admin_settings_submit
return ($form);
} // ===== END Basic Settings ================

/**
 * ========== Submit Handler for "spam_bot_blocker_admin_settings"
 *
 *
 */
function spam_bot_blocker_admin_settings_submit($form, &$form_state){
	//debug($form_state['values']);
	
	$config = config('spam_bot_blocker.settings');
	$values = $form_state['values'];
	
	/*
	$config->set('spam_bot_blocker_fails',$values['spam_bot_blocker_fails']);
	$config->set('spam_bot_blocker_purge_deny',$values['spam_bot_blocker_purge_deny']);
	$config->set('spam_bot_blocker_redirect_type',$values['spam_bot_blocker_redirect_type']);
	$config->set('spam_bot_blocker_redirect',$values['spam_bot_blocker_redirect']);
	$config->set('spam_bot_blocker_use_honey',$values['spam_bot_blocker_use_honey']);
	$config->set('spam_bot_blocker_honey_name',$values['spam_bot_blocker_honey_name']);
	$config->set('spam_bot_blocker_use_ban',$values['spam_bot_blocker_use_ban']);
	$config->set('spam_bot_blocker_max_fails_ban',$values['spam_bot_blocker_max_fails_ban']);
	$config->set('spam_bot_blocker_redirect_ban_type',$values['spam_bot_blocker_redirect_ban_type']);
	$config->set('spam_bot_blocker_redirect_ban',$values['spam_bot_blocker_redirect_ban']);
	$config->set('spam_bot_blocker_expose_errors',$values['spam_bot_blocker_expose_errors']);
	*/
	
	$config->set('fails',(int)$values['spam_bot_blocker_fails']);
	$config->set('purge_deny',(int)$values['spam_bot_blocker_purge_deny']);
	$config->set('redirect_type',(int)$values['spam_bot_blocker_redirect_type']);
	$config->set('redirect',$values['spam_bot_blocker_redirect']);
	$config->set('use_honey',(int)$values['spam_bot_blocker_use_honey']);
	$config->set('honey_name',$values['spam_bot_blocker_honey_name']);
	$config->set('use_ban',(int)$values['spam_bot_blocker_use_ban']);
	$config->set('max_fails_ban',(int)$values['spam_bot_blocker_max_fails_ban']);
	$config->set('redirect_ban_type',(int)$values['spam_bot_blocker_redirect_ban_type']);
	$config->set('redirect_ban',$values['spam_bot_blocker_redirect_ban']);
	$config->set('expose_errors',(int)$values['spam_bot_blocker_expose_errors']);
	
	$config->save();
	
	backdrop_set_message(t('The configuration options have been saved.'));
	
}

/**
* CDN Settings
*
*
*
*/
function spam_bot_blocker_admin_cdn($form, $form_state) {

global $base_path;
$form = array();
$html = '';

// ===== START Grab Languages ============

$lang = spam_bot_blocker_get_language();
$lang = explode('|', $lang);
$array_lang = array();

foreach ($lang as $a) {
  $a = explode(',', $a);
  $tid = $a[0];
  $array_lang[$tid] = $a[1];
}
ob_start();
?>
<p>"<b>Spam Bot Blocker</b>" CDN settings.</p>
<p>You must have an account at <a href="http://www.spambotblocker.com" target="_blank">SpamBotBlocker.com</a> to use the CDN.</p>
<p>You must agree to our <a href="http://www.spambotblocker.com/page/terms-use-and-privacy-policy" target="_blank">Terms of Use</a> to use the CDN.</p>

<p></p>
</ul>
<?php
$html = ob_get_clean();

// Instead of:
// '#default_value' => config_get('spam_bot_blocker.settings','fails'),
// Grab all the config variables from the file at once
$config = config('spam_bot_blocker.settings');

$bs_field = 'spam_bot_blocker_markup_1';
$form[$bs_field] = array(
  '#title' => t('Instructions'),
  '#markup' => $html,
  '#weight' => 1,
);

$form['spam_bot_blocker_use_cdn'] = array(
  '#type' => 'select',
  '#options' => array(
  1 => 'Yes',
  2 => 'No',
  ),
  '#title' => t('Use CAPTCHA challenges from Spam Bot Blocker.com'),
  '#description' => t('You can either use "local" content (you create on this website), or CAPTCHA Challenges from Spam Bot Blocker.com'),
  '#default_value' => $config->get('use_cdn'),
  '#weight' => 2
);

$form['spam_bot_blocker_cnd_site_key'] = array(
  '#type' => 'textfield',
  '#title' => t('The "Site Key" for this Domain (if using the CDN above)'),
  '#description' => t('If you selected "Yes" above for the "Use CAPTCHA challenges from <a href="http://www.spambotblocker.com" target="_blank">SpamBotBlocker.com</a>" field, you MUST enter your "Site Key" for this domain here or the CDN will not be used and the system will fall back to "local" content. If you do not have a "Site Key" for this domain yet, please "Log In" (or create an account then "Log In") at <a href="http://www.spambotblocker.com" target="_blank">SpamBotBlocker.com</a> and create a key.'),
  '#default_value' => $config->get('cnd_site_key'),
  '#weight' => 3
);

// The "Language" number is the TID of
// the term on the CDN
$form['spam_bot_blocker_cdn_language'] = array(
  '#type' => 'select',
  '#options' => $array_lang,
  '#title' => t('"Language" of the CAPTCHA\'s from the CND you want to display'),
  '#description' => t('Select the "Language" your users will most likely be using to answer the CAPTCHA.  Note, if you select "Chinese" and visitors can\'t read Chinese... they will never be able to pass the CAPTCHA.'),
  '#default_value' => $config->get('cdn_language'),
  '#weight' => 4
);

	$form['actions'] = array(
		'#type' => 'action',
		'#weight' => 4
	);
	
	$form['actions']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save Configuration')
	);

// Backdrop Method
// return system_settings_form($form);
// BackDrop Method uses a "Submit Handler" > spam_bot_blocker_admin_settings_submit
return ($form);
} // ===== END Basic Settings ================

/**
 * ========== Submit Handler for "spam_bot_blocker_admin_cdn"
 *
 *
 */
function spam_bot_blocker_admin_cdn_submit($form, &$form_state){
	//debug($form_state['values']);
	
	$config = config('spam_bot_blocker.settings');
	$values = $form_state['values'];

	$config->set('use_cdn',(int)$values['spam_bot_blocker_use_cdn']);
	$config->set('cnd_site_key',$values['spam_bot_blocker_cnd_site_key']);
	$config->set('cdn_language',(int)$values['spam_bot_blocker_cdn_language']);
	
	$config->save();
	
	backdrop_set_message(t('The configuration options have been saved.'));
	
}