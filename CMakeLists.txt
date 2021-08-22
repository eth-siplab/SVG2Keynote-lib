cmake_minimum_required(VERSION 3.15)
project(keynote)

set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.70 COMPONENTS filesystem REQUIRED)

add_subdirectory(zipper)
add_subdirectory(keynote_lib)

add_executable(keynote main.cpp ${SRCS} keynote_lib/src/key_to_svg/svg_wrapper.cpp keynote_lib/src/key_to_svg/svg_wrapper.h)
target_link_libraries(keynote Boost::filesystem)
target_link_libraries(keynote staticZipper)

target_include_directories(keynote PUBLIC keynote_lib)
target_link_directories(keynote PRIVATE keynote_lib)
target_link_libraries(keynote keynote_lib)