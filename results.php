<!DOCTYPE html>
<html>
<?php
// Include all necessary php files 
include "php/common.inc";
include "php/results.inc";
include "php/validate.inc";

// Start the users session
session_start();
session_id();

// Remove all scripts from the search GET parameters
$_GET = remove_scripts($_GET);

// Validate the search parameters
validate_all_search();

// Get the results for the search
$results_data = get_search_results()->fetchAll();
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dog Park Reviews</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
    <script type="text/javascript" src="js/javascript.js">
		// These variables are global variables used for the map
        var map;
        var bounds;
    </script>
    <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false"></script>
</head>
<body>
	<!-- Header -->
	<?php include 'components/header.inc'; ?>
	<!-- Body -->
	<div id="body">
		<p id="title">Results</p>
		<!-- if there is an error message, display it -->
		<?php display_error_message();?> 
		<!-- display the map with search results added as markers -->
		<?php display_map($results_data);?>
		<!-- display search results in a table -->
		<?php display_results_table($results_data)?>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>