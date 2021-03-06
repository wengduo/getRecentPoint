/*************************************************************************
    > File Name: getpoints.cpp
    > Author: wengduo
    > Mail: 2292466904@qq.com
    > Created Time: 2017年05月01日 星期一 09时28分12秒
 ************************************************************************/

#include "../point.h"

int main(int argc,char *argv[]) {
        Point point;
  //      printf("%d-%s-%s",argc,argv[1],argv[2]);
	struct timeval start,end;
	gettimeofday(&start,NULL);
	std::cout <<"开始时间：" << start.tv_sec <<"."<<start.tv_usec  << std::endl;
	if(argc == 3) {
		std::vector<std::vector<std::string> > tmp = point.getRecentPoint(atof(argv[1]),atof(argv[2]));
	//	std::cout << tmp.size() << std::endl;
                for(int k = 0;k < tmp.size();k++) {
			std::cout << tmp[k][0] << std::endl;
			std::cout << tmp[k][1] << std::endl;
			std::cout << tmp[k][2] << std::endl;
			std::cout << tmp[k][3] << std::endl;
		}
	}

	gettimeofday(&end,NULL);
	std::cout <<"结束时间：" << end.tv_sec<<"."<< end.tv_usec<< std::endl;
	return 0;
}
