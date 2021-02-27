add_executable (graphics_generator ${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics.cpp)

target_link_libraries(graphics_generator
PRIVATE 
${Vulkan_LIBRARIES}
  glfw
)

target_include_directories(graphics_generator
PRIVATE
${Vulkan_INCLUDE_DIR}
  glfw
  glm)


add_custom_command (
	OUTPUT graphics_info.hpp 
	COMMAND graphics_generator)
