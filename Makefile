

sim: main.o game.o side.o team.o
	@ g++ main.o game.o side.o team.o -o sim

main.o: main.cpp game.hpp side.hpp utils.hpp team.hpp
	@ g++ -c main.cpp

game.o: game.cpp game.hpp side.hpp
	@ g++ -c game.cpp
side.o: side.cpp side.hpp
	@ g++ -c side.cpp

team.o: team.cpp team.hpp
	@ g++ -c team.cpp

clean: 
	
	@ cmd /q /c del /q game.o main.o side.o team.o sim.exe
	
