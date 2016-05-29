<?php
	function remove_scripts($form_data){
		// add logic to remove sql injection and xxs
		
		// foreach ($form_data as $field => $value){
			
			//$form_data[$field] = htmlspecialchars($value, ENT_QUOTES, 'UTF-8'); 
			//Duplicate the statment above for sql injection 
			
		//}
		
		return $form_data;
	}

	function validate_username(&$form_data, $field_name)
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
	
	function validate_password($form_data, $field_name)
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
	
	function validate_name(&$form_data, $field_name)
	{
		$pattern = "/^[a-zA-Z_ ]+/";
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' must contain only letters and spaces';
			return false;
		}
		return true;
	}
	
	function validate_email(&$form_data, $field_name)
	{
		$pattern = '/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/';
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Email is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Email format is incorrect';
			return false;
		}
		return true;
	}
	
	function validate_date(&$form_data, $field_name)
	{
		$pattern = '/^(0?[1-9]|[12][0-9]|3[01])[\/\-](0?[1-9]|1[012])[\/\-]\d{4}$/';
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Date of Birth is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Date of Birth format is incorrect';
			return false;
		}
		return true;
	}
	
	function validate_number(&$form_data, $field_name)
	{
		$pattern = '/^[0-9]{10}$/';
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Mobile number is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Mobile number format is incorrect';
			return false;
		}
		return true;
	}
	
	function validate_number(&$form_data, $field_name)
	{
		$pattern = '/^[0-9]{10}$/';
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Gender is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Gender is incorrect';
			return false;
		}
		return true;
	}
	
	function validate_search_term_string($form_data, $field_name){
		$pattern = "/^[a-zA-Z ]*$/";

		if(!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' term can only contain letters';
		return false;
		}

		return true;
	}

	function validate_search_term_integer($form_data, $field_name){
		$pattern = "\"/^[0-9]*$/\"";

		if(!preg_match("/^[0-9]*$/", $form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' term must contain a number';
			return false;
		}

		return true;
	}

	function validate_all_search(){
		if(isset($_GET['search'])){
			$validated = validate_search_term_string($_GET, 'search');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		if (isset($_GET['suburb'])){
			$validated = validate_search_term_string($_GET, 'suburb');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		if (isset($_GET['category'])){
			$validated = validate_search_term_string($_GET, 'category');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		if (isset($_GET['distance'])){
			$validated = validate_search_term_integer($_GET, 'distance');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}
		if (isset($_GET['rating'])){
			$validated = validate_search_term_integer($_GET, 'rating');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}
	}
?>