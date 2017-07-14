// TODO
//   https://www.codeproject.com/Articles/27952/Debug-logging-with-STL-stream-operator
//   https://www.codeproject.com/Articles/63736/Simple-debug-log-for-C
//   http://www.drdobbs.com/cpp/logging-in-c/201804215

#include "tq84_debug.hpp"
#include <sstream>
#include <iostream>

namespace tq84 {

debug::debug(const std::string& filename) {

    if (filename == "cout") {

      stream_out = &std::cout;
    }
    else {
      stream_out = new std::ofstream();
      dynamic_cast<std::ofstream*>(stream_out)->open(filename);
    }

}

debug::~debug() {
  delete stream_out;
}

void debug::print_line(const std::string& text) {
  for (int i=0; i<indent_level; i++) {
    *stream_out << "  ";
  }
  *stream_out << text << std::endl;
}

debug::indent_::indent_(debug& dbg) : debug_(dbg) {
  ++debug_.indent_level;
}

debug::indent_::~indent_() {
  --debug_.indent_level;
  debug_.print_line("}");
}

debug::indent_ debug::indent(const std::string& text) {
  std::ostringstream s;
  s << text;
  s << " {";
  print_line(s.str());
  return indent_(*this);
}

void debug::log(const std::string& text) {
  print_line(text);
}

}
