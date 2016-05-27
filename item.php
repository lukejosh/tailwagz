<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>	
		<script
			src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false">
		</script>		
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
		<div>
			<?php
				include 'php/functions.php';
				$result = get_park_by_id($_GET['id']);
				foreach($result as $semantics){
					echo "<p id=\"title\">".$semantics['name']."</p>";
					echo "<div class=\"text\">";
					echo "<p>Dog Park Name: ".$semantics['name']."<br>";
					echo "Street: ".$semantics['street']."<br>";
					echo "Suburb: ".$semantics['suburb']."<br>";
					echo "Tags: ".$semantics['category']."<br>";
					echo "Rating: <b>".$semantics['rating']."</b></p>";
					echo "<script> var lat = ".$semantics['latitude'].";</script>";
					echo "<script> var long = ".$semantics['longitude'].";</script>";
					echo "<script> var name = \"".$semantics['name']."\";</script>";
				}
			?>
			</div>
		<div>
			<div class="googleMap" id="googleMap"></div>
			<script>
				initMap(lat, long, name);
			</script>
			<div class="text" id="reviews">
				<h1>Reviews</h1>
				<p><b>8 out of 10</b> - <i>"Great park! Loads of friendly dogs. Usually busy around 5pm." - Jane Smith</i><p>	
				<p><b>4 out of 10</b> - <i>"Too Busy! Not a good spot for smaller dogs. Always a ton of bigger dogs" - Barbra Hurtbum</i><p>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>