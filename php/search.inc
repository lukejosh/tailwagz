<?php
	function add_suburb_options(){
		$query = 'SELECT DISTINCT suburb FROM parks ORDER BY suburb ASC';
		$parameters = null;
		$result = perform_sql_query($query, $parameters);

		if ($result->rowCount() < 1 || is_null($result)){
				exit();
		}

		foreach($result as $key => $row){
			echo "<option value=\"".$row['suburb']."\">".$row['suburb']."</option>";
		}
	}
?>