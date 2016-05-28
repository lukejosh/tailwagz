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
    $actual_unique = array_unique(array_values($_GET));
    $compare_unique = array(0 => $_GET['distance'], 1 => "");
    sort($actual_unique);
    sort($compare_unique);

    if(empty($_GET) | $actual_unique == $compare_unique){
        // Checks that get exists and has values
        return get_all_parks();
    }

    foreach($_GET as $field => $value){
        if ($value != "" & $value != "distance"){
            if ($field == 'lat' or $field == 'lon'){
                return get_parks_by_location($_GET['lat'], $_GET['lon'], $_GET['distance']);
                // Need to add a check for if both lat and long are set
                // Will cause issues if one is not set
            }

            else if ($field == 'rating') {
                return get_parks_by_rating($value);
            }

            else if ($field == 'search'){
                return get_parks_by_search($value);
            }

            else if ($field == 'category'){
                return get_parks_by_category($value);
            }
        }
    }
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