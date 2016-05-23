<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>Dog Park Reviews</title>
		<link rel="stylesheet" type="text/css" href="css/style.css">
		<link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
		<script type="text/javascript" src="js/javascript.js"></script>	
		
		</script>		
	</head>
	<body>
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<p id="title">Search</p>
			
			<form action="results.php">
				<a href="search.php" class="submit" id="location"><p>Search By Location</p></a>
				<p>or select one of the following</p>
				<select name="suburb" id="suburb" onchange="revert_other_searches('suburb')">
					<option>Select a suburb</option>
					<option value="dogsville">Dogsville</option>
					<option value="puppingham">Puppingham</option>					
					<option value="woofburg">Woofburg</option>
					<option value="northbark">North Bark</option>
				</select>
				<select name="rating" id="rating" onchange="revert_other_searches('rating')">
					<option>Select a minimum rating</option>
					<option value="2">> 1 Star</option>
					<option value="3">> 2 Stars</option>					
					<option value="4">> 3 Stars</option>
					<option value="5">> 4 Stars</option>
				</select>
				<select name="category" id="category" onchange="revert_other_searches('category')">
					<option>Select a category</option>
					<option value="2">Beach</option>
					<option value="3">Friendly</option>					
					<option value="4">Training</option>
					<option value="5">Quiet</option>
					<option value="6">Busy</option>
					<option value="7">Big</option>
				</select>
				<input type="text" name="search" id="search" placeholder="Keyword" onchange="revert_other_searches('search')">
				<input type="submit" class="submit" id="search_btn" value="Search">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>