<!DOCTYPE html>
<html>
	<?php
		include "php/common.inc";
		include "php/signin.inc";
		session_start();	
		
		if (isset($_POST['signin'])) {
			signin($_POST);
			// If login fails we need to add logic to refill forms
		}
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
		<?php include 'components/header.inc'; ?>
		<div id="body">
			<p id="title">Log In</p>
			<?php display_error_message();?>
			<form id="signin" action="signin.php" method="post" >
				<input type="text" name="username" id="username" placeholder="Username" required/>
				<input type="password" name="password" id="password" placeholder="Password" required/>
				<input type="submit" class="submit" name="signin" id="signin" value="Sign In"/>
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>