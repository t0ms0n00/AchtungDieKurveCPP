compile:
	g++ -c main.cpp
	g++ -o flat_map.o -c flat_map.cpp
	g++ -o player.o -c player.cpp
	g++ -o vector2D.o -c vector2D.cpp 
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lX11 flat_map.o player.o vector2D.o
	

clean:
	rm -f *.o
	rm -f main

run: compile
	./main