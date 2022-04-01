all : Board_test Solver_test

Solver_test : Solver_test.o Solver.o Board.o
	g++ -std=c++11 -fsanitize=undefined -fsanitize=address -o Solver_test Solver_test.o Solver.o Board.o

Solver_test.o : Solver_test.cpp Solver.h Board.h
	g++ -std=c++11 -c Solver_test.cpp

Solver.o : Solver.cpp Solver.h
	g++ -std=c++11 -c Solver.cpp

Board_test : Board_test.o Board.o
	g++ -std=c++11 -o Board_test Board_test.o Board.o

Board_test.o : Board_test.cpp Board.h
	g++ -std=c++11 -c Board_test.cpp

Board.o : Board.cpp Board.h
	g++ -std=c++11 -c Board.cpp

clean :
	rm *.o Board_test Solver_test
