#ifndef __libcomplexc_complex_h_
#define __libcomplexc_complex_h_

typedef struct complex_{
	double real;
	double imaginary;
	double phi;
	double absolute;
	double cosine;
	double sine;
}complex;

complex* new_real(double

#define FIRST(A, ...) A
#define COMPLEX(_1, ...) _Generic((_1),                              \
                              int: foo_int,                          \
                              char: foo_char,                        \
                              float: _Generic((FIRST(__VA_ARGS__,)), \
                                     int: foo_float_int))(_1, __VA_ARGS__)


extern const struct ComplexImpl
{
	complex *(*new)(...);
} complex_;

#endif
