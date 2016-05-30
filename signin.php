<!DOCTYPE html>
<html>
<?php
// Include all necessary php files
include "php/common.inc";
include 'php/validate.inc';
include "php/signin.inc";

// Start the users session
session_start();

// If the user has posted a signin form
if (isset($_POST['signin'])) {
	// Remove all cross site sripting from the data
	$_POST = remove_scripts($_POST);
	
	// Validate the data
	$validated = true;
	$validated = $validated && validate_username($_POST, 'username');
	$validated = $validated && validate_password($_POST, 'password');
	
	// If validated the data then signin
	if($validated){
		signin($_POST);
	}
}
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dog Park Reviews</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
	<!-- Header -->
	<?php include 'components/header.inc'; ?>
	<!-- Body -->
	<div id="body">
		<p id="title">Sign In</p>
		<!-- If there is an error message then display it -->
		<?php display_error_message();?>
		<!-- display the form for signing in -->
		<?php display_signin_form($_POST) ;?>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>