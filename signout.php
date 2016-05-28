<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include "php/signout.inc";
session_start();

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
<?php include 'components/header.inc';?>
<div id="body">
    <p id="title">Sign Out</p>
    <p class="error">Successfully Signed Out</p>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>