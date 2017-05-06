<?php

for($i = 120;$i < 131;$i++) {
  $pay = @file_get_contents("or/order_list_$i.csv");
  $arr = explode("\n",$pay);
  $arr_line = array();
  $con = new mysqli("localhost","root","wd123456","sofa_order");
  if(!$con) {
    die('could not connect: '.mysql_error());
  }

  foreach($arr as $k => $v) {
    $line = trim($v);
    if(empty($line)) {
      continue;
    }
    $co = explode(',',$line);
 //   var_dump($co);  
    $time = time();
      $con->set_charset('utf8');
      $sql = "insert into order_list_$i (order_id,order_post_lat,order_post_lng) values ('".$co[0]."',"."$co[1],$co[2])";
      //var_dump($sql);
      $ret = $con->query($sql);
      //var_dump($ret);
  }
}
