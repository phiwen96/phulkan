

add_executable (graphics_generator ${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics.cpp ${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics.hpp
${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp
)

# target_link_libraries(graphics_generator
# PRIVATE 
# ${Vulkan_LIBRARIES}
#   glfw
# )



target_link_libraries(graphics_generator
PUBLIC 
# /Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib 
/Users/pw/vulkansdk/MoltenVK/dylib/macOS/libMoltenVK.dylib 
/Users/pw/vulkansdk/macOS/lib/libVkLayer_khronos_validation.dylib
/Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib
glfw
)

target_include_directories(graphics_generator PUBLIC 
# /Users/pw/vulkansdk/macOS/include
/Users/pw/vulkansdk/MoltenVK/include 
glfw
/usr/local/Cellar/boost/1.75.0_1/include
)

# target_include_directories(graphics_generator
# PRIVATE
# ${Vulkan_INCLUDE_DIR}
#   glfw
#   glm)


add_custom_command (
	OUTPUT graphics_info.hpp 
	COMMAND graphics_generator)

target_compile_definitions (graphics_generator PUBLIC TEMPLATE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp")
