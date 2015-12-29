/**
 * @file
 * Un-check Radios on reload
 */
(function($) {
$(document).ready(function(){

  var inputs = document.getElementsByName("captcha_response");
  for(var i = inputs.length-1;i>=0;i--){
    if(inputs[i].getAttribute("type")==="radio"){
      inputs[i].checked=false;
    }
  }  
});
})(jQuery);