<?php
session_start();
require '../connect.php';
$pageTitle = "Edit Users";
include ( "../includes/header.php" );

//no admin no access
if (!isset($_SESSION["user_id"]) || $_SESSION["is_admin"] != 1) {
    die("Access denied.");
}

//get data from post
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["update_user"])) {
    $user_id = intval($_POST["user_id"]);
    $username = trim($_POST["username"]);
    $email = trim($_POST["email"]);
    $is_admin = isset($_POST["is_admin"]) ? 1 : 0;

    //user regex
    if (!preg_match('/^[a-zA-Z0-9_]{3,20}$/', $username)) {
        $error = "Invalid username format.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $error = "Invalid email.";
    } else {
        //prevent self-demotion
        if ($user_id == $_SESSION["user_id"]) {
            $is_admin = 1;
        }

        //prepare statement, bind params
        $stmt = $connection->prepare("UPDATE users SET username = ?, email = ?, is_admin = ? WHERE id = ?");
        $stmt->bind_param("ssii", $username, $email, $is_admin, $user_id);
        $stmt->execute();
        $stmt->close();
    }
}

//get users as assoc
$result = $connection->query("SELECT id, username, email, is_admin FROM users ORDER BY id ASC");
$users = $result->fetch_all(MYSQLI_ASSOC);


?>


<h2>Edit Users (Admin Only)</h2>

<p>
    <a href="../dashboard.php">Back to Dashboard</a>

</p>

<?php if (!empty($error)) echo "<p style='color:red;'>$error</p>"; ?>

<table border="1" cellpadding="5">
    <tr>
        <th>ID</th><th>Username</th><th>Email</th><th>Admin</th><th>Actions</th>
    </tr>
    <?php foreach ($users as $user): ?>
        <tr>
        <form method="POST" action="edit_users.php">
            <td><?= $user["id"] ?></td>
            <td><input type="text" name="username" value="<?= htmlspecialchars($user["username"]) ?>" required></td>
            <td><input type="email" name="email" value="<?= htmlspecialchars($user["email"]) ?>" required></td>
            <td><input type="checkbox" name="is_admin" <?= $user["is_admin"] ? "checked" : "" ?>></td>
            <td>
                <input type="hidden" name="user_id" value="<?= $user["id"] ?>">
                <input type="submit" name="update_user" value="Update">
            </td>
        </form>
        </tr>
    <?php endforeach; ?>
</table>
<?php include ( "../includes/footer.php" ); ?>
