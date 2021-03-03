#include "graphics.hpp"
#include <ostream>
#include <type_traits>
#include "gpus_info.hpp"

string readFileIntoString(const string& path) {
      ifstream input_file(path);
      if (!input_file.is_open()) {
            cerr << "Could not open the file - '"
            << path << "'" << endl;
            exit(EXIT_FAILURE);
      }
      return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}




#define YEAH(r, data, number) BOOST_PP_CAT (data, number) = number;
#define YEAH2(...) BOOST_PP_SEQ_FOR_EACH (YEAH, int i, BOOST_PP_VARIADIC_TO_SEQ (__VA_ARGS__));

#define EMPTY(...) BOOST_PP_EXPAND (__VA_ARGS__)
#define STR_BEGIN_HELP(...) BOOST_PP_STRINGIZE (__VA_ARGS__) //R"(__VA_ARGS__)"
#define STR_BEGIN(...)  BOOST_PP_EXPAND (STR_BEGIN_HELP (__VA_ARGS__))//STR_BEGIN_HELP(__VA_ARGS__)
#define INT_2_STR(x) std::to_string (x)

struct read;
struct write;
struct End : string{
      End () : string ("\n") {}
//      friend ostream& operator<< (ostream& os, End const& e)
//      {
//            os << "\n";
//            return os;
//      }
};End endit;

template <class>
struct file;

template <class T, class U>
concept convertible = is_convertible_v<T, U> and is_convertible_v<U, T>;

template <>
struct file <write>
{
      ofstream m_file;
      using self = file<write>;
      
      
      file (char const* n)
      {
            m_file.open (n);
      }

      template <class T>
      auto operator<< (T&& v) -> decltype (auto)
      {
            m_file << forward<T>(v);
            return *this;
      }

      ~file ()
      {
            m_file.close ();
      }
};

void process (string& s)
{
      if (int b = s.find ("${"); b != string::npos)
      {
            if (int e = s.find ("}"); e != string::npos)
            {
                  cout << string (s.begin() + b + 2, s.begin() + e) << endl;
                  
            }
      }
};
#define PROCESS5(x, y) y
#define PROCESS4(x, y) {string s {x};\
if (int b = s.find ("${"); b != string::npos)\
{\
      if (int e = s.find ("}"); e != string::npos)\
      {\
            cout << string (s.begin() + b + 2, s.begin() + e) << endl;\
            \
      }\
}}
#define PROCESS3(x) PROCESS4 (BOOST_PP_STRINGIZE (x), x);
#define PROCESS5(x, y) PROCESS4 (BOOST_PP_STRINGIZE (x), x);

#define PROCESS2(x) if (x[0] == '$') cout << "fitta" << endl;
#define PROCESS(file, str) PROCESS2 (BOOST_PP_STRINGIZE (str)); file << BOOST_PP_STRINGIZE (str)
#define NN(x) {if (x == 0) 0}


#define BAJS2(_, data, element)

#define BAJS BOOST_PP_SEQ_FOR_EACH(BAJS2, int i, seq)

#define DECL(z, n, text) text ## n = n;

#define TEST 4


string process_text (string s, int max)
{
      vector <string> strings (max);
      fill (strings.begin(), strings.end(), s);
      
      auto a1 = strings[0].find("${");
      
      while (a1 != string::npos)
      {
            if (int a2 = strings[0].find ("}"); a2 != string::npos)
            {
                  for (int i = 0; i < max; ++i)
                  {
//                        cout << string (strings[i].begin() + a1 + 2, strings[i].begin() + a2) << endl;
                        
                              strings[i].replace (strings[i].begin() + a1, strings[i].begin() + a2 + 1, to_string (i));
                  }
            }
            a1 = strings[0].find ("${");
      }
      
      string res;
      
      for (auto const& i : strings)
            res += i;
      
      
      
      return res;
}
#define PROCESS_TEXT2(x, ...) process_text (BOOST_PP_STRINGIZE (x));cout<<"size:" << BOOST_PP_VARIADIC_SIZE (__VA_ARGS__) << endl;// cout << "max: " << max << endl;
#define PROCESS_TEXT(x)  BOOST_PP_SEQ_ELEM (2, x) = process_text (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (0, x)), BOOST_PP_SEQ_ELEM (1, x));



#define PROCC2(str, max, var) var = []()->string\
{\
vector <string> strings (max);\
\
fill (strings.begin(), strings.end(), str);\
\
auto a1 = strings[0].find("${");\
\
while (a1 != string::npos)\
{\
      if (int a2 = strings[0].find ("}"); a2 != string::npos)\
      {\
            for (int i = 0; i < max; ++i)\
            {\
               \
                  strings[i].replace (strings[i].begin() + a1, strings[i].begin() + a2 + 1, to_string (i));\
            }\
      }\
      a1 = strings[0].find ("${");\
}\
\
string res;\
\
for (auto const& i : strings)\
res += i;\
      return res;\
}();// = [&s]->string{return "";}();

