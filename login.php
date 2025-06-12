<?php
require 'connect.php';
session_start();
$pageTitle = "Login";
include ( "includes/header.php" );

//clear errors
$error = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST["username"]);
    $password = $_POST["password"];

    //regex for username
    if (!preg_match('/^[a-zA-Z0-9_]{3,20}$/', $username)) {
        $error = "Invalid username format.";
    } else {
        $stmt = $connection->prepare("SELECT id, username, password_hash, is_admin FROM users WHERE username = ?");
        $stmt->bind_param("s", $username);
        $stmt->execute();

        //get result as assoc
        $result = $stmt->get_result();
        $user = $result->fetch_assoc();

        //match pw with hashed pw in database
        if ($user && password_verify($password, $user["password_hash"])) {
            $_SESSION["user_id"] = $user["id"];
            $_SESSION["username"] = $user["username"];
            $_SESSION["is_admin"] = $user["is_admin"];//dont forget to set admin status
            header("Location: dashboard.php");
            exit;
        } else {
            //no match
            $error = "Invalid username or password.";
        }

        //clean up
        $stmt->close();
    }
}
?>


<?php if (!empty($error)) echo "<p style='color:red;'>$error</p>"; ?>

<form method="POST" action="">
    Username: <input type="text" name="username" required><br>
    Password: <input type="password" name="password" required><br>
    <input type="submit" value="Login">
</form>

