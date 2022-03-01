<?php
	$bdd=new PDO('mysql:host=192.168.65.34; dbname=temperature; charset=utf8','four', 'four');
	$requete=$bdd->query("select * from temperature where id=(SELECT MAX(id) from temperature )");
	while($donnees=$requete->fetch())
	{
		echo "<h3><center>".$donnees["TEMPERATURE"]." °C</center></h3>";
	}

?>
