/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


//SCRIPT BOUTON TOP
$(window).scroll(function(){
    posScroll = $(document).scrollTop();
    //window.document.getElementById('ScrollTest').innerHTML = posScroll;
    if(posScroll > 0) 
        $('.btn_top').fadeIn(600);
    else
        $('.btn_top').fadeOut(600);
});


jQuery(function($){
	$(".datepicker").datepicker({
	    showOn: 'button',
	    buttonText: 'Show Date',
	    buttonImageOnly: true,
	    buttonImage: 'images/calendar.png',
	    dateFormat: 'dd/mm/yy',
	    constrainInput: true,
	    minDate : 0
	});

	$(".ui-datepicker-trigger").mouseover(function() {
	    $(this).css('cursor', 'pointer');
	});
	$(".ui-datepicker-trigger").css("margin-bottom","-6px");
	$(".ui-datepicker-trigger").css("margin-left","2px");
});


function getCookie(name){
    if(document.cookie.length == 0)
      return null;

    var regSepCookie = new RegExp('(; )', 'g');
    var cookies = document.cookie.split(regSepCookie);

    for(var i = 0; i < cookies.length; i++){
      var regInfo = new RegExp('=', 'g');
      var infos = cookies[i].split(regInfo);
      if(infos[0] == name){
        return unescape(infos[1]);
      }
    }
    return null;
}

function formattedDate(date) {
    var d = new Date(date),
        month = '' + (d.getMonth() + 1),
        day = '' + d.getDate(),
        year = d.getFullYear();

    if (month.length < 2) month = '0' + month;
    if (day.length < 2) day = '0' + day;

    return [day, month, year].join('/');
}
