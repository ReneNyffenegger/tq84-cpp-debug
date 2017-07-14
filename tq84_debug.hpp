#include  <ostream>
#include <iostream>
#include  <fstream>

// #define TQ84_DEBUG_STRINGIFY(x) #x

#define TQ84_DEBUG_FUNC_FILE_LINE_PARAMS const std::string& file, const std::string& func, int line
//#define TQ84_DEBUG_FUNC_FILE_LINE_ARGS   TQ84_DEBUG_STRINGIFY(__FUNCTION__) , TQ84_DEBUG_STRINGIFY(__FILE__) , __LINE__
#define TQ84_DEBUG_FUNC_FILE_LINE_ARGS   __FUNCTION__ , __FILE__ , __LINE__

#define TQ84_DEBUG_INDENT(TXT) tq84::debug::indent_ tq84_debug_indent_ ## __COUNTER__ = tq84_debug.indent(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)
#define TQ84_DEBUG_LOG(TXT) tq84_debug.log(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)

namespace tq84 {

class debug {

  public:
    debug(const std::string& filename);
   ~debug();

    void log(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS);

    class indent_ {
      friend debug;
      private:
        indent_(debug& dbg);
        debug& debug_;

      public:
       ~indent_();

    };

    indent_ indent(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS);

  private:

    std::ostream* stream_out = nullptr;

    int indent_level = 0;

    void print_line(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS);

    void start_line(const std::string& text);
    void print_indent(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS);
    void end_line();
};

}

#define INDENT
