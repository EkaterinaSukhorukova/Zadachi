myProg: main.o heapSort.o heapify.o printArray.o
  g++ main.o heapSort.o heapify.o printArray.o -o myProg
main.o: func.h main.cpp
	g++ main.cpp -o main.o
heapSort.o: func.h heapSort.cpp
	g++ -c heapSort.cpp -o heapSort.o
heapify.o: func.h heapify.cpp
	g++ -c heapify.cpp -o heapify.o
printArray.o: func.h printArray.cpp
	g++ -c printArray.cpp -o printArray.o
clean:
	rm -f *.o
