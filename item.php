<!DOCTYPE html>
<html>
	<?php
		include "php/authentication.php";
		include "php/functions.php";
		session_start();	
	?>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>	
		<script async defer
			src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false&callback=initMap">
		</script>		
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body" onload="initMap()">
		<div>
			<p id="title">7TH BRIGADE PARK</p>
			<div class="text">
				<p>Dog Park Name: REINHOLD CRES DOG OFF LEASH AREA<br>
				Park Code: D0228<br>
				Street: HAMILTON RD<br>
				Suburb: CHERMSIDE<br>
				Size: 10000m<sup>2</sup><br>
				Tags: Busy, Friendly<br>
				Rating: <b>8 out of 10</b></p>
			</div>
		<div>
			<div class="googleMap" id="googleMap"></div>
			<div class="text" id="reviews">
				<h1>Reviews</h1>
				<p><b>8 out of 10</b> - <i>"Great park! Loads of friendly dogs. Usually busy around 5pm." - Jane Smith</i><p>	
				<p><b>4 out of 10</b> - <i>"Too Busy! Not a good spot for smaller dogs. Always a ton of bigger dogs" - Barbra Hurtbum</i><p>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>