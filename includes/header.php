<?php
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}
$userID = isset($_SESSION['userID']) ? $_SESSION['userID'] : null;
?>

<!doctype html>
<html>
<head>
    <title><?php echo isset( $pageTitle ) ? $pageTitle : "Shop" ?></title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <header>
        <div class="logo">
             <img src="images/title.png" width="600" height="61" > 
        </div>
        <nav>
            <!-- <ul class="nav-links">
                <li><a href="index.php"><img src="images/home.jpg"></a></li>
            </ul> -->

        </nav>
        <!--navbar-->
<ul class="navbar">
    <!-- Left side -->
     <li><a href="browse.php">Browse</a></li>
     <li><a href="dashboard.php">Account</a></li>
     <?php if (isset($_SESSION["cart"]) && !empty($_SESSION["cart"])): ?>
     <li><a href="view_cart.php">View Cart</a></li>
     <?php endif; ?> 
    <!-- Right side -->
    <?php if (isset($_SESSION["login"]) && $_SESSION["login"] === true): ?>
        <li style="float:right"><a href="#logout.php">Logout</a></li>
        <li style="float:right"><a href="#">Welcome, <?php echo htmlspecialchars($_SESSION["uname"]); ?></a></li>
    <?php else: ?>
        <li style="float:right"><a href="register.php">Register</a></li>
        <li style="float:right"><a href="login.php">Login</a></li>
    <?php endif; ?>

    <!-- Admin Panel link (only if isAdmin = 1) -->
    <?php if (isset($_SESSION["isAdmin"]) && $_SESSION["isAdmin"] == 1): ?>
        <li style="float:right"><a href="admin.php">Admin Panel</a></li>
    <?php endif; ?>    
</ul>
    </header>

