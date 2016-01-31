all:
	c++ -D EXECU -static -rdynamic -std=c++11 -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp trainingJob.cpp \
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-Wl,-rpath,../build/OpenBLAS \
	 	-lopenblas -lpthread

omp:
	g++-5 -fopenmp -D EXECU  -std=c++11 -g -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp trainingJob.cpp \
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-L. \
		-Wl,-rpath,../build/OpenBLAS \
		-Wl,-rpath,'$$ORIGIN' \
	 	-lopenblas -lpthread
dll:
	g++ -D EXECU -rdynamic -std=c++11 -g -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp trainingJob.cpp \
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-L. \
		-Wl,-rpath,../build/OpenBLAS \
		-Wl,-rpath,'$$ORIGIN' \
	 	-lopenblas -lpthread
dist:
	c++ -D EXECU -rdynamic -std=c++11 -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp trainingJob.cpp \
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-L. \
		-Wl,-rpath,../build/OpenBLAS \
		-Wl,-rpath,'$$ORIGIN' \
	 	-lopenblas -lpthread
	install_name_tool -change "/Users/rraja/code/cgt_distributed/build/OpenBLAS/exports/../libopenblas_sandybridgep-r0.2.14.dylib" "./libopenblas_sandybridgep-r0.2.14.dylib" a.out
	./a.out

rpi:
	/home/rohanraja/code/rpi/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-c++ \
	 	-D EXECU -rdynamic -std=c++11 -o a.out \
		../src/cgt_common.cpp ../src/execution.cpp main.cpp	egreader.cpp trainingJob.cpp \
		-I../include \
		-I../build/OpenBLAS \
		-L../build/lib \
		-L../build/OpenBLAS \
		-Wl,-rpath,../build/OpenBLAS \
	 	-lopenblas -lpthread
