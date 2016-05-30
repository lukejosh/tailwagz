<!DOCTYPE html>
<html>
<?php
// Include all necessary php files 
include "php/common.inc";

// Start the users session
session_start();
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TailWagz</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
	<!-- Header -->
	<?php include 'components/header.inc'; ?>
	<!-- Body -->
	<div id="body">
		<div id="homepage">
			<!-- if there is an error message, display it -->
			<?php display_error_message();?> 
			<img src="images/homepage.jpg" alt="">
			<!-- center-content is a container for the content which appears on top of the homepage image -->
			<div id="center-content">
				<h2>TailWagz</h2>
				<span>A central hub to search and review dog park facilities in and around Brisbane, Australia.</span>
				<a href="search.php" class="more">search</a>
				<!-- if the user is not signed in then display signin and signup buttons -->
				<?php if (!isset($_SESSION['isLoggedOn'])){ ?>
					<a href="signin.php" class="more">sign in</a>
					<a href="signup.php" class="more">sign up</a>
				<?php } ?>
			</div>
		</div>
		<!-- Categories provide links to pre-configured searches for each category -->
		<div id="categories">
			<h1>Popular Categories</h1>
			<a href="results.php?category=beach">
				<img src="images/dog-beach.jpg" alt="Dog on beach">
				<p>Beach</p>
			</a>
			<a href="results.php?category=friendly">
				<img src="images/dog-friendly.jpg" alt="Dogs playing together">
				<p>Friendly</p>
			</a>
			<a href="results.php?category=training">
				<img src="images/dog-training.jpg" alt="Dog playing fetch">
				<p>Training</p>
			</a>
			<a href="results.php?category=quiet">
				<img src="images/dog-quiet.jpg" alt="Empty dog park">
				<p>Quiet</p>
			</a>
			<a href="results.php?category=busy">
				<img src="images/dog-busy.jpg" alt="Lots of dogs">
				<p>Busy</p>
			</a>
			<a href="results.php?category=big">
				<img src="images/dog-big.jpg" alt="Large dog park">
				<p>Big</p>
			</a>
		</div>
	</div>
    <!-- Footer -->
    <?php include 'components/footer.inc'; ?>
</body>
</html>