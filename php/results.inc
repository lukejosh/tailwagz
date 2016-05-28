<?php
	function get_all_parks(){
		$query = 'SELECT * FROM parks';
		return perform_sql_query($query, null);
	 }
	 
	 function get_parks_by_location($lat, $long, $distance){
		$query = "SELECT * FROM parks WHERE haversine(latitude, longitude, ".$lat.", ".$long.") < ".$distance;
		
		return perform_sql_query($query, null);
	}
	 
	 function get_search_results(){
		//Need to add logic to this to support the different types of searches
		
		if(is_null($_GET)){
			return get_all_parks();
		}
		
		while($value = current($_GET)){
			$field = key($_GET);
			
			if ($value != ""){
				if ($field == 'lat' or $field == 'lon'){
					return get_parks_by_location($_GET['lat'], $_GET['lon'], 10);
					// Need to add a check for if both lat and long are set
					// Will cause issues if one is not set
				}
				
				$query = "SELECT * FROM parks WHERE $field LIKE '%$value%'";
				return perform_sql_query($query, null);
			}
			next($_GET);
		}
		
		return get_all_parks();	// 	Caters for if all form parameter are empty
	 }
	 
	 function display_results_rows($results_data){
		foreach($results_data as $park){
			echo "<tr id=\"row\">";
				echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['name']."<a></td>";
				echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['suburb'].", ".$park['street']."<a></td>";
				echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['category']."<a></td>";
				echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['rating']."<a></td>";
			echo "</tr>";
		}
	 }
?>