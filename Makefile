all:
	g++ src\\main.cpp -o build\\main
	make run

run:
	.\\build\\main