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
			<form action="results.php">
					<select name="suburb" id="suburb" onchange="revert_other_searches('suburb')">
						<option>Suburb</option>
						<option value="dogsville"> Dogsville</option>
						<option value="puppingham"> Puppingham</option>					
						<option value="woofburg"> Woofburg</option>
						<option value="northbark"> North Bark</option>
					</select>

					<select name="rating" id="rating" onchange="revert_other_searches('rating')">
						<option>Rating</option>
						<option value="2">>1 Star</option>
						<option value="3">>2 Stars</option>					
						<option value="4">>3 Stars</option>
						<option value="5">>4 Stars</option>
					</select>
				<input type="text" name="search" id="search" placeholder="search" onchange="revert_other_searches('search')">
				<input type="submit" class="submit_button" id="search_btn" value="search">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>