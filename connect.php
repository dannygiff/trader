<?php
    //adapted from gitHub, thanks professor

    //define login stuff
    //global constants
    //on your localhost it should
    define( "DB_IP", "localhost" );
    define( "DB_USER", "root" );
    define( "DB_PASS", "" );
    define( "DB_DB", "trader" );
    

    
    
    try{ 
        $connection = new mysqli( DB_IP, DB_USER, DB_PASS, DB_DB );

        //if my connection had error number greater than 0 its broken
        if( $connection->errno > 0 ) {
            echo "error connecting";
            exit;
        }
    } catch (Exception $e ){
        debug( $e );
    }

    
    function debug( ...$a ){
        echo "<pre>";
        print_r( $a );
        echo "</pre>";
    }
?>