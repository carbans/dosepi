<?php
include ('../db/db.php');

$estado= $_GET['estado'];
if ($estado==off){
exec("sh /var/www/dosepi/control/bin/apagar-alarma.sh > /dev/null &");
}else{
exec("sh /var/www/dosepi/control/bin/encender-alarma.sh > /dev/null &");
}

$sql="UPDATE alarma SET id='1', estado='$estado'";
$datos=mysql_query($sql,$link); //enviar cóo MySQL

mysql_close($con);//cerrar conexion
?>
