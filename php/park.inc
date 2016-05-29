<?php
	// Function:  get_park_by_id($parkID)
	// Description: a function to get park by its id
	// Input: park id
	// Output: park data
	function get_park_by_id($parkID){
		$query = "SELECT * from parks WHERE parkID = ".$parkID;
		$result = perform_sql_query($query, null);
		return $result;
	}

	// Function:  get_previews_by_id($parkID)
	// Description: a function to get reviews for park by its id
	// Input: park id
	// Output: park review data
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

	// Function:  display_park_info($search_data)
	// Description: a function to display the park information
	// Input: the parks data from sql query
	// Output: none
	function display_park_info($search_data){
		$park = $search_data[0];
		
		// echo the parks data including mirco-data and meta-data
		echo 	"<p><b>Dog Park Name: </b><span itemprop='name'>".$park['name']."</span><br>".
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

	// Function:  display_reviews($review_data)
	// Description: a function to display the parks reviews
	// Input: the parks review data
	// Output: none
	function display_reviews($review_data){
		
		// if there are no reviews
		if(is_null($review_data)){
			// the print a message
			echo '<p class="error">There are no reviews for this park</p>';
		} else {
			// Loop through each review
			foreach($review_data as $review){
				// Change date into an acceptable format
				$dateText = date("d M Y", strtotime($review['dateCreated']));
				$datePublished = date("y-m-d", strtotime($review['dateCreated']));
				
				// Echo out the review including mirco-data and meta-data
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

	// Function:  add_review(array $data)
	// Description: a function to add a review to the database
	// Input: the new review data
	// Output: none
	function add_review(array $data){
		// remove and cross site scripting
		$username = $_SESSION['username'];
		$parkID = htmlspecialchars($data['parkID'], ENT_QUOTES, 'UTF-8');
		$message = htmlspecialchars($data['message'], ENT_QUOTES, 'UTF-8');
		$rating = htmlspecialchars($data['rating'], ENT_QUOTES, 'UTF-8');
		$category = htmlspecialchars($data['category'], ENT_QUOTES, 'UTF-8');

		// If the user has already created a review
		if(is_previous_review($parkID, $username)){
			// Update previous review
			update_previous_review($parkID, $username, $message, $rating, $category);
			$_SESSION['errorMessage'] = 'You have already reviewed this park<br>'.
				'Your previous review has been updated';

		}else{
			// Otherwise create a new review
			create_new_review($parkID, $username, $message, $rating, $category);
		}

		// Finally update the parks info based on the new values of the review
		update_park_info($parkID);
	}

	// Function:  is_previous_review($parkID, $username)
	// Description: a function to check if a user has alredy created a reivew for that park
	// Input: the park id and username
	// Output: boolean, true if user has created a previous review
	function is_previous_review($parkID, $username){
		$query = 'SELECT * FROM reviews '.
			'WHERE parkID = :parkID and username = :username';

		$parameters['parkID'] = $parkID;
		$parameters['username'] = $username;

		$result = perform_sql_query($query, $parameters);

		// If database contains more than 1 result then return true
		if ($result->rowCount() > 0){
			return true;
		}

		return false;
	}

	// Function:  update_previous_review($parkID, $username, $message, $rating, $category)
	// Description: a function to update a users previous review
	// Input: the parkID, username, message, rating and category
	// Output: none
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

	// Function:  create_new_review($parkID, $username, $message, $rating, $category)
	// Description: a function to create a new review
	// Input: the parkID, username, message, rating and category
	// Output: none
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

	// Function:  create_new_review($parkID, $username, $message, $rating, $category)
	// Description: a function to update a parks rating and categories
	// Input: the parkID
	// Output: none
	function update_park_info($parkID){
		$query = 'UPDATE parks '.
			'SET rating= :rating, '.
			'category= :category '.
			'WHERE parkid= :parkid ';
		$rating = 0.0;
		$number_of_reviews = 0.0;
		$reviews = get_reviews_by_id($parkID);
		$category = " ";

		// Loop through each review
		foreach($reviews as $review){
			// Add rating onto a total
			$number_of_reviews += 1;
			$rating += intval($review['rating']);

			// If the categories field of the park does not contain the category of the review
			if ($review['category'] != "" && strpos($category, $review['category']) == false){
				// Then add the category to the parks categories
				if ($category == " "){
					$category .= $review['category'];
				} else {
					$category .= ", ".$review['category'];
				}
			}
		}

		// Average the rating total
		$rating = $rating / $number_of_reviews;

		// Bind the paarmeters
		$parameters['parkid'] = intval($parkID);
		$parameters['rating'] = intval($rating);
		$parameters['category'] = $category;

		// Perform the update
		$result = perform_sql_query($query, $parameters);
	}

?>