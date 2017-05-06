main : ./src/point.cpp ./src/log.h ./src/log.cpp ./src/mysql.h ./src/mysql.cpp ./src/redis.h ./src/geohash.h ./src/geohash.cpp
	g++ -o ./bin/main -std=c++11 ./src/test/main.cpp ./src/point.h ./src/point.cpp ./src/log.h ./src/log.cpp ./src/mysql.h ./src/mysql.cpp ./src/redis.h ./src/redis.cpp ./src/geohash.h ./src/geohash.cpp -lhiredis -lmysqlclient
