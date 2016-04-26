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
			<div class="article">
				<p><br>
				Dog Park Name: REINHOLD CRES DOG OFF LEASH AREA<br>
				Park Code: D0228<br>
				Street: HAMILTON RD<br>
				Suburb: CHERMSIDE<br>
				Size: 10000m^2<br>
				Rating: 7/10 Stars 
				</p>
			</div>
			<div id="googleMap"></div>
			<div class="reviews">
				<h2>Reviews</h2>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>