// TODO
//   https://www.codeproject.com/Articles/27952/Debug-logging-with-STL-stream-operator
//   https://www.codeproject.com/Articles/63736/Simple-debug-log-for-C
//   http://www.drdobbs.com/cpp/logging-in-c/201804215

#include "tq84_debug.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

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

void debug::start_line(const std::string& text) {

  std::string spaces(indent_level*2, ' ');

  std::ostringstream oss;
  oss << spaces << text;

  *stream_out << std::left << std::setw(70) << oss.str();
}

void debug::end_line() {
  *stream_out << std::endl;
}

void debug::print_indent(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS) {
  start_line(text);

  *stream_out << std::left << std::setw(30) << file <<  std::setw(30) << func << std::setw(4) << std::right << line << std::endl;
//for (int i=0; i<indent_level; i++) {
//  *stream_out << "  ";
//}
}

void debug::print_line(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS) {
  print_indent(text, file, func, line);
//*stream_out << text << std::endl;
}


debug::indent_::indent_(debug& dbg) : debug_(dbg) {
  ++debug_.indent_level;
}

debug::indent_::~indent_() {
  --debug_.indent_level;
  debug_.start_line("}");
  debug_.end_line();
}

debug::indent_ debug::indent(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS) {
  std::ostringstream s;
  s << text;
  s << " {";
  print_line(s.str(), file, func, line);
  return indent_(*this);
}

void debug::log(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS) {
  print_line(text, file, func, line);
}

}

tq84::debug tq84_debug("/tmp/tq84_debug.txt");
