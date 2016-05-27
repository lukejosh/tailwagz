<?php
	function display_error_message(){
		if (isset($_SESSION['errorMessage'])){
			echo "<p class='error'>";
			echo $_SESSION['errorMessage'];
			echo "</p>";
			$_SESSION['errorMessage'] = null;					
		}
	}
		 
	function add_suburb_options(){
		$pdo = get_sql_connector_aws();
		$query = 'SELECT DISTINCT suburb FROM parks ORDER BY suburb ASC';
		$parameters = null;
		$result = perform_sql_query($pdo, $query, $parameters);

		if ($result->rowCount() < 1 || is_null($result)){
				exit();
		}

		foreach($result as $key => $row){
			echo "<option value=\"".$row['suburb']."\">".$row['suburb']."</option>";
		}
	}
	 
	 function get_all_parks(){
		$pdo = get_sql_connector_aws();
		$query = 'SELECT * FROM parks';
		return perform_sql_query($pdo, $query, null);
	 }
	 
	 function get_park_by_id($id){
		$pdo = get_sql_connector_aws();
		$query = "SELECT * from parks WHERE parkid = ".$id;
		//$result = perform_sql_query($pdo, $query, null)->fetch();
		$result = perform_sql_query($pdo, $query, null);
		return $result;
	}
	 
	 function get_search_results(){
		$pdo = get_sql_connector_aws();
		
		if(is_null($_GET)){
			return get_all_parks();
		}
		
		while($value = current($_GET)){
			if ($value != ""){		
				$field = key($_GET);
				$query = "SELECT * FROM parks WHERE $field = '$value'";
				return perform_sql_query($pdo, $query, null);
			}
			next($_GET);
		}		
		
		return get_all_parks();	// 	Caters for if all form parameter are emppty
	 }
	 
	 function display_results_rows($search_data){
		foreach($search_data as $park){
			echo "<tr id=\"row\">";
				echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['name']."<a></td>";
				echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['suburb'].", ".$park['street']."<a></td>";
				echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['category']."<a></td>";
				echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['rating']."<a></td>";
			echo "</tr>";
		}
	 }
	 
	 function display_park_info($search_data){
			$park = $search_data[0];
	 
			echo "<p><b>Dog Park Name:</b> ".$park['name']."<br>";
			echo "<b>Street:</b> ".$park['street']."<br>";
			echo "<b>Suburb:</b> ".$park['suburb']."<br>";
			echo "<b>Tags:</b> ".$park['category']."<br>";
			echo "<b>Rating:</b>".$park['rating']."</p>";
			echo "<script> var lat = ".$park['latitude'].";";
			echo "var long = ".$park['longitude'].";";
			echo "var name = \"".$park['name']."\";</script>";
	 }
	 
	 function display_map($search_data){
		 echo '<div class="googleMap" id="googleMap"></div>';	 
		 echo '<script>initMap();</script>';
		 
		 foreach($search_data as $park){	 	 
			echo '<script>addMarkerToMap('.$park['latitude'].','.$park['longitude'].
				',"'.$park['name'].'","item.php?id='.$park['parkid'].
				'","'.$park['rating'].'","'.$park['suburb'].
				'","'.$park['street'].'");</script>';
		 }
		 
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