all: diff

.PHONY: diff

diff: test-prog.exe
	@.\test-prog.exe
	@fc tq84_debug.txt expected

test-prog.exe: tq84_debug.obj main.obj
	$(CXX) tq84_debug.obj main.obj -o test-prog.exe

tq84_debug.obj: ../tq84_debug.cpp ../tq84_debug.hpp
	$(CXX) -EHsc -c ../tq84_debug.cpp -o tq84_debug.obj

main.obj: main.cpp ../tq84_debug.hpp
	$(CXX) -EHsc -c main.cpp -o main.obj
