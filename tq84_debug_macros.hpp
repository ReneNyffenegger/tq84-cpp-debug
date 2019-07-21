#include "tq84_stringstream_expr.hpp"
#include "tq84_count_arguments.hpp"

#define TQ84_DEBUG_FUNC_FILE_LINE_ARGS   __FILE__ , __FUNCTION__ , __LINE__

#define TQ84_DEBUG_INDENT(TXT) tq84::debug::indent_ tq84_debug_indent_ ## __COUNTER__ = tq84_debug.indent(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)

TQ84_DEBUG_INDENT("hello")
