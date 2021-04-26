#Makefile for game_main

generate.o: generate.cpp generate.h
	g++ -pedantic-errors -std=c++11 -c generate.cpp

print_grid.o: print_grid.cpp print_grid.h
	g++ -pedantic-errors -std=c++11 -c print_grid.cpp

tail_insert.o: tail_insert.cpp tail_insert.h
	g++ -pedantic-errors -std=c++11 -c tail_insert.cpp

match.o: match.cpp match.h
	g++ -pedantic-errors -std=c++11 -c match.cpp

game_main.o: game_main.cpp generate.h print_grid.h tail_insert.h match.h
	g++ -pedantic-errors -std=c++11 -c game_main.cpp

game_main: game_main.o generate.o print_grid.o tail_insert.o match.o
	g++ -pedantic-errors -std=c++11 game_main.o generate.o print_grid.o tail_insert.o match.o -o game_main
