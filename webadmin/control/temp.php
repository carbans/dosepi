<?php
include '../db/db.php';


$temperatura1= $_GET['temp1'];//Guardamos el parametro que han introducido mediante un GET
$humedad1= $_GET['hume1'];
$temperatura2= $_GET['temp2'];
$humedad2= $_GET['hume2'];


$sql1="INSERT INTO sensores(sensor,temp,hume) VALUES ('1',$temperatura1,$humedad1);";
$datos=mysql_query($sql1,$link); //enviar cóo MySQL

$sql2="INSERT INTO sensores(sensor,temp,hume) VALUES ('2',$temperatura1,$humedad1);";
$datos2=mysql_query($sql2,$link);
mysql_close($con);//cerrar conexion
?>
