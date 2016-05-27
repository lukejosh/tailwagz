<!DOCTYPE html>
<html>
	<?php
		include "php/authentication.php";
		include "php/functions.php";
		session_start();
		
		if (isset($_POST['login'])) {
			login($_POST);
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
			<form id="login" action="login.php" method="post" >
				<input type="text" name="username" id="username" placeholder="Username" required/>
				<!--<input type="email" name="email" id="email" placeholder="E-Mail Address" required/>-->
				<input type="password" name="password" id="password" placeholder="Password" required/>
				<input type="submit" class="submit" name="login" id="login" value="Log In"/>
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>