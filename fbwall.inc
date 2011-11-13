<?php 

/**
 * @file
 * Form builder for fbwall configuration page
 */

/**
 * fbwall Form.
 */ 
function fbwall_form($form, &$form_state) {
	$settings = variable_get('fbwall_settings');

	$form['fbwall_fb_id'] = array(
	'#type' => 'textfield',
	'#title' => t('Facebook ID'),
	'#required' => TRUE,
	'#default_value' => $settings['id'],
	'#description' => t('ID element of facebook page'),
	);

	$options = array(
	'1' => '1',
	'2' => '2', 
	'3' => '3', 
	'4' => '4', 
	'5' => '5', 
	'6' => '6', 
	'7' => '7', 
	'8' => '8', 
	'9' => '9', 
	'10' => '10', 
	);
	
	$form['fbwall_nb_item'] = array(
	'#type' => 'select',
	'#title' => t('Number of displayed Items'),
	'#options' => $options,
	'#default_value' => $settings['item'],
	'#description' => t('How many items to display ?'),
	);

	$options = array(
	'1' => t('yes'),
	'0' => t('no'), 
	);

	$form['fbwall_show_com'] = array(
	'#type' => 'radios',
	'#title' => t('Show comments ?'),
	'#options' => $options,
	'#description' => t('Would you like to show comments ?'),
	'#default_value' => $settings['comments'],
	);
	
	$options = array(
	'1' => t('yes'),
	'0' => t('no'), 
	);

	$form['fbwall_show_entries'] = array(
	  '#type' => 'radios',
	  '#title' => t('Show guest entries ?'),
	  '#options' => $options,
	  '#description' => t('Would you like to show guest entries ?'),
	  '#default_value' => $settings['guestEntries'],
	);

	$options = array(
	'12' => t('12-hour'),
	'24' => t('24-hour'), 
	);

	$form['fbwall_time_conv'] = array(
	  '#type' => 'radios',
	  '#title' => t('Time conversion ?'),
	  '#options' => $options,
	  '#description' => t('Would you like to show guest entries ?'),
	  '#default_value' => $settings['time'],
	);
	
	// Submit button
	$form['submit'] = array(
	'#type' => 'submit',
	'#value' => t('Save settings'),
	);
	
	return $form;	
}

/**
 * Save variables
 */
 function fbwall_form_submit($form, &$form_state) {
 	$settings = array(
	 	'id' => $form_state['values']['fbwall_fb_id'],
	 	'item' => $form_state['values']['fbwall_nb_item'],
	 	'guestEntries' => $form_state['values']['fbwall_show_entries'],
	 	'comments' => $form_state['values']['fbwall_show_com'],
	 	'time' => $form_state['values']['fbwall_time_conv'],
 	);
 	variable_set('fbwall_settings', $settings);

 	drupal_set_message(t('The settings have been saved'));
 }