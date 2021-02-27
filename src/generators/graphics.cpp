#include <iostream>
#include <vector>
//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <fstream>

//#include <GLFW/
using namespace std;

//#define EVAL(...)
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define STRINGIZE(...) #__VA_ARGS__

#define CAT2(x, y) x##y
#define CAT(x, y) CAT2(x, y)

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
            
            auto props = getPhysicalDeviceProperties (i);
            auto feats = getPhysicalDeviceFeatures (i);
            
            string gpu = "#define GPU_" + to_string (nr_of_gpus);
            
            
            myfile << gpu + "_NAME = \"" + props.deviceName + "\"";
            VkPhysicalDeviceLimits limits = props.limits;
            myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_1D = " + to_string (limits.maxImageDimension1D);
            myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_2D = " + to_string (limits.maxImageDimension2D);
            myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_3D = " + to_string (limits.maxImageDimension3D);
            myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_CUBE = " + to_string (limits.maxImageDimensionCube);
            myfile << endl << gpu + "_MAX_IMAGE_ARRAY_LAYERS = " + to_string (limits.maxImageArrayLayers);
            myfile << endl << gpu + "_MAX_TEXEL_BUFFER_ELEMENTS = " + to_string (limits.maxTexelBufferElements);
            myfile << endl << gpu + "_MAX_UNIFORM_BUFFER_RANGE = " + to_string (limits.maxUniformBufferRange);
            myfile << endl << gpu + "_MAX_STORAGE_BUFFER_RANGE = " + to_string (limits.maxStorageBufferRange);
            myfile << endl << gpu + "_MAX_PUSH_CONSTANTS_SIZE = " + to_string (limits.maxPushConstantsSize);
            myfile << endl << gpu + "_MAX_MEMORY_ALLOCATION_COUNT = " + to_string (limits.maxMemoryAllocationCount);
            myfile << endl << gpu + "_MAX_SAMPLER_ALLOCATION_COUNT = " + to_string (limits.maxSamplerAllocationCount);
            myfile << endl << gpu + "_BUFFER_IMAGE_GRANULARIY = " + to_string (limits.bufferImageGranularity);
            myfile << endl << gpu + "_SPARSE_ADDRESS_SPACE_SIZE = " + to_string (limits.sparseAddressSpaceSize);
            myfile << endl << gpu + "_MAX_BOUND_DESCRIPTOR_SETS = " + to_string (limits.maxBoundDescriptorSets);
            myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLERS = " + to_string (limits.maxPerStageDescriptorSamplers);
            myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_UNIFORM_BUFFERS = " + to_string (limits.maxPerStageDescriptorUniformBuffers);
            myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLED_IMAGES = " + to_string (limits.maxPerStageDescriptorSampledImages);
            myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_STORAGE_IMAGES = " + to_string (limits.maxPerStageDescriptorStorageImages);
            
            myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_INPUT_ATTACHMENTS = " + to_string (limits.maxPerStageDescriptorInputAttachments);
            myfile << endl << gpu + "_MAX_PER_STAGE_RESOURCES = " + to_string (limits.maxPerStageResources);
            myfile << endl << gpu + "_MAX_PER_SET_SAMPLERS= " + to_string (limits.maxDescriptorSetSamplers);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS = " + to_string (limits.maxDescriptorSetUniformBuffers);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetUniformBuffersDynamic);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS = " + to_string (limits.maxDescriptorSetStorageBuffers);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetStorageBuffersDynamic);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_SAMPLED_IMAGES = " + to_string (limits.maxDescriptorSetSampledImages);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_IMAGES = " + to_string (limits.maxDescriptorSetStorageImages);
            myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_INPUT_ATTACHMENTS = " + to_string (limits.maxDescriptorSetInputAttachments);
            myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTES = " + to_string (limits.maxVertexInputAttributes);
            myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDINGS = " + to_string (limits.maxVertexInputBindings);
            myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET = " + to_string (limits.maxVertexInputAttributeOffset);
            myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDING_STRIDE = " + to_string (limits.maxVertexInputBindingStride);
            myfile << endl << gpu + "_MAX_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxVertexOutputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_GENERATION_LEVEL = " + to_string (limits.maxTessellationGenerationLevel);
            myfile << endl << gpu + "_MAX_PER_TESSELLATION_PATCH_SIZE = " + to_string (limits.maxTessellationPatchSize);
            myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_INPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_PATCH_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerPatchOutputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_TOTAL_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlTotalOutputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_INPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationInputComponents);
            myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationOutputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRY_SHADER_INVOCATIONS = " + to_string (limits.maxGeometryShaderInvocations);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
            myfile << endl << gpu + "_MAX_GEOMETRU_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
                                                                                                
                                                                                                  

            
            
            cout << "\t" <<  props.deviceName << endl;
            cout << "\t" <<  props.deviceType << endl;
//            cout << "\t" <<  props.limits << endl;
            ++nr_of_gpus;
      }
      
            
      
      
      
      
      

      
//      system("echo \"struct snoppen{};\" > graphics_info.hpp");
//      std::cout << argc << " " << argv[0] << std::endl;
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
      myfile.close();
      system("open graphics_info.hpp");
      return 0;
}

