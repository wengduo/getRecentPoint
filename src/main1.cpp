/*************************************************************************
    > File Name: main.cpp
    > Author: wengduo
    > Mail: 2292466904@qq.com
    > Created Time: 2017年05月01日 星期一 09时28分12秒
 ************************************************************************/

#include "point.h"

int main(int argc,char *argv[]) {
	std::string dbName = "points";
	Mysql po(dbName);
	Point point;
        Geohash hs;
	char sqlHead[128] = "select * from point";
	std::vector<std::vector<std::string> > data;
	po.select(sqlHead,data);	
	std::cout << data.size() << std::endl;
        char sql[128] = {0};
	for(int j = 0;j < 1000;j++) {
                memset(sql,0,128);
		std::vector<std::string> tmp = hs.standardizeParameters(atof(data[j][2].c_str()),atof(data[j][3].c_str()));
		//  point.log_notice(__FILE__,__func__,__LINE__,"points",tmp);
		//  for(int k = 0;k < tmp.size();k++) {
                sprintf(sql,"update point set geohash = '%s' where id = %s",tmp[0].c_str(),data[j][0].c_str());
		  std::cout << sql << std::endl;
	po.query(sql);	
             
		//  std::cout << tmp[k][2] << std::endl;
		//  std::cout << tmp[k][3] << std::endl;
		 // }
	}
	return 0;
}
