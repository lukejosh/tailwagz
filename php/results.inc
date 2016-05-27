<?php
	function get_all_parks(){
		$pdo = get_sql_connector_aws();
		$query = 'SELECT * FROM parks';
		return perform_sql_query($pdo, $query, null);
	 }
	 
	 function get_search_results(){
		//Need to add logic to this to support the different types of searches
		$pdo = get_sql_connector_aws();
		
		if(is_null($_GET)){
			return get_all_parks();
		}
		
		while($value = current($_GET)){
			if ($value != ""){		
				$field = key($_GET);
				$query = "SELECT * FROM parks WHERE $field LIKE '%$value%'";
				return perform_sql_query($pdo, $query, null);
			}
			next($_GET);
		}		
		
		return get_all_parks();	// 	Caters for if all form parameter are emppty
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