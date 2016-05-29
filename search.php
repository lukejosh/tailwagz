<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include "php/search.inc";
include "php/validate.inc";
session_start();
validate_all_search($_GET);
$distance = "1";
foreach($_GET as $field => $value){
	if($value != ""){
		if ($field == "distance"){
				$preset_distance = $value;
		}
	}
}
    $preset_distance = "";
    $preset_suburb = null;
    $preset_rating = "";
    $preset_category = "";
    $preset_search = "";
    foreach($_GET as $field => $value){
        if($value != ""){
            switch($field){
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
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dog Park Reviews</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
<?php include 'components/header.inc'; ?>
<div id="body">
    <p id="title">Search</p>
    <?php display_error_message();?>
    <form action="results.php">
        <a class="submit" id="location" onclick="user_location_link();"><p>Search By Location</p></a>
        <select name="distance" id="distance" onchange="revert_other_searches('distance')">
            <option value="1" <?php if($preset_distance == "1"){echo "selected";}?> >< 1km</option>
            <option value="5" <?php if($preset_distance == "5"){echo "selected";}?>>< 5km</option>
            <option value="10" <?php if($preset_distance == "10"){echo "selected";}?>>< 10km</option>
            <option value="20" <?php if($preset_distance == "20"){echo "selected";}?>>< 20km</option>
            <option value="50" <?php if($preset_distance == "50"){echo "selected";}?>>< 50km</option>
        </select>
        <p>or select one of the following</p>
        <select name="suburb" id="suburb" onchange="revert_other_searches('suburb')">
            <option value="">Select a suburb</option>
            <?php add_suburb_options($preset_suburb);?>
        </select>
        <select name="rating" id="rating" onchange="revert_other_searches('rating')">
            <option value="">Select a minimum rating</option>
            <option value="1" <?php if($preset_rating == "1"){echo "selected";}?>>> 1 Star</option>
            <option value="2" <?php if($preset_rating == "2"){echo "selected";}?>>> 2 Stars</option>
            <option value="3" <?php if($preset_rating == "3"){echo "selected";}?>>> 3 Stars</option>
            <option value="4" <?php if($preset_rating == "4"){echo "selected";}?>>> 4 Stars</option>
        </select>

        <select name="category" id="category" onchange="revert_other_searches('category')">
            <option value="">Select a category</option>
            <option value="beach" <?php if($preset_category == "beach"){echo "selected";}?>>Beach</option>
            <option value="friendly" <?php if($preset_category == "friendly"){echo "selected";}?>>Friendly</option>
            <option value="training" <?php if($preset_category == "training"){echo "selected";}?>>Training</option>
            <option value="quiet" <?php if($preset_category == "quiet"){echo "selected";}?>>Quiet</option>
            <option value="busy" <?php if($preset_category == "busy"){echo "selected";}?>>Busy</option>
            <option value="big" <?php if($preset_category == "big"){echo "selected";}?>>Big</option>
        </select>
        <input type="text" name="search" id="search" value="" placeholder="Keyword" onchange="revert_other_searches('search')">
        <input type="submit" class="submit" id="search_btn" value="Search">
    </form>

    <?php
    if (isset($_GET)){

    }
    ?>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>