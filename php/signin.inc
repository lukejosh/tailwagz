<?php
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
									
		if ($result->rowCount() > 0){ 
			session_start(); 
			session_id();
			$_SESSION['isLoggedOn'] = true;
			
			$user = $result -> fetch();
			$_SESSION['username'] = htmlspecialchars($user['username'], ENT_QUOTES, 'UTF-8');

			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/index.php");
			exit();
		} 
			
		$_SESSION['errorMessage'] = 'Failed to log on. Please check your email and password';			
	}
?>