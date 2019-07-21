#define TQ84_PASS_ON(...) __VA_ARGS__
#define TQ84_ELEVENTH_ARGUMENT(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, ...) a11
#define TQ84_COUNT_ARGUMENTS(...) TQ84_PASS_ON(TQ84_PASS_ON(TQ84_ELEVENTH_ARGUMENT)(dummy, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
// #define TQ84_COUNT_ARGUMENTS(...) TQ84_ELEVENTH_ARGUMENT(dummy, ##__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

// // q //
// // q // #define P(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14) I1: i1, I2: i2, I3: i3, I4: i4, I5: i5, I6: i6, I7: i7, i8, i9, i10, i11, i12, i13, i14
// // q // #define P(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11) I1: i1, I2: i2, I3: i3
// // q // //#define TQ84_COUNT_ARGUMENTS(...)  P(__VA_ARGS__, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// // q // #define TQ84_VA_ARGS_INDIRECT(...) __VA_ARGS__
// // q // //#define TQ84_COUNT_ARGUMENTS(...)  TQ84_VA_ARGS_INDIRECT(P(dummy, __VA_ARGS__))
// // q //
// // q //#define TQ84_EXPAND(...) __VA_ARGS__
// // q #define TQ84_X(x) x
// // q // #define TQ84_COUNT_ARGUMENTS(...) TQ84_ELEVENTH_ARGUMENT(dummy, TQ84_EXPAND(__VA_ARGS__), 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// // q #define TQ84_COUNT_ARGUMENTS(...) TQ84_ELEVENTH_ARGUMENT(dummy, TQ84_X(__VA_ARGS__), 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
// // q 
// // q // #define D3(p1,p2,p3) P1: p1, P2: p2, P3: p3
// // q 
// // q // #define E(...) D4(TQ84_EXPAND(__VA_ARGS__))
// // q // #define F(...) D3(TQ84_X(__VA_ARGS__))
// // q // 
// // q // E(foo, bar, baz)
// // q // F(foo, bar, baz)
// // q 
// TQ84_COUNT_ARGUMENTS(foo)
// TQ84_COUNT_ARGUMENTS(foo, bar)
// TQ84_COUNT_ARGUMENTS(foo, bar, baz)
// // q 
// // q // #define exp(...) __VA_ARGS__
// // q // #define va(c, d, ...) c(d, __VA_ARGS__)
// // q // #define var(a, b, ...) exp(va(__VA_ARGS__, a, b))
// // q // 
// // q // var(2, 3, printf, "%d %d %d\kn", 1);
// // q //
// // q //
// 
// // #define A( a, b, c, ... ) #__VA_ARGS__
// // #define B( ... ) EXPAND(EXPAND(A) (__VA_ARGS__))
// 
// // #define A( a, b, c, ... ) #__VA_ARGS__
// // #define B( ... ) A(__VA_ARGS__)
// 
// // B( 1, 2, 3, 4 );
