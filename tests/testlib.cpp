#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;


consteval int kiss (){return 0;}

TEST_CASE( "Quick check", "[kiss]" ) {
//      cout << GPU_0_MAX_IMAGE_DIMENSION_1D << endl;


	std::cout << "hi" << std::endl;
    REQUIRE( kiss () == 0 );
}







#define IN_BETWEEN_LOOP_H1(r, data, i, elem)    BOOST_PP_CAT (data, BOOST_PP_CAT(BOOST_PP_SEQ_ELEM (0, elem), BOOST_PP_CAT (i, BOOST_PP_SEQ_ELEM (1, elem))))
#define IN_BETWEEN_LOOP(x)       BOOST_PP_SEQ_FOR_EACH_I (IN_BETWEEN_LOOP_H1, BOOST_PP_EMPTY(), x) // expands to a_0 b_1 c_2 d_3

/**
 cout << BOOST_PP_STRINGIZE (IN_BETWEEN_LOOP(((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D)((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D)))) << endl;
 
 BOOST_PP_SEQ_FOR_EACH_I(MACRO, BOOST_PP_EMPTY(), ((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D))((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D))) // expands to a_0 b_1 c_2 d_3

 */


#define PRED(r, state) \
BOOST_PP_NOT_EQUAL ( \
BOOST_PP_TUPLE_ELEM (3, 0, state), \
BOOST_PP_INC (BOOST_PP_TUPLE_ELEM (3, 1, state)) \
) \
/**/

#define OP(r, state) \
( \
BOOST_PP_INC (BOOST_PP_TUPLE_ELEM (3, 0, state)), \
BOOST_PP_TUPLE_ELEM (3, 1, state), \
BOOST_PP_TUPLE_ELEM (3, 2, state) \
) \
/**/

#define MACRO4(r, state) state//BOOST_PP_TUPLE_ELEM (2, 0, state)

/**
 cout << BOOST_PP_STRINGIZE(BOOST_PP_FOR((5, 10, kiss), PRED, OP, MACRO4)) << endl; // expands to 5 6 7 8 9 10)

 */
