#include "tq84_debug.hpp"

tq84::debug dbg("/tmp/tq84-debug-test.txt");

void f() {

  tq84::debug::indent_ f = dbg.indent("Entered f");

  dbg.log("f");

  if (42 == 42) {
    tq84::debug::indent_ equals = dbg.indent("Indeed 42==42");
    dbg.log("is it indented?");

  }
  dbg.log("going to leave f");

}

int main() {

  tq84::debug::indent_ i = dbg.indent("Entered main");
  dbg.log("going to call f");
  f();
  dbg.log("returned from f");

}
