<!DOCTYPE html>
<html>
	<?php
		include "php/login.inc";
		if (isset($_POST['login'])) {
			login($_POST['email'], $_POST['password']);
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
			<?php
				if (isset($_SESSION['errorMessage'])){
					echo "<p class='error'>";
					echo $_SESSION['errorMessage'];
					echo "</p>";	
				}
			?>
			<form id="login" action="login.php" method="post" >
				<input type="email" name="email" id="email" placeholder="E-Mail Address" required/>
				<input type="password" name="password" id="password" placeholder="Password" required/>
				<input type="submit" class="submit" name="login" id="login" value="Log In"/>
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>