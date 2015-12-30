all:
	c++ -D EXECU -static -rdynamic -std=c++11 -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp\
		-ldl -I/home/rohanraja/code/cgt/include \
		-I/home/rohanraja/code/cgt/build/OpenBLAS \
		-L/home/rohanraja/code/cgt/build/lib \
		-L/home/rohanraja/code/cgt/build/OpenBLAS \
		-Wl,-rpath,/home/rohanraja/code/cgt/build/OpenBLAS \
	 	-lopenblas -lpthread


	./a.out
