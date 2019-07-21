all: diff

.PHONY: diff

COPTS=/nologo

diff: test-prog.exe
	@.\test-prog.exe
	@fc tq84_debug.txt expected

test-prog.exe: tq84_debug.obj main.obj
	@$(CXX) $(COPTS) tq84_debug.obj main.obj /Fotest-prog.exe

tq84_debug.obj: ../tq84_debug.cpp ../tq84_debug.hpp
	@$(CXX) $(COPTS) -EHsc -c ../tq84_debug.cpp /Fotq84_debug.obj

main.obj: main.cpp ../tq84_debug.hpp
	@$(CXX) $(COPTS) -EHsc -c main.cpp /Fomain.obj
