main: board
	g++ -std=c++17 main.cpp board.o knight.o -o run

test: board
	g++ -std=c++17 test.cpp board.o knight.o -o test
	./test

board: knight
	g++ -std=c++17 board.cpp knight.o -c

knight:
	g++ -std=c++17 knight.cpp -c

clean:
	rm -rf run test *.o
	
.PHONY: main test board knight clean
