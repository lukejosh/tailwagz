<!DOCTYPE html>
<html>
	<?php
		include "php/authentication.php";
		include "php/functions.php";
		session_start();

		$results_data = get_search_results()->fetchAll();
	?>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"> 
			var map;
			var bounds;
		</script>	
		<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false"></script>	
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<p id="title">Results</p>
			<?php display_error_message();?>
			<?php display_map($results_data);?>
			<table id="results">
				<tr>
				  <th>Name</th>
				  <th>Location</th>
				  <th>Tags</th>
				  <th>Rating</th>
				</tr>
				<?php display_results_rows($results_data)?>

<!-- 					<tr >
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
				</tr> -->
			</table>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>