myProg: main.o func.o
  g++ main.o func.o -o myProg
main.o: quat.h main.cpp
	g++ main.cpp -o main.o
main.o: func.h main.cpp
	g++ main.cpp -o main.o
func.o: quat.h func.h func.cpp
	g++ -c func.cpp
clean:
	rm -f *.o
