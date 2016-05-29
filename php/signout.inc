<?php
	// Function: signout()
	// Description: a function to sign the user out
	// Input: none
	// Output: none
	function signout(){
		session_id();
		// Unset all of the session variables.
		$_SESSION = array();

		// Destroy the session and session data
		if (ini_get("session.use_cookies")) {
			$params = session_get_cookie_params();
			setcookie(session_name(), '', time() - 42000,
				$params["path"], $params["domain"],
				$params["secure"], $params["httponly"]
			);
		}
		
		// Finally, destroy the session.
		session_destroy();
	}
?>