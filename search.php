<!DOCTYPE html>
<html>
<?php
// Include all necessary php files 
include "php/common.inc";
include "php/search.inc";
include "php/validate.inc";

// Start the users session
session_start();

// Set all pre-set search field to empty
$preset_distance = "";
$preset_suburb = null;
$preset_rating = "";
$preset_category = "";
$preset_search = "";

if (!empty($_GET)) {
// Validate the search by validating all fields of the GET request
	validate_all_search();

	if (isset($_SESSION['errorMessage'])) { //Error in the previous search, fill out old values
		// Loop through each search field in the GET request
		foreach ($_GET as $field => $value) {
			// If the field is not empty then set the corresponding pre-set variable to the field value
			if ($value != "") {
				switch ($field) {
					case "distance":
						$preset_distance = $value;
						break;
					case "suburb":
						$preset_suburb = $value;
						break;
					case "rating":
						$preset_rating = $value;
						break;
					case "category":
						$preset_category = $value;
						break;
					case "search":
						$preset_search = $value;
						break;
				}
			}
		}
	} else { // Send results to the results page
		$get_string = "?";
		foreach ($_GET as $field => $value) {
			$get_string = $get_string . $field . "=" . $value . "&";
		}

		header("Location: " . get_base_url() . "/results.php" . $get_string);
	}
}
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dog Park Reviews</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
	<!-- Header -->
	<?php include 'components/header.inc'; ?>
	<!-- Body -->
	<div id="body">
		<p id="title">Search</p>
		<!-- if there is an error message, display it -->
		<?php display_error_message();?> 
		<form action="search.php">
			<!-- Search by location button and distance option section -->
			<h2>Search by location</h2>
			<p>Select a maximum distance</p>
			<select name="distance" id="distance" onchange="revert_other_searches('distance')">
				<!-- For each option if value was previously selected then select it again -->
				<option value="1" <?php if($preset_distance == "1"){echo "selected";}?>> &lt; 1km</option>
				<option value="5" <?php if($preset_distance == "5"){echo "selected";}?>> < &lt; </option>
				<option value="10" <?php if($preset_distance == "10"){echo "selected";}?>> &lt; 10km</option>
				<option value="20" <?php if($preset_distance == "20"){echo "selected";}?>> &lt; 20km</option>
				<option value="50" <?php if($preset_distance == "50"){echo "selected";}?>> &lt; 50km</option>
			</select>
			<a  id="location" onclick="user_location_link();"><span>Search By Location</span></a>
			<!-- Search by suburb, rating, category and keyword section -->
			<h2>Or select one of the following</h2>
			<span>Select a suburb</span>
			<select name="suburb" id="suburb" onchange="revert_other_searches('suburb')">
				<option value="">Select a suburb</option>
				<!-- Use function to retrieve all suburbs for database and populate the suburb option field -->
				<?php add_suburb_options($preset_suburb);?>
			</select>
			<span>Select a minimum rating</span>
			<select name="rating" id="rating" onchange="revert_other_searches('rating')">
				<option value="">Select a minimum rating</option>
				<!-- For each option if value was previously selected then select it again -->
				<option value="1" <?php if($preset_rating == "1"){echo "selected";}?>>&gt; 1 Star</option>
				<option value="2" <?php if($preset_rating == "2"){echo "selected";}?>>&gt; 2 Stars</option>
				<option value="3" <?php if($preset_rating == "3"){echo "selected";}?>>&gt; 3 Stars</option>
				<option value="4" <?php if($preset_rating == "4"){echo "selected";}?>>&gt; 4 Stars</option>
			</select>
			<span>Select a park category</span>
			<select name="category" id="category" onchange="revert_other_searches('category')">
				<option value="">Select a category</option>
				<!-- For each option if value was previously selected then select it again -->
				<option value="beach" <?php if($preset_category == "beach"){echo "selected";}?>>Beach</option>
				<option value="friendly" <?php if($preset_category == "friendly"){echo "selected";}?>>Friendly</option>
				<option value="training" <?php if($preset_category == "training"){echo "selected";}?>>Training</option>
				<option value="quiet" <?php if($preset_category == "quiet"){echo "selected";}?>>Quiet</option>
				<option value="busy" <?php if($preset_category == "busy"){echo "selected";}?>>Busy</option>
				<option value="big" <?php if($preset_category == "big"){echo "selected";}?>>Big</option>
			</select>
			<span>Search by keyword</span>
			<input type="text" name="search" id="search" value="<?php echo $preset_search; ?>"  placeholder="Keyword" onchange="revert_other_searches('search')">
			<input type="submit" class="submit" id="search_btn" value="Search">
		</form>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>