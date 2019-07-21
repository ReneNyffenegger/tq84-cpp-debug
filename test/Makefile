.PHONY: diff

$(info  OS = $(OS))

ifeq ($(OS),Windows_NT)
  DIFF:=fc
else
  DIFF:=diff
endif

diff: test-prog
	@./test-prog
	@$(DIFF) tq84_debug.txt expected

test-prog: tq84_debug.o main.o
	$(CXX) tq84_debug.o main.o -o test-prog

tq84_debug.o: ../tq84_debug.cpp ../tq84_debug.hpp
	$(CXX) -c ../tq84_debug.cpp -o tq84_debug.o

main.o: main.ii
	$(CXX) -c main.ii -o main.o

main.ii: main.cpp ../tq84_debug.hpp
	$(CXX) -E main.cpp -o main.ii
#
# main.o: main.cpp ../tq84_debug.hpp
# 	$(CXX) -c main.cpp -o main.o
