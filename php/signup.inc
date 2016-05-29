<?php
function signup(array $data){
    $query = ''.
        'INSERT INTO users (username, password, salt, firstName, lastName, email, dob, mobile, sex) '.
        'VALUES(:username, SHA2(CONCAT(:password, salt), 0), salt, :firstName, :lastName, :email, DATE(:dob), :mobile, :sex)';

    $username = htmlspecialchars($data['username'], ENT_QUOTES, 'UTF-8');

    if (is_username_existing($username)){
        $_SESSION['errorMessage'] = 'Username already exists';
        return;
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

function display_signin_form($form_data){
	$username = "";
	$firstname = "";
	$lastname = "";
	$email = "";
	$dob = "";
	$mobile = "";
	$gender = "";
	$male = "checked";
	$female = "";
	
	if (isset($form_data['username'])) {
		$username = $form_data['username'];
	}
	
	if (isset($form_data['firstname'])) {
		$firstname = $form_data['firstname'];
	}
	
	if (isset($form_data['lastname'])) {
		$lastname = $form_data['lastname'];
	}
	
	if (isset($form_data['email'])) {
		$email = $form_data['email'];
	}
	
	if (isset($form_data['dob'])) {
		$dob = $form_data['dob'];
	}
	
	if (isset($form_data['mobile'])) {
		$mobile = $form_data['mobile'];
	}
	
	if (isset($form_data['sex'])) {
		if ($form_data['sex'] == "female"){
			$male = "";
			$female = "checked";
		}
	}
	
	echo "<form id='signup' action='signup.php' method='post' >
			<input type='text' name='username' id='username' placeholder='Username' value='".$username."' required/>
			<input type='text' name='firstname' id='firstname' placeholder='First Name' value='".$firstname."' required/>
			<input type='text' name='lastname' id='lastname' placeholder='Last Name' value='".$lastname."' required/>
			<input type='email' name='email' id='email' placeholder='E-Mail Address' value='".$email."' required/>
			<input type='text' name='mobile' id='mobile' placeholder='Phone number' value='".$mobile."' required/>
			<input type='password' name='password' id='password' placeholder='Password' required/>
			<input type='password' name='confpassword' id='confpassword' placeholder='Confirm Password' onchange='validate_password();' required/>
			<input type='date' class='date' name='dob' id='dob' max='2019-12-31' value='".$dob."' required/>
			<div id='rbuttons'>
				<input type='radio' name='sex' value='male' ".$male."/>
				<label >Male</label>
				<input type='radio' name='sex' value='female' ".$female."/>
				<label >Female</label>
			</div>
			<input type='submit' class='submit' name='signup' id='signup' value='Sign Up'/>
		</form>";
}
?>