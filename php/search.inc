<?php
function add_suburb_options($preset){
    $query = 'SELECT DISTINCT suburb FROM parks ORDER BY suburb ASC';
    $parameters = null;
    $result = perform_sql_query($query, $parameters);

    if ($result->rowCount() < 1 || is_null($result)){
        exit();
    }

    foreach($result as $key => $row){
        $append_str = "";
        if ($row['suburb'] == $preset){
            $append_str = " selected";
        }

        echo "<option value=\"".
            $row['suburb'].
            "\"".
            $append_str. //If suburb was previously selected, select it again
            ">".
            $row['suburb'].
            "</option>";
    }
}
?>