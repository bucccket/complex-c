#include <stdio.h>
//#include "generics.h"

typedef struct {int _;} T_double_double;
typedef struct {int _;} T_double_int;
typedef struct {int _;} T_int_double;
typedef struct {int _;} T_int_int;

typedef struct { T_double_double Double; T_double_int Int;} T_double;
typedef struct { T_int_double Double;    T_int_int    Int;} T_int;

#define typeof1(X)       \
_Generic( (X),            \
    int:    (T_int){{0}},  \
    double: (T_double){{0}} )

#define typeof2(X, Y)      \
_Generic( (Y),              \
    int:    typeof1(X).Int,  \
    double: typeof1(X).Double )

#define typename(X, Y)               \
_Generic( typeof2(X, Y),              \
    T_int_int: "int, int\n",           \
    T_int_double: "int, double\n",      \
    T_double_double: "double, double\n", \
    T_double_int: "double, int\n",        \
    default: "Something else\n"            )

int main() {
    printf(typename(1, 2));
    printf(typename(1, 2.0));
    printf(typename(1.0, 2.0));
    printf(typename(1.0, 2));
    return 0;
}

