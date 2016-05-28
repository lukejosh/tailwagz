<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include "php/park.inc";
session_start();

if (isset($_POST['submit_review'])) {
    add_review($_POST);
}

$park_data = get_park_by_id($_GET['id'])->fetchAll();
$reviews_data = get_reviews_by_id($_GET['id']);
?>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dog Park Reviews</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
    <link rel="stylesheet" type="text/css" href="css/mobile.css" media="screen and (max-width : 568px)">
    <script type="text/javascript" src="js/javascript.js">
        var map;
        var bounds;
    </script>
    <script
        src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false">
    </script>
</head>
<body>
<div id="body">
    <?php include 'components/header.inc';
    echo "<p id=\"title\">".$park_data[0]['name']."</p>";
    display_error_message();
    display_map($park_data);
    ?>
    <div class="text">
        <?php echo display_park_info($park_data); ?>
    </div>
    <?php if (isset($_SESSION['isLoggedOn']))
    {?>
        <div class="form">
            <form id="submit_review" action="park.php?id=<?php echo $_GET['id']; ?>" method="post" >
                <input type="hidden" name="parkID" id="parkID" value="<?php echo $_GET['id']; ?>">
                <input type="text" name="message" id="message" placeholder="Review Message" required/>
                <select name="rating" id="rating">
                    <option value="">Select a rating</option>
                    <option value="1">1 Star</option>
                    <option value="2">2 Stars</option>
                    <option value="3">3 Stars</option>
                    <option value="4">4 Stars</option>
                    <option value="5">5 Stars</option>
                </select>
                <input type="submit" class="submit" name="submit_review" id="submit_review" value="Add Review"/>
            </form>
        </div>
    <?php } ?>
    <div class="text" id="reviews">
        <h1>Reviews</h1>
        <?php display_reviews($reviews_data); ?>
    </div>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>