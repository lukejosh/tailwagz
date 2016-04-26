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
			<h1><span>Sign up</span></h1>
			<form action="signup.php">
				<input type="text" name="firstname" id="firstname" placeholder="First Name" required>
				<input type="text" name="surname" id="surname" placeholder="Last Name" required>
				<input type="email" name="email" id="email" placeholder="E-Mail Address" required>
				<input type="number" name="phone" id="phone" placeholder="phone number" required>
				<input type="password" name="password" id="password" placeholder="Password" required>
				<input type="password" name="confpassword" id="confpassword" placeholder="Confirm Password" onchange="validate_password();" required>
				<input type="date" class="date" placeholder="02/02/1996" required>
				<fieldset>
					<div id="rbuttons">
						<input class="radio-input" type="radio" name="gender" value="male" />
						<label class="radio-label">Male</label>
						<input class="radio-input" type="radio" name="gender" value="female" />
						<label class="radio-label">Female</label>
					</div>
				</fieldset>
				<input type="submit" class="submit_button" name="signup" id="signup" value="sign up">
			</form>
		</div>
		<?php include 'components/footer.inc'; ?>
	</body>
</html>