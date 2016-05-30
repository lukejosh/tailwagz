<!DOCTYPE html>
<html>
<?php
// Include all necessary php files
include "php/common.inc";
include "php/park.inc";

// Start the users session
session_start();

// If the user had posted a review
if (isset($_POST['submit_review'])) {
	// Then add the review
    add_review($_POST);
}

// Get all park data
$park_data = get_park_by_id($_GET['id'])->fetchAll();

// Get all reviews data
$reviews_data = get_reviews_by_id($_GET['id']);
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
    <script
        src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false">
    </script>
</head>
<body>
	<div id="body">
		<!-- Header -->
		<?php include 'components/header.inc';
		// Body
		echo "<p id=\"title\">".$park_data[0]['name']."</p>";
		// If there is an error message then display it
		display_error_message();
		// display the map with the park data as a marker on it 
		display_map($park_data);
		?>
		<!-- Add micro data tag for a Place -->
		<div itemscope itemtype='http://schema.org/Place'>
			<div class="text">
				<!-- Display the park infomation -->
				<?php echo display_park_info($park_data); ?>
			</div>
			<!-- If the user is logged on then let them create reviews -->
			<?php if (isset($_SESSION['isLoggedOn']))
			{?>
				<div class="form">
					<form id="submit_review" action="park.php?id=<?php echo $_GET['id']; ?>" method="post" >
						<input type="hidden" name="parkID" id="parkID" value="<?php echo $_GET['id']; ?>">
						<span>Review message</span>
						<input type="text" name="message" id="message" placeholder="Review Message" required/>
						<span>Review rating</span>
						<select name="rating" id="rating">
							<option value="">Select a rating</option>
							<option value="1">1 Star</option>
							<option value="2">2 Stars</option>
							<option value="3">3 Stars</option>
							<option value="4">4 Stars</option>
							<option value="5">5 Stars</option>
						</select>
						<span>Suitable park category</span>
						<select name="category" id="category">
							<option value="">Select a suitable category</option>
							<option value="Beach">Beach</option>
							<option value="Friendly">Friendly</option>
							<option value="Training">Training</option>
							<option value="Quiet">Quiet</option>
							<option value="Busy">Busy</option>
							<option value="Big">Big</option>
						</select>
						<input type="submit" class="submit" name="submit_review" id="submit_review" value="Add Review"/>
					</form>
				</div>
			<?php } ?>
			<div class="text" id="reviews">
				<h1>Reviews</h1>
				<!-- display all the reviews for the park -->
				<?php display_reviews($reviews_data); ?>
			</div>
		</div>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>