add_library(nanosvg INTERFACE)
target_sources(nanosvg INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/nanosvg.h)
target_include_directories(nanosvg INTERFACE ../src/nanosvg.h)