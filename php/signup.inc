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
?>