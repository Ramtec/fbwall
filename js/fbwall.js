(function($) {

	Drupal.behaviors.fbwall = {
		attach: function (context) {
			$('#facebook_wall').fbWall({
				id:Drupal.settings.fbwall_settings.id,
				accessToken:'206158599425293|7809823973348bcf8cd72f6d.1-100000221135225|BW9n2eoyL7EYvJs7GEmv61NbBFk',
				showGuestEntries:Drupal.settings.fbwall_settings.guestEntries,
				showComments:Drupal.settings.fbwall_settings.comments,
				max:Drupal.settings.fbwall_settings.item,
				timeConversion:Drupal.settings.fbwall_settings.time
			});
		}	
	};
}) (jQuery) ;


