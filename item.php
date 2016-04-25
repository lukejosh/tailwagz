<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>		
		<script src="http://maps.googleapis.com/maps/api/js"></script>
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body" onload="initMap(-27.38123113, 153.0436597, 7TH BRIGADE PARK)">
			<h1><span>Item</span></h1>
			<div>
			<div id="map" ></div>
			<div class="article">
				<h2>7TH BRIGADE PARK</h2>
				<p>
				Dog Park Name: REINHOLD CRES DOG OFF LEASH AREA<br>
				Park Code: D0228<br>
				Street: HAMILTON RD<br>
				Suburb: CHERMSIDE<br>
				Size: 10000m^2<br>
				Location: -27.38123113,153.0436597<br>
				</p>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>