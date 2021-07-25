all:
	g++ src\\main.cpp -o build\\main
	.\\build\\main

test-run:
	g++ test\\*.cpp -o build\\tests -std=c++14
	.\\build\\tests