#define PROCC(x) PROCC2 (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (0, x)), BOOST_PP_SEQ_ELEM (1, x), BOOST_PP_SEQ_ELEM (2, x))//BOOST_PP_SEQ_ELEM (2, x) = [](string s){ \
; \
}(string (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (1, x))));

//#define MACRO(z, n, text) cout << BOOST_PP_STRINGIZE (BOOST_PP_CAT (text, n)) << endl;
//#define MACRO(r, data, elem) BOOST_PP_CAT (data, BOOST_PP_CAT(elem, _MAX_IMAGE_DIMENSION_1D))
#define MACRO(r, data, i, elem) cout << BOOST_PP_STRINGIZE (BOOST_PP_CAT (data, BOOST_PP_CAT(BOOST_PP_SEQ_ELEM (0, elem), BOOST_PP_CAT (i, BOOST_PP_SEQ_ELEM (1, elem))))) << endl;


#define MACRO2(r, data, i, elem) cout << BOOST_PP_STRINGIZE (BOOST_PP_CAT(BOOST_PP_SEQ_ELEM (0, elem), BOOST_PP_CAT (data, BOOST_PP_SEQ_ELEM (1, elem)))) << endl;


#define IN_BETWEEN_LOOP_H1(r, data, i, elem)    BOOST_PP_CAT (data, BOOST_PP_CAT(BOOST_PP_SEQ_ELEM (0, elem), BOOST_PP_CAT (i, BOOST_PP_SEQ_ELEM (1, elem))))
#define IN_BETWEEN_LOOP(x)       BOOST_PP_SEQ_FOR_EACH_I (IN_BETWEEN_LOOP_H1, BOOST_PP_EMPTY(), x) // expands to a_0 b_1 c_2 d_3

int yes (...) {
      return 0;
}

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

//#define IN_BETWEEN_LOOP2(x)



#define PRO3(r, state)

