set (MAP_SOURCE_FILES "tile.cpp")
set (MAP_HEADER_FILES "include/gamemap/tile.h")

add_library (map-lib ${MAP_SOURCE_FILES} ${MAP_HEADER_FILES})

target_link_libraries (map-lib box2d-lib)
target_include_directories(map-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")