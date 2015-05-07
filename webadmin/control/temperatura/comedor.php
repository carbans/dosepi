<?php
include ('../../db/db.php');
$sql="select temp from sensores where id='1' order by date DESC limit 1;";
$result=mysqli_query($link, $sql);
$registro= mysqli_fetch_array($result);
echo $registro['temp'];


mysqli_close($link);


?>
