<?php
include('../db/db.php');


$sql=" SELECT * FROM alarma"; //cóo MySQL
$datos=mysql_query($sql,$link); //enviar cóo MySQL
while ($row=mysql_fetch_array($datos)) { //Bucle para ver todos los registros
      $estado=$row['estado']; //datos del campo teléno
      echo $estado; //visualizar datos
      }
mysql_close($con);//cerrar conexion
?>
