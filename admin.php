<?php
session_start();
$pageTitle = "Admin";
include ( "includes/header.php" );

//if user is not admin they shouldn't be here
if (!isset($_SESSION["user_id"]) || !isset($_SESSION["is_admin"]) || !$_SESSION["is_admin"]) {
    die("Access denied.");
}
?>

<h2>Admin Panel</h2>
<p>Only visible to admins.</p>
<p><a href="/admin/add_item.php">Add item</a></p>
<p><a href="dashboard.php">Back to Dashboard</a></p>

