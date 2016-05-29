<?php
function signup(array $data){
    $query = ''.
        'INSERT INTO users (username, password, salt, firstName, lastName, email, dob, mobile, sex) '.
        'VALUES(:username, SHA2(CONCAT(:password, salt), 0), salt, :firstName, :lastName, :email, DATE(:dob), :mobile, :sex)';

    $username = htmlspecialchars($data['username'], ENT_QUOTES, 'UTF-8');

    if (is_username_existing($username)){
        $_SESSION['errorMessage'] = 'Username already exists';
        header("Location: http://{$_SERVER['HTTP_HOST']}/signup.php");
        exit();
    }

    $parameters['username'] = $username;
    $parameters['password'] = htmlspecialchars($data['password'], ENT_QUOTES, 'UTF-8');
    $parameters['firstName'] = htmlspecialchars($data['firstname'], ENT_QUOTES, 'UTF-8');
    $parameters['lastName'] = htmlspecialchars($data['lastname'], ENT_QUOTES, 'UTF-8');
    $parameters['email'] = htmlspecialchars($data['email'], ENT_QUOTES, 'UTF-8');
    $parameters['dob'] = htmlspecialchars($data['dob'], ENT_QUOTES, 'UTF-8');
    $parameters['mobile'] = htmlspecialchars($data['mobile'], ENT_QUOTES, 'UTF-8');
    $parameters['sex'] = htmlspecialchars($data['sex'], ENT_QUOTES, 'UTF-8');

    $result = perform_sql_query($query, $parameters);

    session_start();
    session_id();
    $_SESSION['isLoggedOn'] = true;
    $_SESSION['username'] = $data['username'];
    header("Location: ".get_base_url()."/index.php");
    exit();
}

function is_username_existing($username){
    $query = ''.
        'SELECT * '.
        'FROM users '.
        'WHERE username = :username';
    $parameters['username'] = $username;
    $result = perform_sql_query($query, $parameters);

    if ($result->rowCount() > 0){
        return true;
    }

    return false;
}

function display_month($month, $year) {

    $first_day_of_month = mktime(0, 0, 0, $month, 1, $year);
    $first_day_of_week = date('w', $first_day_of_month);
    $month_name = date('F', $first_day_of_month);
    $days_in_month = date('t', $first_day_of_month);

    $current_year = gmDate("Y");
    $current_month = gmDate("m");
    $current_day = gmDate("d");

    echo "<h2>".$month_name." ".$year."</h2>";
    echo "<table border='solid'><tr><th>Sun</th><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th></tr>";

    if ($first_day_of_week > 0){
        echo "<td colspan=\"$first_day_of_week\">&nbsp;</td>";
    };

    for ($day_of_week = $first_day_of_week, $day_of_month=1;$day_of_month <= $days_in_month; $day_of_month++, $day_of_week++){
        if ($day_of_week == 7) # if past end of week
        {
            echo '</tr>'; # end the row for the current week
            $day_of_week = 0; # reset to the start of the week
            echo '<tr>'; # create a row for the next week
        }
        if ($current_year == $year && $current_month == $month && $current_day == $day_of_month){
            echo "<td><b>$day_of_month</b></td>";
        }else{
            echo "<td>$day_of_month</td>";
        }
    }

    $last_day_of_month = mktime(0, 0, 0, $month, $days_in_month, $year);
    $last_day_of_week = date('w', $last_day_of_month);



    if ($last_day_of_week < 6){
        $num_empty_cols = 6 - $last_day_of_week;
        echo "<td colspan=\"$num_empty_cols\">&nbsp;</td>";
    };
    echo "<tr></tr></table>";

}
?>