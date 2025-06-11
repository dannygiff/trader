<!doctype html>
<html>
<head>
    <title>add a print</title>
    <link rel="stylesheet" href="../styles.css">
</head>
<body>
    <?php
        if( $_SERVER['REQUEST_METHOD'] == "POST" ){ //doing the action
            //var_dump( $_POST );
            if( !empty( $_POST['item_name'] ) ){
                $name = trim( $_POST['item_name']);
                $desc = !empty( $_POST['item_desc'] ) ? trim( $_POST['item_desc'] ) : null;
                $value = !empty( $_POST['item_value'] ) ? trim( $_POST['item_value'] ) : null;
                $file = !empty( $_POST['item_type'] ) ? trim( $_POST['item_type'] ) : null;

                //talk to the database
                require( "../connect.php" );

                $q = "INSERT INTO `items`(`item_name`, `description`, `value`, `type`) VALUES (?,?,?,?)";
                $statement = $connection->prepare( $q );
                $statement->bind_param( "ssii", $name, $desc, $value, $file );

                // debug( $name, $fn, $fn );
                $statement->execute();


                //did it work???
                if( $statement->affected_rows == 1 ) {
                    echo "<p>it worked!</p>";
                } else {
                    echo "<p>There was an error</p>";
                }

                //close
                $statement->close();
                $connection->close();
            }
            else{
                echo "<p style='color:red'>the item requires a name</p>";
            }
        } 

    ?>

    <h1>add an item</h1>
    <form action="add_item.php" method="post">
        <fieldset>
            <legend>Fill out the form to add an item</legend>

            <label for="item_name"><b>item name</b></label>
            <input type="text" id="item_name" name="item_name" value="">

            <label for="item_desc"><b>description</b></label>
            <input type="text" id="item_desc" name="item_desc" value="">

            <label for="item_value"><b>value</b></label>
            <input type="text" id="item_value" name="item_value" value="">

            <label for="item_filename"><b>item type</b></label>
            <select id="item_type" name="item_type">
                <option value="">-select a type-</option>
                <option value="1">1</option>
                <option value="2">2</option>
                <option value="3">3</option>
                <option value="4">4</option>

            <input type="submit" value="submit" />

        </fieldset>
    </form>
    <br>
    <br>
    <a href="../landing.php">home</a>
</body>
</html>