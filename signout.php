<!DOCTYPE html>
<html>
<?php
// Include all necessary php files
include "php/common.inc";
include "php/signout.inc";

// Start the users session
session_start();

// Sign the user out
signout();
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
		<p id="title">Sign Out</p>
		<p class="error">Successfully Signed Out</p>
	</div>
	<!-- Footer -->
	<?php include 'components/footer.inc'; ?>
</body>
</html>