all: diff

# .PHONY: diff

COPTS=/nologo

diff: test-prog-nmake.exe
	@.\test-prog-nmake.exe
	@fc tq84_debug.txt expected

test-prog-nmake.exe: tq84_debug.obj main.obj
	$(CXX) $(COPTS) tq84_debug.obj main.obj    /Fetest-prog-nmake.exe

tq84_debug.obj:  ../tq84_debug.hpp ../tq84_debug_macros.hpp ../tq84_count_arguments.hpp ../tq84_stringstream_expr.hpp
	@$(CXX) $(COPTS) -EHsc -c ../tq84_debug.cpp /Fotq84_debug.obj

main.obj: main.i
	@$(CXX) $(COPTS) -TP -EHsc -c main.cpp      /Fomain.obj

main.i: main.cpp ../tq84_debug.hpp ../tq84_debug_macros.hpp ../tq84_count_arguments.hpp ../tq84_stringstream_expr.hpp
	@$(CXX) $(COPTS) -EHsc /P main.cpp
