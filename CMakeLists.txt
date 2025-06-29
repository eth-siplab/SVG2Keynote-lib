cmake_minimum_required(VERSION 3.15)
project(keynote)
enable_language(OBJC)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.70 COMPONENTS filesystem REQUIRED)

add_subdirectory(zipper)
add_subdirectory(keynote_lib)

# Add svg2key.m to the list of source files
add_executable(svg2key svg2key.mm keynote_lib/src/key_to_svg/svg_wrapper.cpp keynote_lib/src/key_to_svg/svg_wrapper.h)
target_link_libraries(svg2key Boost::filesystem)
target_link_libraries(svg2key staticZipper)

target_include_directories(svg2key PUBLIC keynote_lib)
target_link_directories(svg2key PRIVATE keynote_lib)
target_link_libraries(svg2key keynote_lib)

# Link Objective-C frameworks
find_library(COCOA_LIBRARY Cocoa)
target_link_libraries(svg2key ${COCOA_LIBRARY})
