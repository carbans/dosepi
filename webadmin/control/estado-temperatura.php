<?php

$pagina=$_GET['pag'];

switch ($pagina)
{
	case estudio:
		include('temperatura/estudio.php');
		break;
	case comedor:
		include('temperatura/comedor');
		break;
}


?>