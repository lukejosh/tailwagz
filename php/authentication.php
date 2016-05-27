<?php
	function get_sql_connector(){
		$pdo = new PDO('mysql:host=localhost;dbname=tailwagz', 'root', ''); 
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
		return $pdo;
	}
	
	function get_sql_connector_aws(){
		$pdo = new PDO('mysql:host=tailwagz.cfvove2ohkes.ap-southeast-2.rds.amazonaws.com;dbname=n9155554', 'admin', 'masterpassword');
		//$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
		return $pdo;
	}
	
	function perform_sql_query($pdo, $query, $parameters){
		try {			 
			$result = $pdo->prepare($query);
					
			if(!is_null($parameters)){
				while($value = current($parameters)){
					$result->bindValue(':'.key($parameters), $value);
					next($parameters);
				}
			}						
			$result->execute();
			return $result;
		} catch (PDOException $e) {
			$_SESSION['errorMessage'] = json_encode($parameters)."".$e->getMessage();
			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/error.php");
			exit();
		}
	}

	function signup(array $data){
		$pdo = get_sql_connector();
		$query = ''.
			'SELECT * '.
			'FROM users '.
			'WHERE username = :username'; 
		$parameters['username'] = htmlspecialchars($data['username'], ENT_QUOTES, 'UTF-8');
		$result = perform_sql_query($pdo, $query, $parameters);
								
		if ($result->rowCount() > 0){			
			$_SESSION['errorMessage'] = 'Username already exists';
			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/signup.php");
			exit();
		}

		$query = ''.
			'INSERT INTO users (username, password, salt, firstName, lastName, email, dob, mobile, sex) '.
			'VALUES(:username, SHA2(CONCAT(:password, salt), 0), salt, :firstName, :lastName, :email, DATE(:dob), :mobile, :sex)';	
		$parameters['password'] = htmlspecialchars($data['password'], ENT_QUOTES, 'UTF-8');
		$parameters['firstName'] = htmlspecialchars($data['firstname'], ENT_QUOTES, 'UTF-8');
		$parameters['lastName'] = htmlspecialchars($data['lastname'], ENT_QUOTES, 'UTF-8');
		$parameters['email'] = htmlspecialchars($data['email'], ENT_QUOTES, 'UTF-8');
		$parameters['dob'] = htmlspecialchars($data['dob'], ENT_QUOTES, 'UTF-8');
		$parameters['mobile'] = htmlspecialchars($data['mobile'], ENT_QUOTES, 'UTF-8');
		$parameters['sex'] = htmlspecialchars($data['sex'], ENT_QUOTES, 'UTF-8');
		
		$result = perform_sql_query($pdo, $query, $parameters);
								
		if ($result->rowCount() > 0){			
			session_start(); 
			session_id();
			$_SESSION['isLoggedOn'] = true;
			$_SESSION['username'] = $data['username'];
			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/index.php");
			exit();
		}		
	}

	function login(array $data){	
		$pdo = get_sql_connector();
		$query = ''.
				'SELECT * '.
				'FROM users'.
				'WHERE username = :username and '.
				'password = SHA2(CONCAT(:password, salt), 0)'; 

		$parameters['username'] = $data['username'];
		$parameters['password'] = $data['password'];
		$result = perform_sql_query($pdo, $query, $parameters);
									
		if ($result->rowCount() > 0){ 
			session_start(); 
			session_id();
			$_SESSION['isLoggedOn'] = true;
			
			$user = $result -> fetch();
			$_SESSION['username'] = htmlspecialchars($user['username'], ENT_QUOTES, 'UTF-8');

			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/index.php");
			exit();
		} else {			
			$_SESSION['errorMessage'] = 'Failed to log on. Please check your email and password';
			header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/login.php");			
		}
	}
		
	function logout(){
		session_id();		
		// Unset all of the session variables.
		$_SESSION = array();

		// If it's desired to kill the session, also delete the session cookie.
		// Note: This will destroy the session, and not just the session data!
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
	
	function show_session_username(){
		echo '<p class="auth" id="username">';
		
		if (isset($_SESSION['username']))
		{
			echo "You are logged in as <b>".$_SESSION['username'];
		} else {
			//echo 'Not logged in';
		}
		echo '</b></p>';
	}
	
	function show_session_actions(){
		if (isset($_SESSION['isLoggedOn']))
		{
			?><a class="auth" href="logout.php">Log Out</a><?php	
		} else {
			?><a class="auth" href="login.php">Log In</a>
			<a class="auth" href="signup.php">Sign Up</a>
			<?php
		}
	}
?>