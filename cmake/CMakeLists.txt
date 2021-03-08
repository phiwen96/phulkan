MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    FILE(GLOB cmake_file "${child}/CMakeLists.txt")
    IF(cmake_file)
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()



file (GLOB cmakes *.cmake)

foreach (file ${cmakes})
    include (${file})
endforeach ()

SUBDIRLIST(subdirs ${CMAKE_CURRENT_LIST_DIR})

foreach (folder ${subdirs})
    add_subdirectory (${folder})
    # message (${folder})
endforeach ()

ph_git ()


