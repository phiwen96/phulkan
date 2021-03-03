# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
file(GLOB HEADER_LIST "${phulkan_SOURCE_DIR}/include/phulkan/*.hpp")
file(GLOB SOURCE_LIST ./*.cpp)


# add_executable (graphics_generator ../generators/graphics.cpp)
# add_custom_command (
# 	OUTPUT graphics_info.hpp 
# 	COMMAND graphics_generator)

include (generators/CMakeLists.txt)



# Make an automatic library - will be static or dynamic based on user setting
add_library (phulkan_library 
${SOURCE_LIST} ${HEADER_LIST} 
# ${CMAKE_CURRENT_BINARY_DIR}/graphics_info.hpp
)

add_custom_command (
	TARGET phulkan_library
	PRE_BUILD
	COMMAND $<TARGET_FILE:graphics_generator> ${CMAKE_CURRENT_BINARY_DIR}/graphics_info.hpp)

target_sources(phulkan_library PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/graphics_info.hpp)

target_compile_definitions (phulkan_library PUBLIC kuk=3)

# We need this directory, and users of our library will need it too
target_include_directories (phulkan_library PUBLIC ../include ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries (phulkan_library
	PUBLIC 
	${Vulkan_LIBRARIES}
 	 glfw)

target_include_directories (phulkan_library
	PUBLIC
	${Vulkan_INCLUDE_DIR}
	glfw
  	glm)

# This depends on (header only) boost
# target_link_libraries (modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++20
target_compile_features (phulkan_library PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
source_group (
	TREE "${PROJECT_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LIST})

	
# message ($<TARGET_FILE:phulkan_library>)


write_compiler_detection_header (
	FILE	phulkan_compiler_detection.hpp
	PREFIX phulkan 
	COMPILERS GNU Clang MSVC Intel 
	FEATURES cxx_override 
			cxx_final 
)

