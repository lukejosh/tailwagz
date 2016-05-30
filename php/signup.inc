<?php
	// Function: signup(array $data)
	// Description: a function to sign a new user up
	// Input: signup form POST parameters
	// Output: none
	function signup(array $data){
		$query = ''.
			'INSERT INTO users (username, password, salt, firstName, lastName, email, dob, mobile, sex) '.
			'VALUES(:username, SHA2(CONCAT(:password, salt), 0), salt, :firstName, :lastName, :email, DATE(:dob), :mobile, :sex)';

		$username = htmlspecialchars($data['username'], ENT_QUOTES, 'UTF-8');

		// If a username already exists
		if (is_username_existing($username)){
			// then add helpful message and stop sign up process
			$_SESSION['errorMessage'] = 'Username already exists';
			return;
		}

		// Bind parameters
		$parameters['username'] = $username;
		$parameters['password'] = htmlspecialchars($data['password'], ENT_QUOTES, 'UTF-8');
		$parameters['firstName'] = htmlspecialchars($data['firstname'], ENT_QUOTES, 'UTF-8');
		$parameters['lastName'] = htmlspecialchars($data['lastname'], ENT_QUOTES, 'UTF-8');
		$parameters['email'] = htmlspecialchars($data['email'], ENT_QUOTES, 'UTF-8');
		$parameters['dob'] = htmlspecialchars($data['dob'], ENT_QUOTES, 'UTF-8');
		$parameters['mobile'] = htmlspecialchars($data['mobile'], ENT_QUOTES, 'UTF-8');
		$parameters['sex'] = htmlspecialchars($data['sex'], ENT_QUOTES, 'UTF-8');

		// Add user to data base
		$result = perform_sql_query($query, $parameters);

		// sign the user in
		session_id();
		$_SESSION['isLoggedOn'] = true;
		$_SESSION['username'] = $data['username'];
		header("Location: ".get_base_url()."/index.php");
		exit();
	}

	// Function: is_username_existing($username)
	// Description: a function to check if a username already exists in the database
	// Input: the username
	// Output: returns true if the username already exists
	function is_username_existing($username){
		$query = ''.
			'SELECT * '.
			'FROM users '.
			'WHERE username = :username';
		$parameters['username'] = $username;
		$result = perform_sql_query($query, $parameters);

		if ($result->rowCount() > 0){
			return true;
		}

		return false;
	}

	// Function: display_signin_form($form_data)
	// Description: a function to display the signup form with data from previous post already pre-filled
	// Input: the previous post data
	// Output: none
	function display_signin_form($form_data){
		// Sets all form variables to blank
		$username = "";
		$firstname = "";
		$lastname = "";
		$email = "";
		$dob = "";
		$mobile = "";
		$gender = "";
		$male = "checked";
		$female = "";
		
		// Check to see if username was previously fill in
		if (isset($form_data['username'])) {
			$username = $form_data['username'];
		}
		
		// Check to see if firstname was previously fill in
		if (isset($form_data['firstname'])) {
			$firstname = $form_data['firstname'];
		}
		
		// Check to see if lastname was previously fill in
		if (isset($form_data['lastname'])) {
			$lastname = $form_data['lastname'];
		}
		
		// Check to see if email was previously fill in
		if (isset($form_data['email'])) {
			$email = $form_data['email'];
		}
		
		// Check to see if date of birth was previously fill in
		if (isset($form_data['dob'])) {
			$dob = $form_data['dob'];
		}
		
		// Check to see if mobile number was previously fill in
		if (isset($form_data['mobile'])) {
			$mobile = $form_data['mobile'];
		}
		
		// Check to see if gender was previously fill in
		if (isset($form_data['sex'])) {
			if ($form_data['sex'] == "female"){
				$male = "";
				$female = "checked";
			}
		}
		
		// Echs out the form with the previously filled out parameters added to the form
		echo "<form id='signup' action='signup.php' method='post' >
				<span>Username</span>
				<input type='text' name='username' id='username' placeholder='Username' value='".$username."' required/>
				<span>First Name</span>
				<input type='text' name='firstname' id='firstname' placeholder='First Name' value='".$firstname."' required/>
				<span>Last Name</span>
				<input type='text' name='lastname' id='lastname' placeholder='Last Name' value='".$lastname."' required/>
				<span>Email Address</span>
				<input type='email' name='email' id='email' placeholder='E-Mail Address' value='".$email."' required/>
				<span>Mobile Number</span>
				<input type='text' name='mobile' id='mobile' placeholder='Phone number' value='".$mobile."' required/>
				<span>Gender</span>
				<div id='rbuttons'>
					<input type='radio' name='sex' value='male' ".$male."/>
					<span class='textlabel'>Male</span>
					<input type='radio' name='sex' value='female' ".$female."/>
					<span class='textlabel'>Female</span>
				</div>
				<span>Date of birth (yyyy-mm-dd)</span>
				<input type='date' class='date' name='dob' id='dob' max='2019-12-31' value='".$dob."' required/>
				<span>Password</span>
				<input type='password' name='password' id='password' placeholder='Password' required/>
				<span>Confirm Password</span>
				<input type='password' name='confpassword' id='confpassword' placeholder='Confirm Password' onchange='validate_password();' required/>
				<input type='submit' class='submit' name='signup' id='signup' value='Sign Up'/>
			</form>";
	}
?>