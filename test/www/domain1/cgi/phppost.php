<html><body>
    


<?php

$target_dir = ".";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));


// Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    echo "submit";
  $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
  if($check !== false) {
    var_dump($check);
    echo "File is an image - " . $check["mime"] . ".";
    $uploadOk = 1;
  } else { 
    echo "File is not an image.";
    $uploadOk = 0;
 }
}

?>
hello
</body></html>