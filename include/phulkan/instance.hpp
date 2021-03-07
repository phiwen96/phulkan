#pragma once
#include <phulkan_generator/instance.hpp>
#include <initializer_list>
#include <tuple>
#include <array>
#include <const_str/const_str.hpp>
namespace {
namespace gen = phulkan_generator;
}
using namespace std;




struct instance
{
    
    template <class... Extension, class... Layer>
    constexpr instance (tuple <Extension...> extensions, tuple <Layer...> layers)
    {
        
    }
    
    

};


//template <class T>
//concept instance_layers_concept = requires (T t) {
////    {t.name} -> is_
//}
//
//template <class... T>
//requires {
//
//}
//struct instance_layers
//{
//    static constexpr int size = sizeof... (T);
//    tuple <T...> m_layers;
//
//
//
    

    
    
    
    
    
//};
