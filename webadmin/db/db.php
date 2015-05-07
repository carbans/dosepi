<?php
$db_host='localhost';
$db_user='root';
$db_pass='password';
$db_name='prueba';



$link=  mysqli_connect($db_host, $db_user, $db_pass);
if(!$link){
    echo 'No se ha podido conectar con la base de datos'.mysqli_error();
}
mysqli_select_db($link, $db_name) or die (mysqli_error($link));


?>
