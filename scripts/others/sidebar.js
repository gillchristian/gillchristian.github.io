$(document).ready(function(){
  	
	$(".button-collapse").sideNav();
	
	$('.collapsible').collapsible();
	
	$('.button-collapse').sideNav({
		  closeOnClick: true // Closes side-nav on <a> clicks, useful for Angular/Meteor
		}
	);
	/*
	$('.sideMenu').on('click',function(){
		var $overlayDiv = $('<div id="sidenav-overlay" style="opacity: 1;" class=""></div>');
		
		
		while($overlayDiv){
			$overlayDiv.remove();
		}
			$overlayDiv = $('<div id="sidenav-overlay" style="opacity: 1;" class=""></div>');
			console.log('after',$overlayDiv);
		//$($overlayDiv).each(function() {
		//	$(this).remove();
			
		//});
	});
	
	if($('.drag-target').length){
			  return;
			}
	*/
 });
