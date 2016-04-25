<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/myscripts.js"></script>		
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<h1><span>Search</span></h1>
			<form action="search.php">
				<input type="text" name="search" id="search" value="search">
				<input type="submit" name="signup" id="signup" value="search">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>