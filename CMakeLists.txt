cmake_minimum_required (VERSION 3.19.6)

get_filename_component (self ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project (
	${self} 
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX)	

# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	
	# Let's ensure -std=g++xx instead of -std=c++xx
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)
	set (CMAKE_CXX_EXTENSIONS ON)

	# Let's nicely support folders in IDEs
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)

	# Testing only available if this is the main app
	# Note this needs to be done in the main CMakeLists
	# since it calls enable_testing, which must be in the
	# main CMakeLists.
	include (CTest)



   # Docs only available if this is the main app
   	find_package (Doxygen)

	if (Doxygen_FOUND)
		add_subdirectory (docs)
   	else()
     		message(STATUS "Doxygen not found, not building docs")
   	endif()


	find_package(Vulkan REQUIRED)
	find_package(glfw3 REQUIRED)
	find_package(glm REQUIRED)

endif()
 
include (FetchContent)
include (WriteCompilerDetectionHeader)


# The compiled library code is here
add_subdirectory (src)

# The executable code is here
add_subdirectory (apps)



# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
	add_subdirectory (tests)
endif()





# add_library (${self} STATIC two.cpp three.h)

# target_include_directories (${self} PUBLIC include)