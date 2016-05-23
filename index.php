<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>TailWagz</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>		
	</head>
	<body>
		<!-- Header-->
		<?php include 'components/header.inc'; ?> 
		<div id="body">
			<div id="homepage">
				<img src="images/homepage.jpg" alt="">
				<div id="center-content">
					<h2>TailWagz</h2>
					<span>A central hub to search and review dog park facilities in and around Brisbane, Australia.</span>
					<a href="search.php" class="more">search</a>
					<a href="login.php" class="more">log in</a>
					<a href="signup.php" class="more">sign up</a>
				</div>
			</div>
			<div id="categories">
				<h1>Popular Categories</h1>
				<a href="results.php">
					<img src="images/dog-beach.jpg" alt="">
					<p>Beach</p>
				</a>
				<a href="results.php">
					<img src="images/dog-friendly.jpg" alt="">
					<p>Friendly</p>
				</a>
				<a href="results.php">
					<img src="images/dog-training.jpg" alt="">
					<p>Training</p>
				</a>
				<a href="results.php">
					<img src="images/dog-quiet.jpg" alt="">
					<p>Quiet</p>
				</a>
				<a href="results.php">
					<img src="images/dog-busy.jpg" alt="">
					<p>Busy</p>
				</a>
				<a href="results.php">
					<img src="images/dog-big.jpg" alt="">
					<p>Big</p>
				</a>
				
			</div>
		<!-- Footer -->
		<?php include 'components/footer.inc'; ?>
	</body>
</html>