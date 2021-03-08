cmake_minimum_required (VERSION 3.19.6)

get_filename_component (self ${CMAKE_CURRENT_SOURCE_DIR} NAME)


find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        # execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        #                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        #                 RESULT_VARIABLE GIT_SUBMOD_RESULT)
		execute_process(
			COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
			COMMAND ${GIT_EXECUTABLE} submodule update --remote --merge #submodule update --remote --merge --init --recursive

						# COMMAND ${GIT_EXECUTABLE} submodule foreach git pull main
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT
		)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()


project (
	${self} 
	VERSION 1.0
	DESCRIPTION "Very nice project"
	LANGUAGES CXX
)	

add_subdirectory (cmake/phake)

# add_subdirectory (dependencies/phake)

# ph_git ()


# add_subdirectory (dependencies/const_str)
add_subdirectory (dependencies/phulkan_generator)

# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	
	# Let's ensure -std=g++xx instead of -std=c++xx
	set (CMAKE_CXX_STANDARD 20)
	set (CMAKE_CXX_STANDARD_REQUIRED ON)
	set (CMAKE_CXX_EXTENSIONS ON)

	# Let's nicely support folders in IDEs
	set_property (GLOBAL PROPERTY USE_FOLDERS ON)

	find_package (Boost 1.75 REQUIRED)
	find_package (Vulkan REQUIRED)
	find_package (glfw3 REQUIRED)
	find_package (glm REQUIRED)

	# Testing only available if this is the main app
	# Note this needs to be done in the main CMakeLists
	# since it calls enable_testing, which must be in the
	# main CMakeLists.
	include (CTest)



   # Docs only available if this is the main app
   	# find_package (Doxygen)

	# if (Doxygen_FOUND)
	# 	add_subdirectory (docs)
   	# else()
    #  		message(STATUS "Doxygen not found, not building docs")
   	# endif()


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



find_program (DOT_EXE "dot")

if(DOT_EXE)
    message(STATUS "dot found: ${DOT_EXE}")
else()
    message(STATUS "dot not found!")
endif()

set(DOT_OUTPUT_TYPE "png" CACHE STRING "Build a dependency graph. Options are dot output types: ps, png, pdf..." )


if(DOT_EXE)
    add_custom_target(dependency-graph
        COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} --graphviz=${CMAKE_BINARY_DIR}/graphviz/${PROJECT_NAME}.dot
        COMMAND ${DOT_EXE} -T${DOT_OUTPUT_TYPE} ${CMAKE_BINARY_DIR}/graphviz/${PROJECT_NAME}.dot -o ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.${DOT_OUTPUT_TYPE}
    )

    add_custom_command(
        TARGET dependency-graph POST_BUILD
        COMMAND ;
        COMMENT
        "Dependency graph generated and located at ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.${DOT_OUTPUT_TYPE}"
    )
endif()