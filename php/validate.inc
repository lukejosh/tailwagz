<?php
	function remove_scripts($form_data){
		// add logic to remove sql injection and xxs
		
		// foreach ($form_data as $field => $value){
			
			//$form_data[$field] = htmlspecialchars($value, ENT_QUOTES, 'UTF-8'); 
			//Duplicate the statment above for sql injection 
			
		//}
		
		return $form_data;
	}

	function validateUsername(&$form_data, $field_name)
	{
		$pattern = "/^[a-zA-Z0-9]\w+/";
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Username is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Username must contain only letters and numeric values';
			return false;
		}
		return true;
	}
	
	function validatePassword($form_data, $field_name)
	{		
		$pattern = '/^[a-zA-Z]\w{3,14}$/';
		if (!isset($form_data)|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Password is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = ' Password must be between 4 and 15 characters long.<br>'.
											'No characters other than letters, numbers and the underscore may be used';
			return false;
		}
		return true;
	}	
?>