<?php
/**
 * @file
 * Spam Bot Blocker Help Page
 */

function spam_bot_blocker_help() {
global $base_path;

$html = '';
ob_start();
?>
<p>"<b>Spam Bot Blocker</b>" Help</p>
<p>This Help Page can be seen any time by accessing the "<a href="<?php echo $base_path; ?>admin/config/people/captcha/spam_bot_blocker/help">Configuration > People > CAPTCHA > Spam Bot Blocker > Help</a>" menu item</p>

<ul>
	<li>Although the "Spam Bot Blocker" CDN (see below) can be used exclusively for challenges, it is a good idea to create a couple of local (on this site) "Spam Bot Blocker" pieces of content (<a href="<?php echo $base_path; ?>node/add/spam-bot-blocker">add "Spam Bot Blocker" content</a>) for "fallback" (if the service is down).</li>
  <li><b>Local Content or CDN</b> - With this Module you have a choice of using "Local" content created by you as your CAPTCHA challenges OR the online <a href="http://www.spambotblocker.com/" target="_blank">SpamBotBlocker.com</a> CDN (Content Delivery Network) witch will automatically deliver a mass amount of CAPTCHA challenges created by the community.
    <ul>
      <li><b>Local Content</b> - You create your own CAPTCHA challenges for this website. <a href="<?php echo $base_path; ?>node/add/spam-bot-blocker">Add a "Spam Bot Blocker" piece of content</a>.</li>
      <li><b>CND Content</b> - Click on the "CDN" tab above (<a href="<?php echo $base_path; ?>admin/config/people/captcha/spam_bot_blocker/cdn">or here</a>) and then "Yes" for "Use CDN".  You also have other options you can select.</li>
    </ul>
  </li>
  <li><b>Adding the "Spam Bot Blocker" to your forms</b> - After "enabling" this module (obviously or you wouldn't be here) the Spam Bot Blocker is ready to work but first you must "attach" the Spam Bot Blocker CAPTCHA to the forms you want it to work on. I'll just explain the way I find easiest:
    <ul>
      <li>Go to <a href="<?php echo $base_path; ?>admin/config/people/captcha">Configuration > User accounts > CAPTCHA</a></li>
			<li>In the form "List" your form "may" or "may not" be showing (this is beyond me and I don't know why).  Anyways... even if it is showing the "form_id" is a bit difficult to determine exactly which form you want to put "Spam Bot Blocker" on (in a perfect world "form_id" should be the "Title" of your form).</li>
			<li>If you know the "form_id" of your form and your form is showing up in the list, just select "Spam Bot Blocker" from the drop down in the "CHALLENGE TYPE" column.</li>
			<li>If you DON'T know the "form_id" or your form isn't showing up, scroll down and check "Add CAPTCHA administration links to forms"... "Save Configuration" at the bottom.</li>      
			<li>Navigate to your form "<a href="<?php echo $base_path; ?>admin/content/webform">Content > Webforms</a>" and click the "Title" of your form.</li>			
			<li>At the bottom of the form you will see something like this:<br />
      <p><img src="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/help_0001_0001.jpg"></p>
      Click the "Place a CAPTCHA here for untrusted users"
      </li>
      <li>After clicking the link you will see as screen like this:<br />
      <p><img src="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/help_0002_0001.jpg"></p>
      From the select drop down choose "Spam Bot Blocker"
      </li>
      <li>Don't forget to save:<br />
      <p><img src="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/help_0003_0001.jpg"></p>
      </li>
      <li>Do this for every form you want the "Spam Bot Blocker" CATPCHA on.</li>
			<li>Now we want to turn the "Add CAPTCHA administration links to forms" back off so go back to "<a href="<?php echo $base_path; ?>admin/config/people/captcha">Configuration > User accounts > CAPTCHA</a>" and "uncheck" the box for "Add CAPTCHA administration links to forms", "Save Configuration" at the bottom.</li>
			<li>REMEMBER! that the "Administrator" (the Role you are most likely logged in with) is usually set to "Skip CAPTCHA" on the "Permissions" screen "<a href="<?php echo $base_path; ?>admin/config/people/permissions">Configuration > User accounts > Permissions</a>" so when you are logged in as the Administrator you WILL NOT see the CAPTCHA on the form if you view the forms page!  You must either "Log Out" and view the page OR open the page with a different browser (which of course your not logged in again once again!).</li>		
		</ul>
  </li>
  <li>CAPTCHA Explanation Message<br />
  <p><img src="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/help_0004_0001.jpg"></p>
  <p>You may want to change this message to something like:<br />
  <b>Are you human? Select the Best Answer from the Question Image.</b><br />
  This can be changed here: <a href="<?php echo $base_path; ?>admin/config/people/captcha">Configuration > People > Captcha</a> in the "Challenge description" field
  </p>
  </li>
  <li><b>Cropper</b> - Install and use a "Cropper" tool for your local Spam Bot Blocker content images
    <ul>
      <li>The content type "Spam Bot Blocker" contains a field called "Image" (<a href="<?php echo $base_path; ?>">See all fields here</a>)</li>
      <li>Instead of having to upload an image that "should be exactly 300 pixels wide by 250 pixels high" as the Help Text on the Image field says, you can install a "Cropper" module.</li>
      <li>Unfortunately at the time of this version, there is no "Cropper" module for Backdrop yet (2015, Dec. 23). For the Drupal version we suggested <a href="https://www.backdrop.org/project/imagefield_crop" target="_blank">Imagefield Crop</a> and hopefully in the future that module will be ported to Backdrop.</li>
			<!--
			<li><a href="https://www.backdrop.org/project/imagefield_crop" target="_blank">Imagefield Crop</a> is the cropper we use when we want to use a cropper.
        <ul>
          <li>Download, install and enable it</li>
          <li><a href="XXX echo $base_path; ?>admin/structure/types/manage/spam-bot-blocker/fields/field_sbb_image/widget-type">Edit the Widget Type</a> of the "Image Field", from the drop-down select "Image with cropping" (will be visible after you install Imagefield Crop) and click "Continue".</li>
          <li><a href="XXX echo $base_path; ?>admin/structure/types/manage/spam-bot-blocker/fields/field_sbb_image">Edit the "Image Field".</a></li>
          <li>Scroll down to "The resolution to crop the image onto" and enter "300" in the left box (width) and "250" in the right box (height).</li>
          <li>That's it, "Save" at the bottom</li>
          <li>Now you can upload any image size (up to your Backdrop/Server config allowance) and "Crop" it to the exact size to work with Spam Bot Blocker.</li>
        </ul>
      </li>
			-->
    </ul>
  </li>
  <li>(optional) <b>Join <a href="http://www.spambotblocker.com/" target="_blank">SpamBotBlocker.com</a></b> and help make the web a better place!
    <ul>
      <li>Take a few moments and join! Then add your own CAPTCHA's to our CDN pool and let's make the web a better place! It only takes a few moments to create a CAPTCHA.</li>
    </ul>
  </li>
  <li><b>Spam Bot Blocker "Flow"</b> (<a href="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/spam_bot_blocker_flow.jpg" target="_blank">download</a>)<br />
  <p><img src="<?php echo $base_path . backdrop_get_path('module', 'spam_bot_blocker'); ?>/images/spam_bot_blocker_flow.jpg"></p>
  </li>
</ul>
<?php
$html = ob_get_clean();

return $html;
} // ===== END Basic Settings ================