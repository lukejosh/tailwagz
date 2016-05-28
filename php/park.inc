<?php

function get_park_by_id($parkID){
    $query = "SELECT * from parks WHERE parkID = ".$parkID;
    $result = perform_sql_query($query, null);
    return $result;
}

function get_reviews_by_id($parkID){
    $query = 'SELECT * FROM reviews '.
        'WHERE parkID=:parkID '.
        'ORDER BY dateCreated DESC';
    $parameters['parkID'] = htmlspecialchars($parkID, ENT_QUOTES, 'UTF-8');

    $result = perform_sql_query($query, $parameters);

    if ($result->rowCount() > 0){
        return $result;
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

function display_reviews($review_data){
    if(is_null($review_data)){
        echo '<p class="error">There are no reviews for this park</p>';
    } else {
        foreach($review_data as $review){
            $timestamp = date("d M Y", strtotime($review['dateCreated']));
            echo '<p><b>'.$review['rating'].' out of 5</b> - <i>"'.$review['message'].'"</i> - <b>'.$review['username'].'</b> on '.$timestamp.'<br></p>';
        }
    }
}

function add_review(array $data){
    $username = $_SESSION['username'];
    $parkID = htmlspecialchars($data['parkID'], ENT_QUOTES, 'UTF-8');
    $message = htmlspecialchars($data['message'], ENT_QUOTES, 'UTF-8');
    $rating = htmlspecialchars($data['rating'], ENT_QUOTES, 'UTF-8');
    $category = htmlspecialchars($data['category'], ENT_QUOTES, 'UTF-8');

    if(is_previous_review($parkID, $username)){
        update_previous_review($parkID, $username, $message, $rating, $category);
        $_SESSION['errorMessage'] = 'You have already reviewed this park<br>'.
            'Your previous review has been updated';

    }else{
        create_new_review($parkID, $username, $message, $rating, $category);
    }

    update_park_info($parkID);
}

function is_previous_review($parkID, $username){
    $query = 'SELECT * FROM reviews '.
        'WHERE parkID = :parkID and username = :username';

    $parameters['parkID'] = $parkID;
    $parameters['username'] = $username;

    $result = perform_sql_query($query, $parameters);

    if ($result->rowCount() > 0){
        return true;
    }

    return false;
}

function update_previous_review($parkID, $username, $message, $rating, $category){
    $query = 'UPDATE reviews '.
        'SET message = :message, rating = :rating, '.
        'category = :category '.
        'WHERE parkID = :parkID and username = :username';

    $parameters['parkID'] = $parkID;
    $parameters['username'] = $username;
    $parameters['message'] = $message;
    $parameters['rating'] = intval($rating);
    $parameters['category'] = $category;

    $result = perform_sql_query($query, $parameters);
}

function create_new_review($parkID, $username, $message, $rating, $category){
    $query = ''.
        'INSERT INTO reviews (parkID, username, message, rating, category) '.
        'VALUES(:parkID, :username, :message, :rating, :category)';

    $parameters['parkID'] = intval($parkID);
    $parameters['username'] = $username;
    $parameters['message'] = $message;
    $parameters['rating'] = intval($rating);
    $parameters['category'] = $category;

    $result = perform_sql_query($query, $parameters);
}

function update_park_info($parkID){
    $query = 'UPDATE parks '.
        'SET rating= :rating, '.
        'category= :category '.
        'WHERE parkid= :parkid ';
    $rating = 0.0;
    $number_of_reviews = 0.0;
    $reviews = get_reviews_by_id($parkID);
    $category = " ";

    foreach($reviews as $review){
        $number_of_reviews += 1;
        $rating += intval($review['rating']);

        if ($review['category'] != "" && strpos($category, $review['category']) == false){
            if ($category == " "){
                $category .= $review['category'];
            } else {
                $category .= ", ".$review['category'];
            }
        }
    }

    $rating = $rating / $number_of_reviews;

    $parameters['parkid'] = intval($parkID);
    $parameters['rating'] = intval($rating);
    $parameters['category'] = $category;

    $result = perform_sql_query($query, $parameters);
}

?>