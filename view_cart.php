<?php
session_start();

// Redirect if cart is empty
if (empty($_SESSION['cart'])) {
    echo "<p style='text-align:center;'>Your cart is empty. <a href='browse.php'>Go back</a></p>";
    exit;
}

//includes
include( 'includes/header.php' );
require_once( "connect.php" );

//get cart ids
$cart_ids = array_keys($_SESSION['cart']);

if (!empty($cart_ids)) {
    //implode sticks strings together and sounds really cool
    //temp = ?,?,?,?
    $temp = implode(',', array_fill(0, count($cart_ids), '?'));

    $q = "SELECT item_id, item_name, description, value FROM items WHERE item_id IN ($temp)";
    $s = $connection->prepare($q);

    if ($s === false) {
        die("Prepare failed: " . $connection->error);
    }

    // // Ensure all IDs are integers
    // $cart_ids = array_map('intval', $cart_ids);

    $types = str_repeat('i', count($cart_ids)); //(iii...) 
    $s->bind_param($types, ...$cart_ids); 

    $s->execute();
    $result = $s->get_result();
}

?>
<h2>Your Cart</h2>
<table>
    <!-- header -->
    <tr>
        <th>Item Name</th>
        <th>Description</th>
        <th>Value</th>
        <th>Quantity</th>
        <th>Subtotal</th>
    </tr>

    <?php
    $total = 0;
    //get associative array
    while ($row = $result->fetch_assoc()) {
        $item_id = $row['item_id'];
        $quantity = $_SESSION['cart'][$item_id];
        $subtotal = $row['value'] * $quantity;
        $total += $subtotal;
        
        
        echo "<tr>
                <td>{$row['item_name']}</td>
                <td>{$row['description']}</td>
                <td>{$row['value']}</td>
                <td>$quantity</td>
                <td>$subtotal</td>
              </tr>";
    }
    ?>
    <tr>
        <!-- total on the right -->
        <td colspan="4" style="text-align:right;"><strong>Total:</strong></td>
        <td><strong><?php echo $total; ?></strong></td>
    </tr>
</table>

<div class="actions">
    <form method="post" action="view_cart.php">
        <button type="submit" name="clear_cart">Empty Cart</button>
    </form>
    <p><a href="browse.php">Back to items</a></p>
</div>

<?php

//cart clearing
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['clear_cart'])) {
    $_SESSION['cart'] = [];
    header("Location: view_cart.php");
    exit;
}


//clean up
$connection->close();
include( 'includes/footer.php' );
?>