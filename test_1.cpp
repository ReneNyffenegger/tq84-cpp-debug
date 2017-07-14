#include "tq84_debug.hpp"

// Global var is in tq84_debug.cpp
// tq84::debug tq84_debug("/tmp/tq84-debug-test.txt");


void func_with_param(int param_i, const std::string& param_s) {
  TQ84_DEBUG_INDENT("Entered func_with_param");
  TQ84_DEBUG_LOG_VAR(param_i);
  TQ84_DEBUG_LOG_VAR(param_s);

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

}
