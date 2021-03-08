



file (GLOB cmakes *.cmake)

foreach (file ${cmakes})
    include (${file})
endforeach ()

ph_git ()


