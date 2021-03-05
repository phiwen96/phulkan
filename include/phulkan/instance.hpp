#pragma once
#include <phulkan_generator/instance.hpp>
#include <initializer_list>
#include <tuple>
#include <array>
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


template <int... N>
struct instance_layers
{
    static constexpr int size = sizeof... (N);
    array<char[30], size> m_layers;
    
    
    instance_layers (gen::instance::layer<N>... layers)
    {
        int i = 0;
        ((add_layer (layers, i++)), ...);
    }
    
//    template <int I>
//    instance_layers (gen::instance::layer<I>, int i)
//    {
//
//    }
    
    template <int I>
    void add_layer (gen::instance::layer<I> layer, int i)
    {
//        m_layers [i] = layer.name;
//        std::copy(layer.name, layer.name + 15, m_layers.begin ());
    }
    
    
    
    
    
};
