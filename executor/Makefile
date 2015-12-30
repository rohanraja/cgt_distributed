all:
	c++ -D EXECU -static -rdynamic -std=c++11 -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp\
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-Wl,-rpath,../build/OpenBLAS \
	 	-lopenblas -lpthread


	./a.out
