Spam Bot Blocker
=======================

Description
------------

"Spam Bot Blocker" blocks SPAM submitted through forms.

It is simple to use and "simple" for visitors to pass yet
extremely "strong". It is a sub-module of the CAPTCHA module
that is unique in three ways:

1.) Users can create their own local CAPTCHA Content
    (it's a normal Backdrop Content Type) or,
2.) Users can use the SpamBotBlocker.com community CDN to
    serve CAPTCHA's, and
3.) for either service (local or CDN), not only do users create
    their own questions and answers, they upload an image or graphic
    to which the question relates. Since anybody can upload any image
    and create an infinite amount of possible image related question/answer
    combinations, it makes it almost impossible for bots to pass.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

1.) Download and copy the module into your "/modules" folder<br />
2.) In order for the "Spam Bot Blocker" CAPTCHA to be enabled, the "CAPTCHA"
     module is required: https://backdropcms.org/project/captcha
3.) Enable the module at "Functionality > Modules" (/admin/modules/list)
    and find the "Spam Bot Blocker" Module. Check the box and save at the bottom.
4.) Once the module has been enabled, review the "Help" section at
    "Configuration > User accounts > CAPTCHA > Spam Bot Blocker > Help"
		(/admin/config/people/captcha/spam_bot_blocker/help)


License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Current Maintainers
-------------------

- BSCOOL (https://github.com/JugglingCoder/)

Credits
-------

- Ported to Backdrop CMS by BSCOOL (https://github.com/JugglingCoder).
- Originally written for Drupal 7 by BSCOOL (https://github.com/JugglingCoder).
