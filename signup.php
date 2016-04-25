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
			<h1><span>Sign up</span></h1>
			<form action="signup.php">
				<input type="text" name="firstname" id="firstname" value="name">
				<input type="text" name="surname" id="surname" value="name">
				<input type="text" name="address" id="address" value="address">
				<input type="text" name="email" id="email" value="email">
				<input type="text" name="phone" id="phone" value="phone number">
				<textarea name="message" id="message">message</textarea>
				<input type="submit" name="signup" id="signup" value="sign up">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>