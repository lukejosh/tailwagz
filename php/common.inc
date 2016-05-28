<?php
function get_sql_connector(){
    $pdo = new PDO('mysql:host=tailwagz.cfvove2ohkes.ap-southeast-2.rds.amazonaws.com;dbname=tailwagz', 'admin', 'masterpassword');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    return $pdo;
}

function perform_sql_query($query, $parameters){
    $pdo = get_sql_connector();

    try {
        $result = $pdo->prepare($query);

        if(!is_null($parameters)){
            while($value = current($parameters)){
                $result->bindValue(':'.key($parameters), $value);
                next($parameters);
            }
        }
        $result->execute();

        return $result;
    } catch (PDOException $e) {
        $_SESSION['errorMessage'] = $result->queryString."<br><br>".json_encode($parameters)."<br><br>".$e->getMessage();
        header("Location: http://{$_SERVER['HTTP_HOST']}/cab230-assignment1/error.php");
        exit();
    }
}

function display_error_message(){
    if (isset($_SESSION['errorMessage'])){
        echo "<p class='error'>";
        echo $_SESSION['errorMessage'];
        echo "</p>";
        $_SESSION['errorMessage'] = null;
    }
}

function display_map($search_data){
    echo '<div class="googleMap" id="googleMap"></div>';
    echo '<script>initMap();</script>';

    foreach($search_data as $park){
        echo '<script>addMarkerToMap('.$park['latitude'].','.$park['longitude'].
            ',"'.$park['name'].'","park.php?id='.$park['parkid'].
            '","'.$park['rating'].'","'.$park['suburb'].
            '","'.$park['street'].'");</script>';
    }
}

function display_session_username(){
    echo '<p class="auth" id="username">';

    if (isset($_SESSION['username']))
    {
        echo "Signed in as <b>".$_SESSION['username'];
    } else {
        //echo 'Not signed in';
    }
    echo '</b></p>';
}

function display_session_actions(){
    if (isset($_SESSION['isLoggedOn']))
    {
        ?><a class="auth" href="signout.php">Log Out</a><?php
    } else {
        ?><a class="auth" href="signin.php">Log In</a>
        <a class="auth" href="signup.php">Sign Up</a>
        <?php
    }
}
?>