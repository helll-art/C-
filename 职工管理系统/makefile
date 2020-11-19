
#注意makefile的写法
#这样写会产生错误，你修改了文件之后，不一定会进行重新编译
#main : main.cpp employee.cpp workerManager.cpp boss.cpp manager.cpp
#	g++ -o main main.cpp employee.cpp workerManager.cpp boss.cpp manager.cpp


main : main.o employee.o workerManager.o boss.o manager.o
	g++ -o main main.o employee.o workerManager.o boss.o manager.o

main.o : main.cpp
	g++ -c main.cpp

employee.o : employee.cpp employee.h
	g++ -c employee.cpp
workerManager.o : workerManager.cpp workerManager.h
	g++ -c workerManager.cpp
boss.o : boss.cpp boss.h
	g++ -c boss.cpp
manager.o : manager.cpp manager.h
	g++ -c manager.cpp




clean :
	rm *.o
