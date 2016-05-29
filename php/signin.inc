<?php
function signin(array $signin_data){
    session_id();
    $query = ''.
        'SELECT * '.
        'FROM users '.
        'WHERE username = :username and '.
        'password = SHA2(CONCAT(:password, salt), 0)';

    $parameters['username'] = $signin_data['username'];
    $parameters['password'] = $signin_data['password'];
    $result = perform_sql_query($query, $parameters);

    if ($result->rowCount() > 0){
        session_start();
        session_id();
        $_SESSION['isLoggedOn'] = true;

        $user = $result -> fetch();
        $_SESSION['username'] = htmlspecialchars($user['username'], ENT_QUOTES, 'UTF-8');

        header("Location: ".get_base_url()."/index.php");
        exit();
    }

    $_SESSION['errorMessage'] = 'Failed to log on. Please check your username and password';
}

function display_signin_form($form_data){
	$username = "";
	$password = "";
	
	if (isset($form_data['username'])) {
		$username = $form_data['username'];
	}
	
	if (isset($form_data['password'])) {
		$password = $form_data['password'];
	}
	
	echo "<form id='signin' action='signin.php' method='post'>
			<input type='text' name='username' id='username' placeholder='Username' value='".$username."' required/>
			<input type='password' name='password' id='password' placeholder='Password' value='".$password."' required/>
			<input type='submit' class='submit' name='signin' id='signin' value='Sign In'/>
		</form>";
}
?>