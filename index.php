<!DOCTYPE html>
<html>
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
			<div id="homepage">
				<img src="images/homepage.jpg" alt="">
				<div>
					<h2>The dog park reviewer</h2>
					<span>A central hub to search and review dog park facilities</span>
					<span>in and around Brisbane, Australia.</span><br>
					<a href="search.php" class="more">search</a>
					<a href="login.php" class="more">log in</a>
					<a href="signup.php" class="more">sign up</a>
				</div>
			<br><h1><span>Popular Categories</span></h1>
			</div id="categories">
				<ul>
					<li>
						<a href="results.php">
							<img src="images/dog-beach.jpg" alt="">
							<span>Beach</span>
						</a>
					</li>
					<li>
						<a href="results.php">
							<img src="images/dog-friendly.jpg" alt="">
							<span>Friendly</span>
						</a>
					</li>
					<li>
						<a href="results.php">
							<img src="images/dog-training.jpg" alt="">
							<span>Training</span>
						</a>
					</li>
				</ul>
				<ul>
					<li>
						<a href="results.php">
							<img src="images/dog-quiet.jpg" alt="">
							<span>Quiet</span>
						</a>
					</li>
					<li>
						<a href="results.php">
							<img src="images/dog-busy.jpg" alt="">
							<span>Busy</span>
						</a>
					</li>
					<li>
						<a href="results.php">
							<img src="images/dog-big.jpg" alt="">
							<span>Big</span>
						</a>
					</li>
				</ul>
			</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>