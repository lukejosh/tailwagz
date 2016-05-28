`<!DOCTYPE html>
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
		<script
			src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false">
		</script>
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<p id="title">Results</p>
			<div id="googleMap" class="googleMap"></div> <!-- Placeholder for the Google Map element -->
			<div class="results">
				<table>
					<tr>
					  <th>Name</th>
					  <th>Location</th>
					  <th>Tags</th>
					  <th>Rating</th>
					</tr>

					<?php
					include 'php/functions.php';

					foreach($_GET as $key => $value){ //Find used GET parameter - i.e., what was searched by
						if ($value != ""){
							break;
						}
					}
					if ($key == 'lat' or $key == 'lon'){
						$results = get_parks_near_user($_GET['lat'], $_GET['lon'], 2);
					}
					else{
						$results = query_park_column($key, $value);
					}

					foreach($results as $park){ //Create table containing parks
						echo "<tr>";
							echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['name']."<a></td>";
							echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['suburb'].", ".$park['street']."<a></td>";
							echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['category']."<a></td>";
							echo "<td><a href=\"item.php?id=".$park['parkid']."\">".$park['rating']."<a></td>";
						echo "</tr>";

					}

					?>
				</table>
			<div>
 				<script> //Create google map with all results
					var lat = <?php echo $_GET['lat']; ?>;
					var lon = <?php echo $_GET['lon']; ?>;
					initMap(lat, lon, "Your Location");
					<?php
					// echo "console.log(".$results[0]['latitude'].")";
						foreach($results as $park){
							
							echo "addMarker(".$park['latitude'].", ".$park['longitude'].", \"".$park['name']."\");";
						}
					?>
				</script>
			</div>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>