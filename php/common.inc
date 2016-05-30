<?php

	// Function: get_base_url()
	// Description: Returns the base url of the website
	// Input: none
	// Output: Base url of website
	function get_base_url(){
		return "http://{$_SERVER['HTTP_HOST']}//n9438726";
	}

	// Function: get_sql_connector()
	// Description: Returns the connector to the sql database
	// Input: none
	// Output: PDO object directed to the sql database
	function get_sql_connector(){
		$pdo = new PDO('mysql:host=fastapps04.qut.edu.au;dbname=n9438726', 'n9438726', 'password1');
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		return $pdo;
	}

	// Function: perform_sql_query($query, $parameters)
	// Description: A single function to perform sql queries
	// Input: the sql query string and an array containing 
	// all the parameters to be bound to the query
	// Output: The result object of the query else
	// redirects to error page if error has occurred
	function perform_sql_query($query, $parameters){
		// Get the sql connector object
		$pdo = get_sql_connector();

		try {
			// prepare the query
			$result = $pdo->prepare($query);
			
			// check if the parameters is not null
			if(!is_null($parameters)){
				// Loop over each parameter and bind to query
				while($value = current($parameters)){
					$result->bindValue(':'.key($parameters), $value);
					next($parameters);
				}
			}
			
			// Execute the query
			$result->execute();
			
			// Return the result
			return $result;
		} catch (PDOException $e) {
			// Set a useful error message
			//$_SESSION['errorMessage'] = $result->queryString."<br><br>".json_encode($parameters)."<br><br>".$e->getMessage();
			$_SESSION['errorMessage'] = $e->getMessage();
			
			// Redirect to error page
			header("Location: ".get_base_url()."/error.php");
			exit();
		}
	}
	
	// Function: display_error_message()
	// Description: a single function to echo any 
	// error messages from the users session
	// Input: none
	// Output: none
	function display_error_message(){
		if (isset($_SESSION['errorMessage'])){
			echo "<p class='error'>";
			echo $_SESSION['errorMessage'];
			echo "</p>";
			$_SESSION['errorMessage'] = null;
		}
	}

	// Function: display_map($search_data)
	// Description: a single function to display a map
	// with each park added as a marker 
	// error messages from the users session
	// Input: the search data from the parks table
	// Output: none
	function display_map($search_data){
		
		// Set up and init an empty map
		echo '<div class="googleMap" id="googleMap"></div>';
		echo '<script>initMap();</script>';

		// Add each park as a marker on the map 
		foreach($search_data as $park){
			echo '<script>addMarkerToMap('.$park['latitude'].','.$park['longitude'].
				',"'.$park['name'].'","park.php?id='.$park['parkid'].
				'","'.$park['rating'].'","'.$park['suburb'].
				'","'.$park['street'].'");</script>';
		}
	}

	// Function: display_session_username()
	// Description: a single function to display the
	// logged in users name if logged in
	// Input: none
	// Output: none
	function display_session_username(){
		echo '<p class="auth" id="username">';

		if (isset($_SESSION['username']))
		{
			echo "Signed in as <b>".$_SESSION['username'];
		}
		echo '</b></p>';
	}

	// Function: display_session_actions()
	// Description: a single function to display the
	// available actions for a user based on if they're
	// logged in or not
	// Input: none
	// Output: none
	function display_session_actions(){
		if (isset($_SESSION['isLoggedOn']))
		{
			?><a class="auth" href="signout.php">Sign Out</a><?php
		} else {
			?><a class="auth" href="signin.php">Sign In</a>
			<a class="auth" href="signup.php">Sign Up</a>
			<?php
		}
	}
?>