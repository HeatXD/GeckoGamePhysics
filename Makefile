all:
	g++ src\\main.cpp -o bin\\main -std=c++14
	.\\bin\\main

test-run:
	g++ test\\*.cpp -o bin\\tests -std=c++14
	.\\bin\\tests