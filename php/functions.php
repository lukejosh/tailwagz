<?php
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
	
		function display_month($month, $year) {
			
			$first_day_of_month = mktime(0, 0, 0, $month, 1, $year);
			$first_day_of_week = date('w', $first_day_of_month);
			$month_name = date('F', $first_day_of_month);
			$days_in_month = date('t', $first_day_of_month);
			
			$current_year = gmDate("Y");
			$current_month = gmDate("m");
			$current_day = gmDate("d");
			
			echo "<h2>".$month_name." ".$year."</h2>";
			echo "<table border='solid'><tr><th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr>";
			
			if ($first_day_of_week > 0){
				echo "<td colspan=\"$first_day_of_week\">&nbsp;</td>";
			};
			
			for ($day_of_week = $first_day_of_week, $day_of_month=1;$day_of_month <= $days_in_month; $day_of_month++, $day_of_week++){
				if ($day_of_week == 7) # if past end of week
				{
					echo '</tr>'; # end the row for the current week
					$day_of_week = 0; # reset to the start of the week
					echo '<tr>'; # create a row for the next week
				}
				if ($current_year == $year && $current_month == $month && $current_day == $day_of_month){
					echo "<td><b>$day_of_month</b></td>";
				}else{
					echo "<td>$day_of_month</td>";
				}
			}
			
			$last_day_of_month = mktime(0, 0, 0, $month, $days_in_month, $year);
			$last_day_of_week = date('w', $last_day_of_month);
			
			
			
			if ($last_day_of_week < 6){
				$num_empty_cols = 6 - $last_day_of_week;
				echo "<td colspan=\"$num_empty_cols\">&nbsp;</td>";
			};
			echo "<tr></tr></table>";

		}
?>