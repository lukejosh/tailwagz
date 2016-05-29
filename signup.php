<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include 'php/validate.inc';
include "php/signup.inc";
session_start();

if (isset($_POST['signup'])) {
	$_POST = remove_scripts($_POST);
	
	$validated = true;
	$validated = $validated && validate_username($_POST, 'username');
	$validated = $validated && validate_name($_POST, 'firstname');
	$validated = $validated && validate_name($_POST, 'lastname');
	$validated = $validated && validate_email($_POST, 'email');
	$validated = $validated && validate_date($_POST, 'dob');
	$validated = $validated && validate_gender($_POST, 'gender');
	$validated = $validated && validate_number($_POST, 'mobile');
	$validated = $validated && validate_password($_POST, 'password');
	$validated = $validated && check_passwords_match($_POST , 'password' , 'confpassword');
	
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
<?php include 'components/header.inc'; ?>
<div id="body">
    <p id="title">Sign Up</p>
    <?php display_error_message();?>
    <form id="signup" action="signup.php" method="post" >
        <input type="text" name="username" id="username" placeholder="Username" required/>
        <input type="text" name="firstname" id="firstname" placeholder="First Name" required/>
        <input type="text" name="lastname" id="lastname" placeholder="Last Name" required/>
        <input type="email" name="email" id="email" placeholder="E-Mail Address" required/>
        <input type="text" name="mobile" id="mobile" placeholder="Phone number" required/>
        <input type="password" name="password" id="password" placeholder="Password" required/>
        <input type="password" name="confpassword" id="confpassword" placeholder="Confirm Password" onchange="validate_password();" required/>
        <input type="date" class="date" name="dob" id="dob" placeholder="Date of birth (yyy/mm/dd)" required/>
        <div id="rbuttons">
            <input type="radio" name="sex" value="male"/>
            <label >Male</label>
            <input type="radio" name="sex" value="female"/>
            <label >Female</label>
        </div>
        <input type="submit" class="submit" name="signup" id="signup" value="Sign Up"/>
    </form>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>