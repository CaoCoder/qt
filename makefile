aod:aod.cpp util.hpp data.hpp
	g++ -o $@ $^ -std=c++11 -ljsoncpp  -lmysqlclient -lpthread 
.PHONY:clean
clean:
	rm -rf aod