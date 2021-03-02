#pragma once


#define EXPAND(...) __VA_ARGS__
#define EAT(...)
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

#define PAT(...) BOOST_PP_SEQ_CAT (BOOST_PP_VARIADIC_TO_SEQ (__VA_ARGS__))



#define KISS(filename) system (BOOST_PP_CAT)


#include <iostream>
#include <vector>
#include <string>
#include <array>
//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <fstream>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/cat.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/facilities/identity.hpp>
#include <boost/preprocessor/seq/to_tuple.hpp>

using namespace std;

//#define EVAL(...)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define STRINGIZE(...) #__VA_ARGS__

#define CAT2(x, y) x##y
#define CAT(x, y) CAT2(x, y)

#include <filesystem>
//#define N \n
//#define N2 N N
//#define N3 N2 N
//#define N4 N3 N
//#define N5 N4 N



#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
auto get (auto a)
{
      return a;
}

consteval void a (int& i) {
      --i;
}

#define NR_H(x) x - 1
#define NR(x) BOOST_PP_IF((x), 1, 0)//NR_0 (x)//BOOST_PP_EXPAND (BOOST_PP_IF(x, BOOST_PP_IDENTITY(get(y)), BOOST_PP_EMPTY)())
#define NR_0(x) BOOST_PP_IF (x, 1, 0)
#define NR_1 1
#define NR_2 2
#define NR_3 3
#define NR_4 4
#define NR_5 5
#define NR_6 6


//#define IIF(c) PRIMITIVE_CAT(IIF_, c)
//#define IIF_0(t, ...) __VA_ARGS__
//#define IIF_1(t, ...) t
//#define IIF_2(t1, t2, ...) t2
//#define IIF_3(t1, t2, t3, ...) t3
//#define IIF_4(t1, t2, t3, t4, ...) t4
//#define IIF_5(t1, t2, t3, t4, t5, ...) t5
//#define IIF_6(t1, t2, t3, t4, t5, t6, ...) t6


#define EMPTY()

#define DEFER(...) __VA_ARGS__ EMPTY()
// To defer it twice we simply add in another defered EMPTY() call
#define DEFER2(...) __VA_ARGS__ DEFER(EMPTY) ()
#define DEFER3(...) __VA_ARGS__ DEFER2(EMPTY) ()
#define DEFER4(...) __VA_ARGS__ DEFER3(EMPTY) ()
#define DEFER5(...) __VA_ARGS__ DEFER4(EMPTY) ()

#define EVAL_1(...) __VA_ARGS__
// Note how we call EVAL of the lower level twice
// This allows us to double the number of EVAL calls per level
#define EVAL_2(...) EVAL_1(EVAL_1(__VA_ARGS__))
#define EVAL_3(...) EVAL_2(EVAL_2(__VA_ARGS__))
#define EVAL_4(...) EVAL_3(EVAL_3(__VA_ARGS__))
#define EVAL_5(...) EVAL_4(EVAL_4(__VA_ARGS__))
#define EVAL_6(...) EVAL_5(EVAL_5(__VA_ARGS__))
#define EVAL_7(...) EVAL_6(EVAL_6(__VA_ARGS__))
#define EVAL_8(...) EVAL_7(EVAL_7(__VA_ARGS__))
// Finally our EVAL calls the top level EVAL call
#define EVAL(...) EVAL_8(__VA_ARGS__)
