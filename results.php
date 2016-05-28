<!DOCTYPE html>
<html>
<?php
include "php/common.inc";
include "php/results.inc";
session_start();

$results_data = get_search_results()->fetchAll();
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
    <script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDOIr2_wRZyXYr8wsA3vdXk50J0OMti4oA&signed_in=false"></script>
</head>
<body>
<?php include 'components/header.inc'; ?>
<div id="body">
    <p id="title">Results</p>
    <?php display_error_message();?>
    <?php display_map($results_data);?>
    <table id="results">
        <tr>
            <th>Name</th>
            <th>Location</th>
            <th>Tags</th>
            <th>Rating</th>
        </tr>
        <?php display_results_rows($results_data)?>
    </table>
</div>
<?php include 'components/footer.inc'; ?>
</body>
</html>