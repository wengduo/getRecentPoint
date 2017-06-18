/*************************************************************************
    > File Name: main.cpp
    > Author: wengduo
    > Mail: 2292466904@qq.com
    > Created Time: 2017年05月01日 星期一 09时28分12秒
 ************************************************************************/

#include "../point.h"

int main(int argc,char *argv[]) {
	std::string dbName = "points";
	Mysql points(dbName);
	Point point;
	Geohash yy;
	char sqlHead[128] = {0};
	std::vector<std::vector<std::string> > data;
	strcpy(sqlHead,"select * from point");
	points.select(sqlHead,data);	
		//std::cout <<start.tv_sec*1000 + start.tv_usec/1000 << std::endl;
		//std::cout <<start.tv_sec  << std::endl;
		std::cout << data.size() << std::endl;
		char sql[128] = {0};
		for(int j = 0;j < data.size();j++) {
	     std::vector<std::string> tmp = yy.standardizeParameters(atof(data[j][2].c_str()),atof(data[j][3].c_str()));
//			point.log_notice(__FILE__,__func__,__LINE__,"points",tmp);
			/*for(int k = 0;k < tmp.size();k++) {
				std::cout << tmp[k][0] << std::endl;
				std::cout << tmp[k][1] << std::endl;
				std::cout << tmp[k][2] << std::endl;
				std::cout << tmp[k][3] << std::endl;
			}*/
			 std::cout << tmp[0] << std::endl;
			 sprintf(sql,"update point set geohash = '%s' where id = %s",tmp[0].c_str(),data[j][0].c_str());
			points.query(sql);
			memset(sql,0,1024);
			tmp.clear();
			//gettimeofday(&end,NULL);
			//std::cout <<end.tv_sec*1000 + end.tv_usec/1000<< std::endl;
			//exit(1);
		}

	return 0;
}
