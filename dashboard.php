<?php
session_start();
$pageTitle = "Account Dashboard";
include ( "includes/header.php" );

if (!isset($_SESSION["user_id"])) {
    header("Location: login.php");
    exit;
}
//check for admin status
$is_admin = isset($_SESSION["is_admin"]) && $_SESSION["is_admin"];
?>

<h2>Welcome, <?php echo htmlspecialchars($_SESSION["username"]); ?>!</h2>
<?php if ($is_admin): ?>
    <p><strong>You are an administrator.</strong></p>
    <p><a href="admin.php">Go to Admin Panel</a></p>
<?php else: ?>
    <p>You are a regular user.</p>
<?php endif; ?>

<p>User inventory system coming in a future update!</p>
<p style="text-align:right">...probably</p>

<p><a href="logout.php">Logout</a></p>

<?php include ( "includes/footer.php" );?>