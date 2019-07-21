#include  <ostream>
#include <iostream>
#include  <sstream>
#include  <fstream>

#include "tq84_stringstream_expr.hpp"

#define TQ84_ELEVENTH_ARGUMENT(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) a11
#define TQ84_COUNT_ARGUMENTS(...) TQ84_ELEVENTH_ARGUMENT(dummy, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// #define TQ84_CONCAT(a, b) a ## b
// #define TQ84_CONCAT2(a, b) TQ84_CONCAT(a, b)


#define TQ84_DEBUG_FUNC_FILE_LINE_PARAMS const std::string& file, const std::string& func, int line
#define TQ84_DEBUG_FUNC_FILE_LINE_ARGS   __FILE__ , __FUNCTION__ , __LINE__
// c++ 11: might also use __func__ instead of __FUNCTION__

#define TQ84_DEBUG_INDENT(TXT) tq84::debug::indent_ tq84_debug_indent_ ## __COUNTER__ = tq84_debug.indent(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)
// #define TQ84_DEBUG_LOG(TXT) tq84_debug.log(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)
   #define TQ84_DEBUG_LOG(expr) TQ84_STRINGSTREAM_EXPR(expr); tq84_debug.log( TQ84_STRINGSTREAM_STR , TQ84_DEBUG_FUNC_FILE_LINE_ARGS );

#define TQ84_DEBUG_VAR2SS(VAR) \
  ss << #VAR << ": " << VAR;

#define TQ84_DEBUG_LOG_VAR_BEGIN(VAR) \
{ \
  std::ostringstream ss; \
  TQ84_DEBUG_VAR2SS(VAR)

#define TQ84_DEBUG_LOG_VAR_END \
  tq84_debug.log(ss.str(), TQ84_DEBUG_FUNC_FILE_LINE_ARGS); \
}

#define TQ84_DEBUG_LOG_VAR_APPEND(VAR) \
  ss << ", "; \
  TQ84_DEBUG_VAR2SS(VAR)
  

#define TQ84_DEBUG_LOG_VAR(...) \
  TQ84_CONCAT_INDIRECT(TQ84_DEBUG_LOG_VAR_, TQ84_COUNT_ARGUMENTS(__VA_ARGS__))(__VA_ARGS__)
  
#define TQ84_DEBUG_LOG_VAR_1(VAR1) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_2(VAR1, VAR2) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_3(VAR1, VAR2, VAR3) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_4(VAR1, VAR2, VAR3, VAR4) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_5(VAR1, VAR2, VAR3, VAR4, VAR5) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_6(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_7(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR7) \
    TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_8(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7, VAR8) \
    TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR7) \
    TQ84_DEBUG_LOG_VAR_APPEND(VAR8) \
    TQ84_DEBUG_LOG_VAR_END

namespace tq84 {

class debug {

  public:
    debug(const std::string& filename);
   ~debug();

    void log(const std::string& text, TQ84_DEBUG_FUNC_FILE_LINE_PARAMS);

    static std::string var_colon_value(const std::string& var_name, const std::string& var_value);

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

extern tq84::debug tq84_debug;

#define INDENT
