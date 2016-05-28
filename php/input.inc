<?php

function input_text($errors, $name, $label) {
    echo '<div class="required_field">';
    label($name, $label);
    $value = posted_value($name);
    echo "<input type=\"text\" id=\"$name\" name=\"$name\" value=\"$value\"/>"; errorLabel($errors, $name);
    echo '</div>';
}

function input_password($errors, $name, $label) {
    echo '<div class="required_field">';
    label($name, $label);
    $value = posted_value($name);
    echo "<input type=\"password\" id=\"$name\" name=\"$name\" value=\"$value\"/>"; errorLabel($errors, $name);
    echo '</div>';
}

function posted_value($name){
    if(isset($_POST['firstname'])){
        return htmlspecialchars($_POST[$name]);
    }
}

function label($name, $label){
    echo "<label for=$name>$label :</label>";
}

function errorLabel($errors, $name){
    echo "<span id=$name class=\"error\">";
    if (isset($errors[$name])){
        echo $errors[$name];
    }
}

function select($name, $values) {
    echo "<select id=\"$name\" name=\"$name\">";
    foreach ($values as $value => $display){
        $selected = ($value==posted_value($name))?'selected="selected"':'';
        echo "<option $selected value=\"$value\">$display</option>";
    }

    echo '</select>';
}

?>