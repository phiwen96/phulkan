# add_executable(app app.cpp)
# target_compile_features(app PRIVATE cxx_std_20)
# target_link_libraries(app PRIVATE phulkan_library)

# add_executable(app2 app2.cpp)
# target_compile_features(app2 PRIVATE cxx_std_20)
# target_link_libraries(app2 PRIVATE phulkan_library)


# add_custom_target (run_app2 app)
# add_custom_command (TARGET run_app2 PRE_BUILD COMMAND app2)

# add_custom_target(run_app2
#   COMMAND app2
#   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#   COMMENT "run generated test2 in ${CMAKE_CURRENT_SOURCE_DIR}"
#   SOURCES app2.cpp
# )
# add_dependencies(app run_app2)


