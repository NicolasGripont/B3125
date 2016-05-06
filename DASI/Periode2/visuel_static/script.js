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
	    buttonImage: 'calendar.png',
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


