#include <order/interpreter.h>

#define ORDER_PP_DEF_ dispatch_overload ORDER_PP_FN( \
 fn( N,  V, \
     do( \
         print(  cat( (static inline int DISPATCH_OVER_),  N) ((int ac, int av[]) { return ) ), \
         seq_for_each_with_idx( \
             fn( I,  T, \
                 let( ( S,  tuple_to_seq( tuple_at_1( T))), \
                     print(  lparen (ac==)  to_lit( seq_size( S)) ), \
                     seq_for_each_with_idx( fn( I,  T,  print( (&&av[)  I (]==)  cat( (K_),  T) )), 0,  S), \
                     print(  rparen (?)  I (:) ) \
                )), \
            1,  V), \
         print( ( -1; }) ) \
    ) ))

#define TYPES_TO_ENUMS(TS) ORDER_PP ( \
     do( \
         seq_for_each( fn( T,  print(  T (:)  cat( (K_),  T) (,) )), \
                       tuple_to_seq( (TS))), \
         print( (default: -1) ) \
    ) \
)
#define ENUMERATE_TYPES(TS) enum OVERLOAD_TYPEK { ORDER_PP ( \
     seq_for_each( fn( V,  print(  V (,) )),  types_to_vals( tuple_to_seq( (TS)))) \
) };
#define ORDER_PP_DEF_ types_to_vals ORDER_PP_FN( \
 fn( S,  seq_map( fn( T,  cat( (K_),  T)),  S)) )


ENUMERATE_TYPES(OVERLOAD_ARG_TYPES)
#define OVER_ARG_TYPE(V) _Generic((V), TYPES_TO_ENUMS(OVERLOAD_ARG_TYPES) )

#define OVERLOAD
ORDER_PP (
     seq_for_each(
         fn( F,
             lets( ( D,  expand( adjoin(  F,  (()) )))
                   ( O,  seq_drop(2,  tuple_to_seq( D))),
                 dispatch_overload( F,  O) )),
         tuple_to_seq( (OVERLOAD_FUNCTIONS))
    )
)
#undef OVERLOAD

#define OVERLOAD(N, ARGS, ...) ORDER_PP ( \
     do( \
         print( lparen), \
         seq_for_each_with_idx( \
             fn( I,  T, \
                 lets( ( S,  tuple_to_seq( tuple_at_1( T))) \
                       ( R,  tuple_to_seq( (ARGS))) \
                       ( N,  tuple_at_0( T)), \
                     if( equal( seq_size( S),  seq_size( R)), \
                         do( \
                             print(  lparen (DISPATCH_OVER_##N)  lparen  to_lit( seq_size( R)) (,(int[]){) ), \
                             seq_for_each( fn( A,  print( (OVER_ARG_TYPE)  lparen  A  rparen (,) )),  R), \
                             print( (-1})  rparen (==)  I  rparen (?)  N  lparen ), \
                             let( ( P,  fn( A,  T, \
                                            print( (_Generic)  lparen  lparen  A  rparen (,)  T (:)  A (,default:*)  lparen  T (*)  rparen (0)  rparen ) \
                                           )), \
                                 ap( P,  seq_head( R),  seq_head( S)), \
                                 seq_pair_with( fn( A,  T,  do( print((,)),  ap( P,  A,  T))),  seq_tail( R),  seq_tail( S)) \
                            ), \
                             print(  rparen (:) ) \
                        ), \
                         print(( )) ) \
                )), \
            1,  tuple_to_seq( ((__VA_ARGS__))) \
        ), \
         print(  cat( (N),  (_default)) (())  rparen) \
    ) \
)
