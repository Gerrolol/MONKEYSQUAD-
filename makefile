all:
	g++ -I src/include -L src/lib -o main *.cpp -lSDL2main -lSDL2
