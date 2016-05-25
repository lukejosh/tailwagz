<!DOCTYPE html>
<html>
	<?php 
		session_start();
		
		include "php/logout.inc";
		logout();	
	?>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>	
				
	</head>
	<body>
		<?php include 'components/header.inc';?>
		<div id="body">
			<p id="title">Log Out</p>
			<p class="error">Successfully Logged Out</p>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>