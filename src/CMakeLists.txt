

FetchContent_Declare(phulkan_generator
GIT_REPOSITORY https://github.com/phiwen96/phulkan_generator.git
GIT_TAG main
)
FetchContent_GetProperties(phulkan_generator) 
if(NOT phulkan_generator_POPULATED)
	FetchContent_Populate(phulkan_generator)
	add_subdirectory(${phulkan_generator_SOURCE_DIR} ${phulkan_generator_BINARY_DIR}) 
endif()



# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
file(GLOB_RECURSE HEADER_LIST "${phulkan_SOURCE_DIR}/include/phulkan/*.hpp")
file(GLOB SOURCE_LIST ${phulkan_SOURCE_DIR}/src/*.cpp)


# add_executable (graphics_generator ../generators/graphics.cpp)


# Make an automatic library - will be static or dynamic based on user setting
add_library (phulkan
${SOURCE_LIST}  ${HEADER_LIST} 
)

target_sources(phulkan PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions (phulkan PUBLIC kuk=3)

target_include_directories (phulkan PUBLIC ${phulkan_SOURCE_DIR}/include)

target_link_libraries (phulkan
	PUBLIC 
	${Vulkan_LIBRARIES}
 	 glfw)

target_include_directories (phulkan
	PUBLIC
	${Vulkan_INCLUDE_DIR}
	glfw
  	glm)

# This depends on (header only) boost
# target_link_libraries (modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++20
target_compile_features (phulkan PUBLIC cxx_std_20)



