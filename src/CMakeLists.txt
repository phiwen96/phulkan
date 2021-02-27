# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
file(GLOB HEADER_LIST "${phulkan_SOURCE_DIR}/include/phulkan/*.hpp")
file(GLOB SOURCE_LIST ./*.cpp)

# Make an automatic library - will be static or dynamic based on user setting
add_library (phulkan_library ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories (phulkan_library PUBLIC ../include)

# This depends on (header only) boost
# target_link_libraries (modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++20
target_compile_features (phulkan_library PUBLIC cxx_std_20)

# IDEs should put the headers in a nice place
source_group (
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})