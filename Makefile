

sim: main.o game.o side.o team.o
	@ g++ main.o game.o side.o team.o -o sim

main.o: src/main.cpp src/game.hpp src/side.hpp src/utils.hpp src/team.hpp
	@ g++ -c src/main.cpp

game.o: src/game.cpp src/game.hpp src/side.hpp
	@ g++ -c src/game.cpp
side.o: src/side.cpp src/side.hpp
	@ g++ -c src/side.cpp

team.o: src/team.cpp src/team.hpp
	@ g++ -c src/team.cpp

clean: 
	
	@ cmd /q /c del /q game.o main.o side.o team.o sim.exe
	
