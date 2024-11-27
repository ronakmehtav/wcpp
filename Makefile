all:
	g++ --std=c++11 ./wcpp.cpp -o wc_cpp && ./wc_cpp -w -l
clear:
	rm -rf ./wc_cpp
