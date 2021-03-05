#include <phulkan/phulkan.hpp>
#include <phulkan/instance.hpp>
#include <phulkan_generator/instance.hpp>
#include <initializer_list>
#include <vulkan/vulkan.hpp>
#include <const_str/const_str.hpp>

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
namespace gen = phulkan_generator;






int main() {
    
    
    constexpr const_str s1 ("hej");
   
    cout << s1 << endl;
    cout << s1.size () << endl;
    cout << s1 [0] << endl;
    constexpr char c1 = s1 [0];
    cout << (s1 == "hej") << endl;
    
   
    constexpr instance s = {tuple<gen::instance::extension<0>, gen::instance::extension<1>>{}, tuple<gen::instance::layer<0>>{}};
    
    instance_layers in = {gen::instance::layer<0>{}, gen::instance::layer<1>{}};
    
    return 0;
}
