<?php

include( 'includes/header.php' );

require_once( "connect.php" );

//initialize cart if not set
if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = [];
}

//is something in post?
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_to_cart'])) {
    $item_id = $_POST['item_id'];
    
    // Add item ID to cart (or increase quantity)
    if (!isset($_SESSION['cart'][$item_id])) {
        $_SESSION['cart'][$item_id] = 1;
    } else {
        $_SESSION['cart'][$item_id]++;
    }

    //prevent form being submitted again
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}


//get query
$q = "SELECT i.item_id, i.item_name, i.description, i.value, t.typeName 
        FROM items i
        LEFT JOIN item_types t ON i.type = t.typeID";

//table header
echo "<table align=center>
<tr>
    <th>Img</th>
    <th>Item Name</th>
    <th>Description</th>
    <th>Type</th>
    <th>Price</th>
    <th>"?>
    <a href="view_cart.php">View Cart</a>
    <?php
echo "</th>    
</tr>
";

//get db stuff
if ($result = $connection->query( $q ))
{
    foreach( $result as $row)
    {
        echo "
        <tr>
            <td>img</td>
            <td>{$row['item_name']}</td>
            <td>{$row['description']}</td>
            <td>{$row['typeName']}</td>
            <td>{$row['value']}</td>
            <td>
                <form method='post' style='margin:0'>
                    <input type='hidden' name='item_id' value='{$row['item_id']}'>
                    <button type='submit' name='add_to_cart'>Add to Cart</button>
                </form>
            </td>
        </tr>
        ";
    }
    $result->close();
    $connection->close();
}

//clean up
echo "</table>";

include( 'includes/footer.php' );
?>