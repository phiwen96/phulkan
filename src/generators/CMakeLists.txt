add_executable (gpus_info_generator 
	${CMAKE_CURRENT_SOURCE_DIR}/generators/number_of_gpus.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/generators/number_of_gpus.hpp
)

target_link_libraries(gpus_info_generator
	PUBLIC 
	/Users/pw/vulkansdk/MoltenVK/dylib/macOS/libMoltenVK.dylib 
	/Users/pw/vulkansdk/macOS/lib/libVkLayer_khronos_validation.dylib
	/Users/pw/vulkansdk/macOS/lib/libvulkan.1.2.162.dylib
	glfw
)

target_include_directories(gpus_info_generator PUBLIC 
	# /Users/pw/vulkansdk/macOS/include
	/Users/pw/vulkansdk/MoltenVK/include 
	glfw
	/usr/local/Cellar/boost/1.75.0_1/include
)

# add_custom_command (
# 	OUTPUT gpus_info.hpp 
# 	PRE_BUILD
# 	COMMAND gpus_info_generator 
# 	# "${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp"
# 	)

# target_compile_definitions (graphics_number_of_gpus_generator PUBLIC TEMPLATE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp")



add_executable (graphics_generator 
	${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics.cpp 
	${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/generators/graphics_template.hpp
	# ${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp
)



add_custom_command (
	TARGET graphics_generator
	# OUTPUT gpus_info.hpp 
	PRE_BUILD
	COMMAND gpus_info_generator snopp.txt#gpus_info.hpp
	# WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	# ARGS ${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp
	# "${CMAKE_CURRENT_BINARY_DIR}/gpus_info.hpp"
	)
# target_sources(graphics_generator PRIVATE )
# message("$<TARGET_FILE_DIR:graphics_generator>")

# add_custom_command(testing
# 	PRE_BUILD 
# 	COMMAND open .
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
	${CMAKE_CURRENT_BINARY_DIR}
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


# try_run (
#     # Name of variable to store the run result (process exit status; number) in:
#     test_run_result

#     # Name of variable to store the compile result (TRUE or FALSE) in:
#     test_compile_result

#     # Binary directory:
#     ${CMAKE_CURRENT_BINARY_DIR}/

#     # Source file to be compiled:
#     "${CMAKE_CURRENT_SOURCE_DIR}/generators/number_of_gpus.cpp"

#     # Where to store the output produced during compilation:
#     COMPILE_OUTPUT_VARIABLE test_compile_output

#     # Where to store the output produced by running the compiled executable:
#     RUN_OUTPUT_VARIABLE test_run_output)

    # Did compilation succeed and process return 0 (success)?
# IF("${test_compile_result}" AND ("${test_run_result}" EQUAL 0))
# # Strip whitespace (such as the trailing newline from std::endl)
# # from the produced output:
# STRING(STRIP "${test_run_output}" test_run_output)
# ELSE()
# # Error on failure and print error message:
# MESSAGE(FATAL_ERROR "Failed check!")
# ENDIF()