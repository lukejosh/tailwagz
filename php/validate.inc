<?php
	function validateUsername(&$errors, $field_list, $field_name)
	{
		$pattern = '/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/';
		if (!isset($field_list[$field_name])|| empty($field_list[$field_name]))
			$errors[$field_name] = 'required';
		//else if (!preg_match($pattern, $field_list[$field_name]))
			//$errors[$field_name] = 'invalid';
	}
	
	function validatePassword(&$errors, $field_list, $field_name)
	{
		$pattern = '/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/';
		if (!isset($field_list[$field_name])|| empty($field_list[$field_name]))
			$errors[$field_name] = 'required';
		//else if (!preg_match($pattern, $field_list[$field_name]))
			//$errors[$field_name] = 'invalid';
	}
	
	function checkPassword($username, $password){
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
					$_SESSION['isAdmin'] = true;
					header("Location: http://{$_SERVER['HTTP_HOST']}/tutes/tute11/Private.php");
					exit();
				} else {
					echo 'Login failed';
				}
				
			} catch (PDOException $e) { 
				echo $e->getMessage(); 
			}
	}
?>