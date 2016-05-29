<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include "php/index.inc";
session_start();
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TailWagz</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
    <script type="text/javascript" src="js/javascript.js"></script>
</head>
<body>
<!-- Header-->
<?php include 'components/header.inc'; ?>
<?php display_error_message();?>
<div id="body">
    <div id="homepage">
        <img src="images/homepage.jpg" alt="">
        <div id="center-content">
            <h2>TailWagz</h2>
            <span>A central hub to search and review dog park facilities in and around Brisbane, Australia.</span>
            <a href="search.php" class="more">search</a>
            <?php
            if (!isset($_SESSION['isLoggedOn']))
            {
                ?>
                <a href="signin.php" class="more">sign in</a>
                <a href="signup.php" class="more">sign up</a><?php
            }?>
        </div>
    </div>
    <div id="categories">
        <h1>Popular Categories</h1>
        <a href="results.php?category=beach">
            <img src="images/dog-beach.jpg" alt="">
            <p>Beach</p>
        </a>
        <a href="results.php?category=friendly">
            <img src="images/dog-friendly.jpg" alt="">
            <p>Friendly</p>
        </a>
        <a href="results.php?category=training">
            <img src="images/dog-training.jpg" alt="">
            <p>Training</p>
        </a>
        <a href="results.php?category=quiet">
            <img src="images/dog-quiet.jpg" alt="">
            <p>Quiet</p>
        </a>
        <a href="results.php?category=busy">
            <img src="images/dog-busy.jpg" alt="">
            <p>Busy</p>
        </a>
        <a href="results.php?category=big">
            <img src="images/dog-big.jpg" alt="">
            <p>Big</p>
        </a>

    </div>
    <!-- Footer -->
    <?php include 'components/footer.inc'; ?>
</body>
</html>