
if(NOT "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitinfo.txt" IS_NEWER_THAN "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/pw/GitHub/phulkan/xbuild/_deps/catch-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/local/bin/git"  clone --no-checkout "https://github.com/catchorg/Catch2.git" "catch-src"
    WORKING_DIRECTORY "/Users/pw/GitHub/phulkan/xbuild/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/catchorg/Catch2.git'")
endif()

execute_process(
  COMMAND "/usr/local/bin/git"  checkout v2.9.1 --
  WORKING_DIRECTORY "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v2.9.1'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/local/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/pw/GitHub/phulkan/xbuild/_deps/catch-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitinfo.txt"
    "/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/catch-populate-gitclone-lastrun.txt'")
endif()

