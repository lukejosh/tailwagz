<?php
	// Function: signin(array $signin_data)
	// Description: a function to sign a user in
	// Input: signin form POST parameters
	// Output: none
	function signin(array $signin_data){
		session_id();
		$query = ''.
			'SELECT * '.
			'FROM users '.
			'WHERE username = :username and '.
			'password = SHA2(CONCAT(:password, salt), 0)';

		$parameters['username'] = $signin_data['username'];
		$parameters['password'] = $signin_data['password'];
		$result = perform_sql_query($query, $parameters);

		// If there is more than one user with a matching password and username 
		if ($result->rowCount() > 0){
			// then set the session isLoggedOn variable true
			session_id();
			$_SESSION['isLoggedOn'] = true;
			
			// Get the users information
			$user = $result -> fetch();
			$_SESSION['username'] = htmlspecialchars($user['username'], ENT_QUOTES, 'UTF-8');

			// Redirect to the homepage
			header("Location: ".get_base_url()."/index.php");
			exit();
		}

		// Else the sign in attempt failed
		$_SESSION['errorMessage'] = 'Failed to sign on. Please check your username and password';
	}

	// Function: display_signin_form($form_data)
	// Description: a function to display the sign in form
	// Input: signin form POST parameters
	// Output: none
	function display_signin_form($form_data){
		$username = "";
		$password = "";
		
		// If the username was previously set then add it to the form
		if (isset($form_data['username'])) {
			$username = $form_data['username'];
		}
		
		// If the password was previously set then add it to the form
		if (isset($form_data['password'])) {
			$password = $form_data['password'];
		}
		
		// Echo the form out
		echo "<form id='signin' action='signin.php' method='post'>
				<span>Username</span>
				<input type='text' name='username' id='username' placeholder='Username' value='".$username."' required/>
				<span>Password</span>
				<input type='password' name='password' id='password' placeholder='Password' value='".$password."' required/>
				<input type='submit' class='submit' name='signin' id='signinsubmit' value='Sign In'/>
			</form>";
	}
?>