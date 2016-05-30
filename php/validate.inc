<?php
	// Function: remove_scripts($form_data)
	// Description: removes any cross site scripting from raw GET or POST data
	// Input: raw GET or POST data
	// Output: cleansed GET or POST data
	function remove_scripts($form_data){
		
		// Loop through each field in the posted data and remove any cross site scripting
		foreach ($form_data as $field => $value){			
			$form_data[$field] = htmlspecialchars($value, ENT_QUOTES, 'UTF-8'); 			
		}
		
		//return the posted data with the scripting removed 
		return $form_data;
	}

	// Function: validate_username(&$form_data, $field_name)
	// Description: checks a username against a regex expression
	// Input: GET or POST data and the name of the username field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_username(&$form_data, $field_name)
	{
		$pattern = "/^[a-zA-Z0-9]+$/";
		
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
	
	// Function: validate_password(&$form_data, $field_name)
	// Description: checks a password against a regex expression
	// Input: GET or POST data and the name of the password field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
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
	
	
	// Function: validate_name(&$form_data, $field_name)
	// Description: checks a text entry against a regex expression
	// Input: GET or POST data and the name of the text field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_name(&$form_data, $field_name)
	{
		$pattern = "/^[a-zA-Z_ ]+$/";
		
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
	
	// Function: validate_email(&$form_data, $field_name)
	// Description: checks an email against a regex expression
	// Input: GET or POST data and the name of the email field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
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
	
	
	// Function: validate_date(&$form_data, $field_name)
	// Description: checks a date against a regex expression
	// Input: GET or POST data and the name of the date field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_date(&$form_data, $field_name)
	{
		$pattern = '/^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$/';
		
		if (!isset($form_data[$field_name])|| empty($form_data[$field_name])){
			$_SESSION['errorMessage'] = 'Date of Birth is required';
			return false;
		}
		else if (!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = $form_data[$field_name].'<br>Date of Birth format is incorrect<br>'.
																'Expected format is yyyy-mm-dd';
			return false;
		}
		return true;
	}
	
	
	// Function: validate_number(&$form_data, $field_name)
	// Description: checks a number against a regex expression
	// Input: GET or POST data and the name of the number field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
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
	
	
	// Function: validate_gender(&$form_data, $field_name)
	// Description: checks a gender against a regex expression
	// Input: GET or POST data and the name of the gender field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_gender(&$form_data, $field_name)
	{
		$pattern = '/^(female|male)$/';
		
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
	
	
	// Function: check_passwords_match($form_data , $password1 , $password2)
	// Description: checks two passwords to see if they match
	// Input: GET or POST data and the names of the password fields
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function check_passwords_match($form_data , $password1 , $password2){
		
		if ($form_data[$password1] == $form_data[$password1]){
			return true;
		}
		$_SESSION['errorMessage'] = 'Passwords do not match';
		return false;	
	}
	
	// Function: validate_search_term_string($form_data, $field_name){
	// Description: checks a search term against a regex expression
	// Input: GET or POST data and the name of the search term field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_search_term_string($form_data, $field_name){
		$pattern = "/^[a-zA-Z ]*$/";

		if(!preg_match($pattern, $form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' term can only contain letters';
		return false;
		}

		return true;
	}

	// Function: validate_search_term_integrer($form_data, $field_name)
	// Description: checks a search term number against a regex expression
	// Input: GET or POST data and the name of the search term field
	// Output: boolean value, true if matched, false if not matched
	// also provides a useful error message if false.
	function validate_search_term_integer($form_data, $field_name){
		$pattern = "\"/^[0-9]*$/\"";

		if(!preg_match("/^[0-9]*$/", $form_data[$field_name])){
			$_SESSION['errorMessage'] = $field_name.' term must contain a number';
			return false;
		}

		return true;
	}

	// Function: validate_all_search()
	// Description: validates all search terms using the validate_search_term functions
	// Input: none
	// Output: none. Function reload search page if validation fails
	function validate_all_search(){
		
		// validate a keyword search
		if(isset($_GET['search'])){
			$validated = validate_search_term_string($_GET, 'search');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		// validate a suburb search
		if (isset($_GET['suburb'])){
			$validated = validate_search_term_string($_GET, 'suburb');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		// validate a category search
		if (isset($_GET['category'])){
			$validated = validate_search_term_string($_GET, 'category');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}

		// validate a distance search
		if (isset($_GET['distance'])){
			$validated = validate_search_term_integer($_GET, 'distance');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}
		
		// validate a minimum rating search
		if (isset($_GET['rating'])){
			$validated = validate_search_term_integer($_GET, 'rating');
			if(!$validated){
				header("Location: ".get_base_url()."/search.php");
				exit();
			}
		}
	}
?>