all:
	g++ src/*.cpp -o bin/main -std=c++14
	./bin/main

test-run:
	g++ test/*.cpp  src/*.cpp -o bin/tests -std=c++14 -Wall
	./bin/tests