<!DOCTYPE html>
<html>
<?php
// Include all necessary php files
include "php/common.inc";
include 'php/validate.inc';
include "php/signup.inc";

// Start the users session
session_start();

// If the user has posted a signup form	
if (isset($_POST['signup'])) {
	// Remove all cross site scripting from the data
	$_POST = remove_scripts($_POST);
	
	// Validate the data
	$validated = true;
	$validated = $validated && validate_username($_POST, 'username');
	$validated = $validated && validate_name($_POST, 'firstname');
	$validated = $validated && validate_name($_POST, 'lastname');
	$validated = $validated && validate_email($_POST, 'email');
	$validated = $validated && validate_date($_POST, 'dob');
	$validated = $validated && validate_gender($_POST, 'sex');
	$validated = $validated && validate_number($_POST, 'mobile');
	$validated = $validated && validate_password($_POST, 'password');
	$validated = $validated && check_passwords_match($_POST , 'password' , 'confpassword');
	
	// If validated the data then signup
	if($validated){
		signup($_POST);
	}
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
	<!-- Header -->
	<?php include 'components/header.inc'; ?>
	<!-- Body -->
	<div id="body">
		<p id="title">Sign Up</p>
		<!-- If there is an error message then display it -->
		<?php display_error_message();?>
		<!-- display the form for signing in -->
		<?php display_signin_form($_POST);?>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>