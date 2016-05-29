<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include 'php/validate.inc';
include "php/signin.inc";
session_start();

if (isset($_POST['signin'])) {
	$_POST = remove_scripts($_POST);
	
	$validated = true;
	$validated = $validated && validate_username($_POST, 'username');
	$validated = $validated && validate_password($_POST, 'password');
	
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
    <link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
<?php include 'components/header.inc'; ?>
<div id="body">
    <p id="title">Sign In</p>
    <?php display_error_message();?>
    <?php display_signin_form($_POST) ;?>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>