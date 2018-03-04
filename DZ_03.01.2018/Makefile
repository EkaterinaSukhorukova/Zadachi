all: main.o heapSort.o heapify.o printArray.o
  g++ -std=gnu++11 -O0 -Wall -Wextra -DCEMA main.o heapSort.o heapify.o printArray.o main.exe
main.o: main.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA main.cpp -o main.o
heapSort.o: heapSort.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA heapSort.cpp -o heapSort.o
heapify.o: heapify.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA heapify.cpp -o heapify.o
printArray.o: printArray.cpp func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra -DCEMA printArray.cpp -o printArray.o
clean:
	rm -f *.o
