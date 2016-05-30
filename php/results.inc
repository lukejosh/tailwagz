<?php
	// Function:  get_all_parks()
	// Description: a function to get all parks in the database
	// Input: none 
	// Output: all parks
	function get_all_parks(){
		$query = 'SELECT * FROM parks';
		return perform_sql_query($query, null);
	}

	// Function:  get_parks_by_location($lat, $long, $distance)
	// Description: a function to get all parks by location
	// Input: users latitude and longitude as well as the maximum distance
	// Output: all parks within the maximum distance
	function get_parks_by_location($lat, $long, $distance){
		$query = "SELECT * FROM parks WHERE haversine(latitude, longitude, ".$lat.", ".$long.") < ".$distance;

		return perform_sql_query($query, null);
	}

	// Function:  get_parks_by_rating($min)
	// Description: a function to get all parks by rating
	// Input: minimum allowable rating
	// Output: all parks with a rating greater than the minimum rating
	function get_parks_by_rating($min){
		$query = "SELECT * FROM parks WHERE rating > $min";

		return perform_sql_query($query, null);
	}

	// Function:  get_parks_by_search($text)
	// Description: a function to get all parks by a keyword(s)
	// Input: the keyword(s)
	// Output: all parks matching the keyword(s)
	function get_parks_by_search($text){
		$lower_string = strtolower($text);
		$query = "SELECT * FROM parks WHERE parkid IN (SELECT parkID from reviews WHERE LOWER(message) LIKE \"%".$lower_string."%\") OR LOWER(name) LIKE \"%".$lower_string."%\"";

		return perform_sql_query($query, null);
	}

	// Function:  get_parks_by_category($category)
	// Description: a function to get all parks by a category
	// Input: the category
	// Output: all parks matching the category
	function get_parks_by_category($category){
		$lower_string = strtolower($category);
		$query = "SELECT * FROM parks WHERE LOWER(category) LIKE \"%".$lower_string."%\"";

		return perform_sql_query($query, null);
	}

	// Function:  get_parks_by_suburb($suburb)
	// Description: a function to get all parks by a suburb
	// Input: the suburb
	// Output: all parks matching the suburb
	function get_parks_by_suburb($suburb){
		$lower_string = strtolower($suburb);
		$query = "SELECT * FROM parks WHERE LOWER(suburb) = \"".$lower_string."\"";

		return perform_sql_query($query, null);
	}

	// Function:  get_search_results(){
	// Description: a complex function to get search results based on the set GET request parameters
	// Input: none
	// Output: all parks matching the search parameters
	function    get_search_results(){

		if(empty($_GET)){
			// if the search has no parameters then return all parks
			return get_all_parks();
		}
		
		
		if(!isset($_GET['distance']) || $_GET['distance'] == ""){
			// If the distance is not set then set it to 10km
			$distance = 10;
		} else {
			// Else set it to the required distance
			$distance = htmlspecialchars($_GET['distance'], ENT_QUOTES, 'UTF-8');
		}

		// loop through each field of the GET request
		foreach($_GET as $field => $value){
			$value = htmlspecialchars($value, ENT_QUOTES, 'UTF-8');
			
			// If the value is not empty and is not the distance parameter
			if ($value != "" & $value != "distance"){
				
				// If the set field is lat and lon is not empty
				if ($field == 'lat' && $_GET['lon'] != ""){
					// Then get parks by distance
					$lon = htmlspecialchars($_GET['lon'], ENT_QUOTES, 'UTF-8');
					$result = get_parks_by_location($value, $lon, $distance);
					break;
				}
				
				// If the set field is lon and lat is not empty
				else if ($field == 'lon' && $_GET['lat'] != ""){
					// Then get parks by distance
					$lat = htmlspecialchars($_GET['lat'], ENT_QUOTES, 'UTF-8');
					$result = get_parks_by_location($lat, $value, $distance);
					break;
				}

				// If the set field is rating
				else if ($field == 'rating') {
					$result = get_parks_by_rating($value);
					break;
				}

				// If the set field is keyword search 
				else if ($field == 'search'){
					$result = get_parks_by_search($value);
					break;
				}

				// If the set field is category
				else if ($field == 'category'){
					 $result = get_parks_by_category($value);
					 break;
				}

				// If the set field is suburb
				else if ($field == 'suburb'){
					$result = get_parks_by_suburb($value);
					break;
				}
			}

			// if the code reaches this point (none of the above conditions are met)
			if (!isset($result)){
				// Then get all parks
				$result = get_all_parks();
			}
			
		}

		// If any of the above searches return no results
		if($result->rowCount() < 1){
			// then set an error message and return to the search page
			$_SESSION['errorMessage'] = 'No parks matched your search';
			header("Location: ".get_base_url()."/search.php?".$field."=".$value);
			exit();
		}
		
		return $result;
	}

	
	// Function:  display_results_table($results_data)
	// Description: a function to display the search results in a tabular format
	// Input: the search results
	// Output: none
	function display_results_table($results_data){
		// Start the table and set all of the headings
		echo '<table id="results">'.
			'<tr>'.
				'<th>Name</th>'.
				'<th>Location</th>'.
				'<th>Tags</th>'.
				'<th>Rating</th>'.
			'</tr>';
		
		// For each park in the search results , add a table row
		foreach($results_data as $park){
			echo "<tr id=\"row\">";
			echo "<td ><a id='park_title' href=\"park.php?id=".$park['parkid']."\">".$park['name']."<a></td>";
			echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['suburb'].", ".$park['street']."<a></td>";
			echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['category']."<a></td>";
			echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['rating']."<a></td>";
			echo "</tr>";
		}
		
		// Close the table
		echo '</table>';
	}
?>