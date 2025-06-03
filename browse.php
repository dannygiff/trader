<?php

include( 'includes/header.php' );

require_once( "connect.php" );

//get query
$q = "SELECT `item_id`, `item_name`, `description`, `value`, `img_name` FROM `items` WHERE 1";

//table header
echo "<table align=center>
<tr>
    <th>Img</th>
    <th>Item Name</th>
    <th>Description</th>
    <th>Price</th>
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
            <td>{$row['value']}</td>
        </tr>
        ";
    }
    $result->close();
}

//clean up
echo "</table>";
$connection->close();
include( 'includes/footer.php' );
?>