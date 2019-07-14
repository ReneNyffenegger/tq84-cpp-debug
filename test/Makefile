.PHONY: diff

diff: test-prog
	@./test-prog
	@diff /tmp/tq84_debug.txt expected

test-prog: tq84_debug.o main.o
	$(CXX) tq84_debug.o main.o -o test-prog

tq84_debug.o: ../tq84_debug.cpp ../tq84_debug.hpp
	$(CXX) -c ../tq84_debug.cpp -o tq84_debug.o

main.o: main.cpp ../tq84_debug.hpp
	$(CXX) -c main.cpp -o main.o
