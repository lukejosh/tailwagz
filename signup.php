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
			<p id="title">Sign Up</p>
			<form action="signup.php">
				<input type="text" name="username" id="username" placeholder="Username" required/>
				<input type="text" name="firstname" id="firstname" placeholder="First Name" required/>
				<input type="text" name="surname" id="surname" placeholder="Last Name" required/>
				<input type="email" name="email" id="email" placeholder="E-Mail Address" required/>
				<input type="number" name="phone" id="phone" placeholder="Phone number" required/>
				<input type="password" name="password" id="password" placeholder="Password" required/>
				<input type="password" name="confpassword" id="confpassword" placeholder="Confirm Password" onchange="validate_password();" required/>
				<!--<input type="date" class="date" placeholder="02/02/1996" required/>
				<div id="rbuttons">
					<input type="radio" name="gender" value="male"/>
					<label >Male</label>
					<input type="radio" name="gender" value="female"/>
					<label >Female</label>
				</div>-->
				<input type="submit" class="submit" name="signup" id="signup" value="Sign Up"/>
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>