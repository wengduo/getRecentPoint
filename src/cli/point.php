<?php


  $pay = @file_get_contents("point.csv");
  $arr = explode("\n",$pay);
  $arr_line = array();
  $con = new mysqli("localhost","root","wd123456","points");
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
      $sql = "insert into point (address,lat,lng,city_id,display,create_time,update_time) values ('".$co[0]."',"."$co[1],$co[2],$co[3],$co[4],$time,$time)";
      $ret = $con->query($sql);
      var_dump($ret);
  }
