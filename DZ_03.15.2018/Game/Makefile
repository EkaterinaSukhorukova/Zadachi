
myGame: Source.o Func.o

	g++ Source.o 

Source.o: Things.h Source.cpp 
	
	g++ -c -Wall Source.cpp

Func.o: Header1.h Func.cpp

	g++ -c -Wall Func.cpp

clean:                               
	
	rm -f myGame *.o
