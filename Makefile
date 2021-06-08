

sim: main.o game.o side.o
	@ g++ main.o game.o side.o -o sim

main.o: main.cpp game.hpp side.hpp utils.hpp team.hpp
	@ g++ -c main.cpp

game.o: game.cpp game.hpp side.hpp
	@ g++ -c game.cpp
side.o: side.cpp side.hpp
	@ g++ -c side.cpp

clean: 
	del /f game.o sim.exe main.o side.o