cmake_minimum_required(VERSION 3.15)
project(keynote)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Protobuf REQUIRED)
find_package(Boost 1.70 COMPONENTS filesystem REQUIRED)
FILE(GLOB SRCS "../keynote-protos/gen/*.cc")
FILE(GLOB SLIDEOBJECTS "models/SlideObjects/*cpp" "models/SlideObjects/*h")

include_directories(keynote_lib lib/include)

add_library(keynote_lib proto_helper.cpp ${SRCS} ${SLIDEOBJECTS} ../keynote-protos/mapping/ProtoMapping.cpp ../keynote-protos/mapping/ProtoMapping.h proto_helper.h snappy_helper.cpp snappy_helper.h keynote.cpp headers/keynote.h src/svg_to_key/svg_to_key.cpp src/svg_to_key/svg_to_key.h lib/nanosvg/src/nanosvg_impl.cpp src/svg_to_key/common_message_creation.cpp src/svg_to_key/common_message_creation.h src/svg_to_key/nanosvg_helper.cpp src/svg_to_key/nanosvg_helper.h src/key_to_svg/key_to_svg.cpp src/key_to_svg/key_to_svg.h src/key_to_svg/svg_wrapper.cpp src/key_to_svg/svg_wrapper.h lib/nanosvg/src/nanosvg.h src/svg_to_key/shape_creation_repository.cpp src/svg_to_key/shape_creation_repository.h)


include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(keynote_lib ../keynote-protos/gen)

add_subdirectory(lib/nanosvg)
include_directories(keynote_lib lib/nanosvg/src)

target_link_libraries(keynote_lib ${Protobuf_LIBRARIES})
target_link_libraries(keynote_lib nanosvg)

install(TARGETS keynote_lib DESTINATION lib)
install(FILES keynote_lib.h DESTINATION include)

target_link_libraries(keynote_lib ${Protobuf_LIBRARIES})
#target_link_libraries(keynote_lib ${CMAKE_CURRENT_SOURCE_DIR}/lib/libsnappy.a)

find_library(SNAPPY_LIBRARY
    NAMES snappy
    PATHS /usr/local/lib /opt/homebrew/lib
)

if(NOT SNAPPY_LIBRARY)
    message(FATAL_ERROR "Snappy library not found")
endif()

target_link_libraries(keynote_lib ${SNAPPY_LIBRARY})

#set_property(TARGET keynote_lib PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
#set(CMAKE_STATIC_LINKER_FLAGS "-Wl,-dead_strip -Wl,--gc-sections")
