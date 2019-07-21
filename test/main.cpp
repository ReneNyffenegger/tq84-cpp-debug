#include "../tq84_debug.hpp"

// Global var is in tq84_debug.cpp
// tq84::debug tq84_debug("/tmp/tq84-debug-test.txt");

void another_func_with_param(int i1, const std::string& s2, float f3) {

  TQ84_DEBUG_INDENT("Entered another_func_with_param");
  TQ84_DEBUG_LOG_VAR(i1, s2, f3);

}

void func_with_param(int param_i, const std::string& param_s) {
  TQ84_DEBUG_INDENT("Entered func_with_param");
  TQ84_DEBUG_LOG_VAR(param_i);
  TQ84_DEBUG_LOG_VAR(param_s);

  TQ84_DEBUG_LOG("Going to call another_func_with_param");
  another_func_with_param(-9, "minus nine", 3.141);

}

void f() {

  TQ84_DEBUG_INDENT("Entered f");

  TQ84_DEBUG_LOG("f");

  if (42 == 42) {
    TQ84_DEBUG_INDENT("indeed 42==42");

    TQ84_DEBUG_LOG("going to call g()");
    func_with_param(42, "Hello, world");

  }
  TQ84_DEBUG_LOG("going to leave f");

}

int main() {

  TQ84_DEBUG_INDENT("Entered main");
  TQ84_DEBUG_LOG("going to call f");
  f();
  TQ84_DEBUG_LOG("returned from f");


  TQ84_DEBUG_LOG("Eleventh argument: " << TQ84_ELEVENTH_ARGUMENT("one", "two", 3, 4, five, "six", 7, '8', "9", ten, "eleven", twelve, 13, "14"));

  TQ84_DEBUG_LOG("Count of arguments in (foo): "             << TQ84_COUNT_ARGUMENTS(foo));
  TQ84_DEBUG_LOG("Count of arguments in (bar,baz): "         << TQ84_COUNT_ARGUMENTS(bar,baz))
  TQ84_DEBUG_LOG("Count of arguments in (one, two, three): " << TQ84_COUNT_ARGUMENTS(one, two, three))

}
