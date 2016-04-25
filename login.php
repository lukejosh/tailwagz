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
			<h1><span>log in</span></h1>
			<form action="login.php">
				<input type="email" name="email" id="email" placeholder="E-Mail Address" required>
				<input type="password" name="password" id="password" placeholder="Password" required>
				<input type="submit" class="submit_button" name="login" id="login" value="login in">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>