#define PRO2(code, count, var)
namespace jj{}
#define PRO(x) PRO2 (BOOST_PP_STRINGIZE (BOOST_PP_SEQ_ELEM (0, x)), BOOST_PP_SEQ_ELEM (1, x), BOOST_PP_SEQ_ELEM (2, x))
#define W(...) __VA_ARGS__
int main (int argc, const char * argv[])
{
//      string input = readFileIntoString (argv [1]);
//      cout << input << endl;
      
   
      

      PROCC((
             template <>
             struct gpu <${i}>
             {
                  static constexpr int count = GPU_COUNT;
                  static constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;
             };
             
             )(1)
            (string rr))
      
      cout << rr << endl;
      file <write> f (argv [1]);
      f << "#pragma once \n";
      f << "namespace{\n";
      f << readFileIntoString (GENERATED_INCLUDE_FILE);
      f << "}\n";
      f << "template <int>struct gpu;";
      f << rr;
      
      
      cout << BOOST_PP_STRINGIZE(BOOST_PP_FOR((5, 10, kiss), PRED, OP, MACRO4)) << endl; // expands to 5 6 7 8 9 10)
      return 0;
      
      cout << BOOST_PP_STRINGIZE (IN_BETWEEN_LOOP(((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D))
                                                  ((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D)))) << endl;
      
      
      BOOST_PP_SEQ_FOR_EACH_I(MACRO, BOOST_PP_EMPTY(), ((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D))((int i = GPU_)(_MAX_IMAGE_DIMENSION_1D))) // expands to a_0 b_1 c_2 d_3
      cout << endl;
      
      
      BOOST_PP_SEQ_FOR_EACH_I(MACRO2, 0, ((int a = GPU_)(_MAX_IMAGE_DIMENSION_1D))((int b = GPU_)(_MAX_IMAGE_DIMENSION_1D))) // expands to a_0 b_1 c_2 d_3
      
      
      
      
      return 0;
      
      
      []{
            PROCESS_TEXT(
                         (int i${i} = ${i})
                         (3)
                         (string res)
                         )
            //      return 0;
            PROCESS_TEXT ((template <>
                           struct ggpu <${i}>
                           {
                  int a = ${i};
                  int b = ${i};
            };)
                          (3)
                          (string res2)
                          )
            cout << res2 << endl;
      };
      
      
      
      file <write> myfile (argv[1]);
      string template_string = readFileIntoString (TEMPLATE_FILE);
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
      auto physicalDevices = [&instance] {
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
      
      [&]{
            for (auto& i : instanceExtensions)
                  cout << "\t" << i.extensionName << endl;
            
            cout << endl;
            
            for (auto& i : instanceValidationLayers)
                  cout << "\t" << i.layerName << endl;
      };
      

      

      int nr_of_gpus = 0;
      
      for (auto& i : physicalDevices)
      {
            auto props = getPhysicalDeviceProperties (i);
            auto feats = getPhysicalDeviceFeatures (i);
            VkPhysicalDeviceLimits limits = props.limits;
            auto _int = to_string (nr_of_gpus);
            
#define MAX_IMAGE_DIMENSION_1D(limits) 1//to_string (limits.maxImageDimension1D)
            
            PROCESS_TEXT
            ((
              
                          template <>
                          struct gpu <${i}>
                          {
                              static constexpr int count = GPU_COUNT;
                              constexpr uint32_t max_image_dimension_1D = GPU_${i}_MAX_IMAGE_DIMENSION_1D;
                          };
                          
            )(GPU_COUNT)
             (string rr))
            
            
            cout << rr << endl;
//            myfile << rr;
            string kiss = "hej";
            
            
            
            template_string +=
            STR_BEGIN (template <>  ${kiss}
                       struct gpu<
                       )
            + to_string (nr_of_gpus);
            int k = 10;
            
            
         
            EAT(
                template <>
                struct gpu <${N}>
                {
                  
                };
                
                );
            
                       
                     
            
            
            
//            template_string += "struct gpu<" + to_string (nr_of_gpus) + ">\n" +
           
//            myfile << template_string;
//
//            myfile << endit << "static constexpr uint32_t max_image_dimension_1D = " << to_string (limits.maxImageDimension1D) << ";" << endit << endit;
//
//            myfile << "};" << endit;
//
//            myfile << "kuk";
                 
            break;
            
            
            
            
            
            string gpu = "#define GPU_" + to_string (nr_of_gpus);
            
            
//            myfile << gpu + "_NAME = \"" + props.deviceName + "\"";
            
            
            {
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_1D = " + to_string (limits.maxImageDimension1D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_2D = " + to_string (limits.maxImageDimension2D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_3D = " + to_string (limits.maxImageDimension3D);
//                  myfile << endl << gpu + "_MAX_IMAGE_DIMENSION_CUBE = " + to_string (limits.maxImageDimensionCube);
//                  myfile << endl << gpu + "_MAX_IMAGE_ARRAY_LAYERS = " + to_string (limits.maxImageArrayLayers);
//                  myfile << endl << gpu + "_MAX_TEXEL_BUFFER_ELEMENTS = " + to_string (limits.maxTexelBufferElements);
//                  myfile << endl << gpu + "_MAX_UNIFORM_BUFFER_RANGE = " + to_string (limits.maxUniformBufferRange);
//                  myfile << endl << gpu + "_MAX_STORAGE_BUFFER_RANGE = " + to_string (limits.maxStorageBufferRange);
//                  myfile << endl << gpu + "_MAX_PUSH_CONSTANTS_SIZE = " + to_string (limits.maxPushConstantsSize);
//                  myfile << endl << gpu + "_MAX_MEMORY_ALLOCATION_COUNT = " + to_string (limits.maxMemoryAllocationCount);
//                  myfile << endl << gpu + "_MAX_SAMPLER_ALLOCATION_COUNT = " + to_string (limits.maxSamplerAllocationCount);
//                  myfile << endl << gpu + "_BUFFER_IMAGE_GRANULARIY = " + to_string (limits.bufferImageGranularity);
//                  myfile << endl << gpu + "_SPARSE_ADDRESS_SPACE_SIZE = " + to_string (limits.sparseAddressSpaceSize);
//                  myfile << endl << gpu + "_MAX_BOUND_DESCRIPTOR_SETS = " + to_string (limits.maxBoundDescriptorSets);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLERS = " + to_string (limits.maxPerStageDescriptorSamplers);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_UNIFORM_BUFFERS = " + to_string (limits.maxPerStageDescriptorUniformBuffers);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_SAMPLED_IMAGES = " + to_string (limits.maxPerStageDescriptorSampledImages);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_STORAGE_IMAGES = " + to_string (limits.maxPerStageDescriptorStorageImages);
//
//                  myfile << endl << gpu + "_MAX_PER_STAGE_DESCRIPTOR_INPUT_ATTACHMENTS = " + to_string (limits.maxPerStageDescriptorInputAttachments);
//                  myfile << endl << gpu + "_MAX_PER_STAGE_RESOURCES = " + to_string (limits.maxPerStageResources);
//                  myfile << endl << gpu + "_MAX_PER_SET_SAMPLERS= " + to_string (limits.maxDescriptorSetSamplers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS = " + to_string (limits.maxDescriptorSetUniformBuffers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_UNIFORM_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetUniformBuffersDynamic);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS = " + to_string (limits.maxDescriptorSetStorageBuffers);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_BUFFERS_DYNAMIC = " + to_string (limits.maxDescriptorSetStorageBuffersDynamic);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_SAMPLED_IMAGES = " + to_string (limits.maxDescriptorSetSampledImages);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_STORAGE_IMAGES = " + to_string (limits.maxDescriptorSetStorageImages);
//                  myfile << endl << gpu + "_MAX_DESCRIPTOR_SET_INPUT_ATTACHMENTS = " + to_string (limits.maxDescriptorSetInputAttachments);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTES = " + to_string (limits.maxVertexInputAttributes);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDINGS = " + to_string (limits.maxVertexInputBindings);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_ATTRIBUTE_OFFSET = " + to_string (limits.maxVertexInputAttributeOffset);
//                  myfile << endl << gpu + "_MAX_VERTEX_INPUT_BINDING_STRIDE = " + to_string (limits.maxVertexInputBindingStride);
//                  myfile << endl << gpu + "_MAX_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxVertexOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_GENERATION_LEVEL = " + to_string (limits.maxTessellationGenerationLevel);
//                  myfile << endl << gpu + "_MAX_PER_TESSELLATION_PATCH_SIZE = " + to_string (limits.maxTessellationPatchSize);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_INPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_VERTEX_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerVertexInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_PER_PATCH_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlPerPatchOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_CONTROL_TOTAL_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationControlTotalOutputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_INPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationInputComponents);
//                  myfile << endl << gpu + "_MAX_TESSELLATION_EVALUATION_OUTPUT_COMPONENTS = " + to_string (limits.maxTessellationEvaluationOutputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_SHADER_INVOCATIONS = " + to_string (limits.maxGeometryShaderInvocations);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_INPUT_COMPONENTS = " + to_string (limits.maxGeometryInputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_OUTPUT_COMPONENTS = " + to_string (limits.maxGeometryOutputComponents);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_OUTPUT_VERTICES = " + to_string (limits.maxGeometryOutputVertices);
//                  myfile << endl << gpu + "_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = " + to_string (limits.maxGeometryTotalOutputComponents);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_INPUT_COMPONENTS= " + to_string (limits.maxFragmentInputComponents);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_OUTPUT_ATTACHMENTS = " + to_string (limits.maxFragmentOutputAttachments);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_DUAL_SRC_ATTACHMENTS = " + to_string (limits.maxFragmentDualSrcAttachments);
//                  myfile << endl << gpu + "_MAX_FRAGMENT_COMBINED_OUTPUT_RESOURCES = " + to_string (limits.maxFragmentCombinedOutputResources);
//                  myfile << endl << gpu + "_MAX_COMPUTE_SHARED_MEMORY_SIZE = " + to_string (limits.maxComputeSharedMemorySize);
//                  //            myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_COUNT = " + to_string (limits.maxComputeWorkGroupCount);
//                  myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = " + to_string (limits.maxComputeWorkGroupInvocations);
//                  //            myfile << endl << gpu + "_MAX_COMPUTE_WORK_GROUP_SIZE = " + to_string (limits.maxComputeWorkGroupSize);
//                  myfile << endl << gpu + "_SUB_PIXEL_PRECISION_BITS = " + to_string (limits.subPixelPrecisionBits);
//                  myfile << endl << gpu + "_SUB_TEXEL_PRECISION_BITS = " + to_string (limits.subTexelPrecisionBits);
//                  myfile << endl << gpu + "_MIPMAP_PRECISION_BITS = " + to_string (limits.mipmapPrecisionBits);
//                  myfile << endl << gpu + "_MAX_DRAW_INDEXED_INDEX_VALUE = " + to_string (limits.maxDrawIndexedIndexValue);
//                  myfile << endl << gpu + "_MAX_DRAW_INDIRECT_COUNT = " + to_string (limits.maxDrawIndirectCount);
//                  myfile << endl << gpu + "_MAX_SAMPLER_LOD_BIAS = " + to_string (limits.maxSamplerLodBias);
//                  myfile << endl << gpu + "_MAX_SAMPLER_ANISOTROPY = " + to_string (limits.maxSamplerAnisotropy);
//                  myfile << endl << gpu + "_MAX_VIEWPORTS = " + to_string (limits.maxViewports);
            }
            
            


                                                                                                  

            
            
//            cout << "\t" <<  props.deviceName << endl;
//            cout << "\t" <<  props.deviceType << endl;
//            cout << "\t" <<  props.limits << endl;
            ++nr_of_gpus;
      }
      
            
      
              
      
      
      

      
//      system("echo \"struct snoppen{};\" > graphics_info.hpp");
//      std::cout << argc << " " << argv[0] << std::endl;
      
      vkDestroyInstance(instance, nullptr);
      glfwTerminate();
//      system("open graphics_info.hpp");
      return 0;
}


