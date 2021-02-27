#include <iostream>
#include <vector>
//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <fstream>

//#include <GLFW/
using namespace std;

#define EVAL(...) __VA_ARGS__
#define STRINGIZE(...) #__VA_ARGS__
#define CAT(x, y) STRINGIZE(x##y)

int main (int argc, const char * argv[])
{
      ofstream myfile;
      myfile.open ("graphics_info.hpp");
      
      
      glfwInit();
      auto instanceExtensions = []{
            uint32_t extensionCount = 0;
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
            vector<VkExtensionProperties> extensions (extensionCount);
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
            return extensions;
      }();
      auto instanceValidationLayers = []{
            uint32_t layerCount = 0;
            vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
            vector<VkLayerProperties> availableLayers (layerCount);
            vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
            return availableLayers;
      }();
      auto instance = []{
            VkApplicationInfo appInfo
            {
                  .sType                  = VK_STRUCTURE_TYPE_APPLICATION_INFO,
                  .pApplicationName       = "generator",
                  .applicationVersion     = VK_MAKE_VERSION (1, 0, 0),
                  .pEngineName            = "No Engine",
                  .engineVersion          = VK_MAKE_VERSION (1, 0, 0),
                  .apiVersion             = VK_API_VERSION_1_2
            };
            
            
            
            VkInstance instance;
            
            VkInstanceCreateInfo createInfo
            {
                  .sType                        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                  .pApplicationInfo             = &appInfo,
                  .enabledExtensionCount        = 0,//glfwExtensionCount,
                  .ppEnabledExtensionNames      = nullptr,//glfwExtensions,
                  .enabledLayerCount            = 0
            };
            

            
            
            
            if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            {
                  throw runtime_error ("failed to create instance");
            }
            return instance;
      }();
      auto physicalDevices = [&instance]{
            uint32_t deviceCount = 0;
            vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
            vector<VkPhysicalDevice> devices (deviceCount);
            vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
            return devices;
      }();
      auto getPhysicalDeviceProperties = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceProperties properties;
            vkGetPhysicalDeviceProperties(physicalDevice, &properties);
            return properties;
      };
      auto getPhysicalDeviceFeatures = [](VkPhysicalDevice const& physicalDevice) {
            VkPhysicalDeviceFeatures features;
            vkGetPhysicalDeviceFeatures(physicalDevice, &features);
            return features;
      };
      
      for (auto& i : instanceExtensions)
            cout << "\t" << i.extensionName << endl;
      
      cout << endl;
      
      for (auto& i : instanceValidationLayers)
            cout << "\t" << i.layerName << endl;
      
      cout << endl;
      
      
      int nr_of_gpus = 0;
      for (auto& i : physicalDevices)
      {
            ++nr_of_gpus;
            auto props = getPhysicalDeviceProperties (i);
            auto feats = getPhysicalDeviceFeatures (i);
            string def = CAT(#define GPU_, nr_of_gpus);
//            string name = props.deviceName;
            myfile << def;
            cout << "\t" <<  props.deviceName << endl;
            cout << "\t" <<  props.deviceType << endl;
//            cout << "\t" <<  props.limits << endl;
      }
      
            
      
      
      
      
      

      
//      system("echo \"struct snoppen{};\" > graphics_info.hpp");
//      std::cout << argc << " " << argv[0] << std::endl;
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
      myfile.close();
      system("open graphics_info.hpp");
      return 0;
}


