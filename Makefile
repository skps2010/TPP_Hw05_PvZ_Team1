all:
	g++ -std=c++14 main.cpp map.cpp land.cpp zombie.cpp player.cpp plant.cpp game.cpp

clean:
	rm a.out