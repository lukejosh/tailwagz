<?php
function get_all_parks(){
    $query = 'SELECT * FROM parks';
    return perform_sql_query($query, null);
}

function get_parks_by_location($lat, $long, $distance){
    $query = "SELECT * FROM parks WHERE haversine(latitude, longitude, ".$lat.", ".$long.") < ".$distance;

    return perform_sql_query($query, null);
}

function get_parks_by_rating($min){
    $query = "SELECT * FROM parks WHERE rating > $min";

    return perform_sql_query($query, null);
}

function get_parks_by_search($text){
    $lower_string = strtolower($text);
    $query = "SELECT * FROM parks WHERE parkid IN (SELECT parkID from reviews WHERE LOWER(message) LIKE \"%".$lower_string."%\") OR LOWER(name) LIKE \"%".$lower_string."%\"";

    return perform_sql_query($query, null);
}

function get_parks_by_category($category){
    $lower_string = strtolower($category);
    $query = "SELECT * FROM parks WHERE LOWER(category) LIKE \"%".$lower_string."%\"";

    return perform_sql_query($query, null);
}

function    get_search_results(){
    //$actual_unique = array_unique(array_values($_GET));
    //$compare_unique = array(0 => $_GET['distance'], 1 => "");
    //sort($actual_unique);
    //sort($compare_unique);

    if(empty($_GET)){
        // Checks that get exists and has values
        //echo "<script> alert(\"RETURNING ALL\");</script>";
        return get_all_parks();
    }
	
	if(!isset($_GET['distance']) || $_GET['distance'] == ""){
		$distance = 10;
	} else {
		$distance = htmlspecialchars($_GET['distance'], ENT_QUOTES, 'UTF-8');
	}

    foreach($_GET as $field => $value){
		$value = htmlspecialchars($value, ENT_QUOTES, 'UTF-8');
        if ($value != "" & $value != "distance"){
            if ($field == 'lat' && $_GET['lon'] != ""){
				$lon = htmlspecialchars($_GET['lon'], ENT_QUOTES, 'UTF-8');
                $result = get_parks_by_location($value, $lon, $distance);
				break;
            }
			
			if ($field == 'lon' && $_GET['lat'] != ""){
                $lat = htmlspecialchars($_GET['lat'], ENT_QUOTES, 'UTF-8');
                $result = get_parks_by_location($lat, $value, $distance);
				break;
            }

            else if ($field == 'rating') {
                $result = get_parks_by_rating($value);
				break;
            }

            else if ($field == 'search'){
                $result = get_parks_by_search($value);
				break;
            }

            else if ($field == 'category'){
                 $result = get_parks_by_category($value);
				 break;
            }
        }
		
    }

	if($result->rowCount() < 1){
		$_SESSION['errorMessage'] = 'No parks matched your search';
        header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/search.php?".$field."=".$value);
        exit();
	}
	
	return $result;
}

function display_results_table($results_data){
	
	echo '<table id="results">'.
        '<tr>'.
            '<th>Name</th>'.
            '<th>Location</th>'.
            '<th>Tags</th>'.
            '<th>Rating</th>'.
        '</tr>';
	
    foreach($results_data as $park){
        echo "<tr id=\"row\">";
        echo "<td ><a id='park_title' href=\"park.php?id=".$park['parkid']."\">".$park['name']."<a></td>";
        echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['suburb'].", ".$park['street']."<a></td>";
        echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['category']."<a></td>";
        echo "<td><a href=\"park.php?id=".$park['parkid']."\">".$park['rating']."<a></td>";
        echo "</tr>";
    }
	
	echo '</table>';
}
?>