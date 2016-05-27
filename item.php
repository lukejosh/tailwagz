<!DOCTYPE html>
<html>
	<?php
		include "php/authentication.php";
		include "php/functions.php";
		session_start();

		$search_data = get_park_by_id($_GET['id'])->fetchAll();;
		//$reviews = get_reviews_by_id($_GET['id']);
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
		<script
			src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false">
		</script>		
	</head>
	<body>
		<div id="body">
			<?php include 'components/header.inc'; 
			echo "<p id=\"title\">".$search_data[0]['name']."</p>";
			display_error_message();
			display_map($search_data);
			?>
		<div class="text">
			<?php echo display_park_info($search_data); ?>
		</div>
		<div>
			<div class="text" id="reviews">
				<h1>Reviews</h1>
				<p><b>8 out of 10</b> - <i>"Great park! Loads of friendly dogs. Usually busy around 5pm." - Jane Smith</i><p>	
				<p><b>4 out of 10</b> - <i>"Too Busy! Not a good spot for smaller dogs. Always a ton of bigger dogs" - Barbra Hurtbum</i><p>
			</div>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>