<?php
$in = fopen("php://stdin", "r");
$data = fread($in, 100);
echo "data from c father\n";
echo $data;
echo "this is data from php code";
?>
