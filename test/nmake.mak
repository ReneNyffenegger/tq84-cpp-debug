all: diff

# .PHONY: diff

COPTS=/nologo

diff: test-prog-nmake.exe
	@.\test-prog-nmake.exe
	@fc tq84_debug.txt expected

test-prog-nmake.exe: tq84_debug.obj main.obj
	$(CXX) $(COPTS) tq84_debug.obj main.obj    /Fetest-prog-nmake.exe

tq84_debug.obj: ../tq84_debug.cpp ../tq84_debug.hpp
	@$(CXX) $(COPTS) -EHsc -c ../tq84_debug.cpp /Fotq84_debug.obj

main.i: main.cpp  ../tq84_debug.hpp
	@$(CXX) $(COPTS) -EHsc /P main.cpp

main.obj: main.i ../tq84_debug.hpp
	@$(CXX) $(COPTS) -TP -EHsc -c main.cpp          /Fomain.obj
