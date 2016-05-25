<?php
	function login($username, $password){	
		$pdo = new PDO('mysql:host=localhost;dbname=authentication', 'root', ''); 
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
		
		try { 			
			$result = $pdo->prepare('SELECT * '.
									'FROM admins '.
									'WHERE username = :username and '.
									'password = SHA2(CONCAT(:password, salt), 0)'); 
			$result->bindValue(":username", $username);
			$result->bindValue(":password", $password);
			$result->execute();
									
			if ($result->rowCount() > 0){ 
				session_start(); 
				session_id();
				$_SESSION['isLoggedOn'] = true;
				$_SESSION['username'] = $username;
				
				header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/index.php?sessionId=");
				exit();
			} else {			
				$_SESSION['errorMessage'] = 'Failed to log on. Please check your email and password';			
			}
		} catch (PDOException $e) { 
			echo $e->getMessage(); 
			$_SESSION['errorMessage'] = 'Something went wrong';
		}
		
		header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/login.php");
	}
?>