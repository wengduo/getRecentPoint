#!/bin/bash

create_order() {
sql=$(cat <<EOF
set names utf8;
use sofa_order;

CREATE TABLE order_list_%d (
  order_id varchar(64) COLLATE utf8_bin NOT NULL DEFAULT '' COMMENT '订单id',
  order_post_lat double unsigned NOT NULL DEFAULT '0' COMMENT '发单时的纬度',
  order_post_lng double unsigned NOT NULL DEFAULT '0' COMMENT '发单时的经度',
  PRIMARY KEY (order_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

\n
EOF
)    
echo "drop database if exists sofa_order;";
echo "create database sofa_order;";

for j in {0..130};do 
	    printf "$sql" $j 
	done
}
create_order  
#exit
create_point() {
sql=$(cat<<EOF
\n
use points;
\n
CREATE TABLE point (
id bigint(20) unsigned NOT NULL AUTO_INCREMENT COMMENT 'id',
address varchar(64) CHARACTER SET utf8 NOT NULL DEFAULT '' COMMENT '站点名称',
lat double NOT NULL DEFAULT '0' COMMENT '经度',
lng double NOT NULL DEFAULT '0' COMMENT '维度',
city_id int(11) NOT NULL DEFAULT '0' COMMENT '所在城市id',
create_time int(11) NOT NULL DEFAULT '0' COMMENT '创建时间',
display tinyint(4) DEFAULT '1' COMMENT '对用户是否可见',
geohash VARCHAR(16)  NOT NULL  DEFAULT '' COMMENT '经纬度hash值',
update_time int(11) unsigned NOT NULL DEFAULT '0' COMMENT '修改时间',
PRIMARY KEY (id),
KEY idx_city_id_geohash (city_id,geohash)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT='站点表';
EOF
)
echo "drop database if exists points;";
echo "create database points;";
echo 
printf "$sql"
echo 
}
create_point
#exit
