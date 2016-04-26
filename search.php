<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>		
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<h1><span>Search</span></h1>
			<form action="search.php">
				<div class="suburbselect">
					<select name="suburb">
						<option value="dogsville"> Dogsville</option>
						<option value="puppingham"> Puppingham</option>					
						<option value="woofburg"> Woofburg</option>
						<option value="northbark"> North Bark</option>
					</select>
				</div>
				<input type="text" name="search" class="searchfield" id="search" placeholder="search"><br>
				<input type="submit" class="submit_button" id="search_btn" value="search">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>