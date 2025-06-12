<?php
require 'connect.php';
$pageTitle = "Register";
include ( "includes/header.php" );

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST["username"]);
    $email = trim($_POST["email"]);
    $password = $_POST["password"];

    //username regex
    if (!preg_match('/^[a-zA-Z0-9_]{3,20}$/', $username)) {
        die("Invalid username. Use 3-20 letters, numbers, or underscores.");//otherwise die(dramatically)
    }

    //email "regex"
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        die("Invalid email address.");//die also provides a nice error message
    }

    //password regex
    if (!preg_match('/^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/', $password)) {
        die("Password must be at least 8 characters long and include a letter and a number.");
    }

    //password hash
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    //prepare statement and bind params
    $stmt = $connection->prepare("INSERT INTO users (username, email, password_hash) VALUES (?, ?, ?)");
    $stmt->bind_param("sss", $username, $email, $hashed_password);

    if ($stmt->execute()) {
        echo "Registration successful. <a href='login.php'>Login here</a>.";
    } else {
        echo "Error: " . $stmt->error;
    }

    //clean up
    $stmt->close();
}
?>

<!-- <?php if ($register_success): ?> -->
    <p>Registration successful. <a href="login.php">Login here</a>.</p>
<?php else: ?>
    <?php if (!empty($error)) echo "<p style='color:red;'>$error</p>"; ?>
    <form method="POST" action="">
        Username: <input type="text" name="username" required><br>
        Email:    <input type="email" name="email" required><br>
        Password: <input type="password" name="password" required><br>
        <input type="submit" value="Register">
    </form>
<?php endif; ?>

<?php include ( "includes/footer.php" );?>