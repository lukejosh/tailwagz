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

function    get_search_results(){
    if(empty($_GET) | array_unique(array_values($_GET)) == array(0 => "")){
        // Checks that get exists and has values
        echo "<script> alert(\"RETURNING ALL\");</script>";
        return get_all_parks();
    }

    foreach($_GET as $field => $value){
        if ($value != ""){
            if ($field == 'lat' or $field == 'lon'){
                return get_parks_by_location($_GET['lat'], $_GET['lon'], 10);
                // Need to add a check for if both lat and long are set
                // Will cause issues if one is not set
            }

            else if ($field == 'rating') {
                return get_parks_by_rating($value);
            }

            else if ($field == 'search'){
                return get_parks_by_search($value);
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