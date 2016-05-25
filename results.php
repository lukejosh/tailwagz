<!DOCTYPE html>
<html>
	<?php
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
			<p id="title">Results</p>
			<div id="googleMap"></div>
			<div class="results">
				<table>
					<tr>
					  <th>Name</th>
					  <th>Location</th>
					  <th>Tags</th>
					  <th>Rating</th>
					</tr>
					<tr >
						  <td><a href="item.php">7TH BRIGADE PARK<a></td>
						  <td><a href="item.php">HAMILTON RD,CHERMSIDE<a></td>
						  <td><a href="item.php">Busy, Friendly<a></td>
						  <td><a href="item.php">8<a></td>
					</tr>
					<tr >
						  <td><a href="item.php">ABBEVILLE STREET PARK<a></td>
						  <td><a href="item.php">ABBEVILLE ST,UPR MT GRAVATT<a></td>
						  <td><a href="item.php">Quiet<a></td>
						  <td><a href="item.php">2<a></td>
					</tr>
					<tr >
						  <td><a href="item.php">ALBERT BISHOP PARK<a></td>
						  <td><a href="item.php">HEDLEY AVE,NUNDAH<a></td>
						  <td><a href="item.php">Big, Training<a></td>
						  <td><a href="item.php">5<a></td>
					</tr>
				</table>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>