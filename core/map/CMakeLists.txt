set (MAP_SOURCE_FILES "wall.cpp")
set (MAP_HEADER_FILES "include/gamemap/wall.h")

add_library (map-lib ${MAP_SOURCE_FILES} ${MAP_HEADER_FILES}  "include/gamemap/map.h" "map.cpp" "include/gamemap/seed_generator.h" "seed_generator.cpp")

target_link_libraries (map-lib box2d-lib)
target_include_directories(map-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")