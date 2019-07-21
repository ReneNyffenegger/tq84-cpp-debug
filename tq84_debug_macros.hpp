#include "tq84_stringstream_expr.hpp"
#include "tq84_count_arguments.hpp"

#define TQ84_DEBUG_FUNC_FILE_LINE_ARGS   __FILE__ , __FUNCTION__ , __LINE__

#define TQ84_DEBUG_INDENT(TXT) tq84::debug::indent_ tq84_debug_indent_ ## __COUNTER__ = tq84_debug.indent(TXT, TQ84_DEBUG_FUNC_FILE_LINE_ARGS)
#define TQ84_DEBUG_LOG(expr) TQ84_STRINGSTREAM_EXPR(expr); tq84_debug.log( TQ84_STRINGSTREAM_STR , TQ84_DEBUG_FUNC_FILE_LINE_ARGS );

#ifdef _MSC_VER
#define TQ84_DEBUG_LOG_VAR(...) \
    TQ84_PASS_ON(TQ84_CONCAT_INDIRECT(TQ84_DEBUG_LOG_VAR_, TQ84_COUNT_ARGUMENTS(__VA_ARGS__)))TQ84_PASS_ON((__VA_ARGS__))
#else
#define TQ84_DEBUG_LOG_VAR(...) \
    TQ84_CONCAT_INDIRECT(TQ84_DEBUG_LOG_VAR_, TQ84_COUNT_ARGUMENTS(__VA_ARGS__))(__VA_ARGS__)
#endif

#define TQ84_DEBUG_LOG_VAR_(VAR) #VAR << ": " << VAR

#define TQ84_DEBUG_LOG_VAR_1(VAR1) \
   TQ84_DEBUG_LOG(TQ84_DEBUG_LOG_VAR_(VAR1))

//  TQ84_DEBUG_LOG_VAR_BEGIN(VAR1) \
//  TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_2(VAR1, VAR2)  \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2)            \
   )
//  TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//  TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//  TQ84_DEBUG_LOG_VAR_END

#define TQ84_DEBUG_LOG_VAR_3(VAR1, VAR2, VAR3) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3)            \
   )

#define TQ84_DEBUG_LOG_VAR_4(VAR1, VAR2, VAR3, VAR4) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR4)            \
   )

#define TQ84_DEBUG_LOG_VAR_5(VAR1, VAR2, VAR3, VAR4, VAR5) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR4) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR5)            \
   )

#define TQ84_DEBUG_LOG_VAR_6(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR4) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR5) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR6)            \
   )

#define TQ84_DEBUG_LOG_VAR_7(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR4) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR5) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR6) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR7)            \
   )

#define TQ84_DEBUG_LOG_VAR_8(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7, VAR8) \
   TQ84_DEBUG_LOG(                        \
     TQ84_DEBUG_LOG_VAR_(VAR1) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR2) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR3) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR4) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR5) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR6) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR7) << ", " << \
     TQ84_DEBUG_LOG_VAR_(VAR8)            \
   )

// #define TQ84_DEBUG_LOG_VAR_3(VAR1, VAR2, VAR3) \
//    TQ84_DEBUG_LOG(#VAR1 << ": " << VAR1 << ", " << #VAR2 << ": " << VAR2 << ", " << #VAR3 << ": " << VAR3)

//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_END

// #define TQ84_DEBUG_LOG_VAR_4(VAR1, VAR2, VAR3, VAR4) \
//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
//     TQ84_DEBUG_LOG_VAR_END
// 
// #define TQ84_DEBUG_LOG_VAR_5(VAR1, VAR2, VAR3, VAR4, VAR5) \
//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
//     TQ84_DEBUG_LOG_VAR_END
// 
// #define TQ84_DEBUG_LOG_VAR_6(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6) \
//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
//     TQ84_DEBUG_LOG_VAR_END
// 
// #define TQ84_DEBUG_LOG_VAR_7(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7) \
//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR7) \
//     TQ84_DEBUG_LOG_VAR_END
// 
// #define TQ84_DEBUG_LOG_VAR_8(VAR1, VAR2, VAR3, VAR4, VAR5, VAR6, VAR7, VAR8) \
//     TQ84_DEBUG_LOG_VAR_BEGIN(VAR1)  \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR2) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR3) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR4) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR5) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR6) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR7) \
//     TQ84_DEBUG_LOG_VAR_APPEND(VAR8) \
//     TQ84_DEBUG_LOG_VAR_END
