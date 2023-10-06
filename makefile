all:
	g++ -I src/include -L src/lib -o main main.cpp Game.cpp -lSDL2main -lSDL2
