<?php
ini_set('display_errors','on');
error_reporting(E_ALL);

$mysqlServerIp      = "127.0.0.1";
$mysqlServerPort    = "3306";
$mysqlDbName        = "contact";
$mysqlDbUser        = "root";
$mysqlDbPwd         = "";
$mysqlDbCharset     = "UTF8";

try {
  $pdo = new PDO("mysql:dbname=contact;host=127.0.0.1;port=3306", "root", "", array(PDO::ATTR_PERSISTENT => true));
} catch (PDOException $e) {
  echo "Failed to get DB handle: " . $e->getMessage() . "\n";
  exit;
}
if(!empty($_POST["send"])) {
	$name = $_POST["name"];
	$email = $_POST["email"];
	$subject = $_POST["subject"];
	$message = $_POST["message"];

	$connexion = mysqli_connect("localhost", "root", "", "contact") or die("Erreur de connexion: " . mysqli_error($connexion));
	$result = mysqli_query($connexion, "INSERT INTO contact (name, email, subject, message) VALUES ('" . $name. "', '" . $email. "','" . $subject. "','" . $message. "')");
	if($result){
		$db_msg = "Vos informations de contact sont enregistrées avec succés.";
		$type_db_msg = "success";
		echo $db_msg;
	}else{
		$db_msg = "Erreur lors de la tentative d'enregistrement de contact.";
		$type_db_msg = "error";
		echo $db_msg;
	}
}
?>