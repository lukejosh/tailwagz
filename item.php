<!DOCTYPE html>
<html>
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
			<h1><span>7TH BRIGADE PARK</span></h1>
			<div class="item">
				<p>Dog Park Name: REINHOLD CRES DOG OFF LEASH AREA</p>
				<p>Park Code: D0228</p>
				<p>Street: HAMILTON RD</p>
				<p>Suburb: CHERMSIDE</p>
				<p>Size: 10000m<sup>2</sup></p>
				<p>Tags: Busy, Friendly</p>
				<p>Rating: <b>8 out of 10</p>
			</div>
			<div id="googleMap"></div>
			<div class="reviews">
				<h2>Reviews</h2>
				<div class="review">
						<p><b>8 out of 10</b> - <i>"Great park! Loads of friendly dogs. Usually busy around 5pm." - Jane Smith</i><p>	
				</div>
				<div class="review">
						<p><b>4 out of 10</b> - <i>"Too Busy! Not a good spot for smaller dogs. Always a ton of bigger dogs" - Barbra Hurtbum</i><p>	
				</div>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>