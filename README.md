Spam Bot Blocker
============================

Description
----------------------------

"Spam Bot Blocker" blocks SPAM submitted through forms by bots.

"Real Humans" can easily pass just by clicking the correct answer
to a challenge.

"Challenges" can be added in one of two ways:

1.) Users can create their own local "Spam Bot Blocker" Content
    (it's a normal Backdrop Content Type) or,
		
2.) Users can use the SpamBotBlocker.com community CDN to
    automatically serve "Spam Bot Blocker" challenges.

For either service (locally created content or CDN served challenges),
not only do users create their own questions and answers, they upload
an image or graphic to which the question relates. Since anybody can
upload any image and create an infinite amount of possible image related
question/answer combinations, it makes it almost impossible for bots to pass.

Note that by using the "Spam Bot Blocker" CDN an "ad" will be passed with
the challenge (see example links below).  With "Locally Created Content"
no ads will be along side the challenge (of course).


Example Sites (forms) using the "Spam Bot Blocker" Module
----------------------------

To see what the "Spam Bot Blocker" CAPTCHA looks like on a form,
here are some live sites that are using it (note that these are Drupal 7
sites using the Drupal 7 "Spam Bot Blocker" module. Backdrop sites will
look exactly the same).

http://www.snapjapan.com/contact-us

http://www.thedreamchest.com/form/contact

http://www.cloudbrat.com/form/contact-us


Installation
----------------------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

1.) Download and copy the module into your "/modules" folder

2.) In order for the "Spam Bot Blocker" CAPTCHA to be enabled, the "CAPTCHA"
     module is required: https://backdropcms.org/project/captcha
		 
3.) Enable the module at "Functionality > Modules" (/admin/modules/list)
    and find the "Spam Bot Blocker" Module. Check the box and save at the bottom.
		
4.) Once the module has been enabled, review the "Help" section at
    "Configuration > User accounts > CAPTCHA > Spam Bot Blocker > Help"
		(/admin/config/people/captcha/spam_bot_blocker/help)


License
----------------------------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.


Current Maintainers
----------------------------

- BSCOOL (JugglingCoder) (https://github.com/JugglingCoder/, http://www.thedreamchest.com/)


Credits
----------------------------

- Ported to Backdrop CMS by BSCOOL (JugglingCoder) (https://github.com/JugglingCoder/, http://www.thedreamchest.com/)
- Originally written for Drupal 7 by BSCOOL (JugglingCoder) (https://github.com/JugglingCoder/, http://www.thedreamchest.com/)
