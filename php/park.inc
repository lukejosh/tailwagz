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
	
	echo 	"<p><b>Dog Park Name:</b><span itemprop='name'>".$park['name']."</span><br>".
			"<span itemprop='address' itemscope itemtype='http://schema.org/PostalAddress'>".			
				"<b>Street:</b> <span itemprop='streetAddress'>".$park['street']."</span><br>".
				"<b>Suburb:</b> <span itemprop='addressLocality'>".$park['suburb']."</span><br>".
			"</span>".
			"<span itemprop='aggregateRating' itemscope itemtype='http://schema.org/AggregateRating'>".
				"<b>No. Reviews:</b> <span itemprop='ratingValue'>".$park['rating']."</span><br>".
				"<b>Rating:</b> <span itemprop='reviewCount'>".$park['rating']."</span><br>".
			"</span>".
			"<b>Tags:</b> ".$park['category']."<br>".
			"<div itemprop='geo' itemscope itemtype='http://schema.org/GeoCoordinates'>".
				"<meta itemprop='latitude' content='40.75' />".
				"<meta itemprop='longitude' content='73.98' />".
			"</div>";
	
    echo 	"<script> var lat = ".$park['latitude'].";".
				"var long = ".$park['longitude'].";".
				"var name = \"".$park['name']."\";".
			"</script>";
}

function display_reviews($review_data){
    if(is_null($review_data)){
        echo '<p class="error">There are no reviews for this park</p>';
    } else {
        foreach($review_data as $review){
            $dateText = date("d M Y", strtotime($review['dateCreated']));
            $datePublished = date("y-m-d", strtotime($review['dateCreated']));
			
			echo 	"<div itemprop='review' itemscope itemtype='http://schema.org/Review'>".
						"<p>".
							"<b><span id='reviewRating' itemprop='reviewRating' itemscope itemtype='http://schema.org/Rating'>".
								"<span itemprop='ratingValue'>".$review['rating']."</span> out of ".
								"<span itemprop='bestRating'>5</span> stars".
							"</span></b> - ".
							"\"<i><span itemprop='name'>".$review['message']."</span></i>\" - ".						
							"<b><span itemprop='author'>".$review['username']."</span></b> ".
							"on ".$dateText."<br>".
							"<meta itemprop='datePublished' content=".$datePublished.">".
						"</p>".
					"</div>";
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