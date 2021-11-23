set (ENTITY_SOURCE_FILES "entity.cpp" "player.cpp")
set (ENTITY_HEADER_FILES "include/entity/entity.h" "include/entity/player.h" "include/entity/properties.h")

add_library (entity-lib ${ENTITY_SOURCE_FILES} ${ENTITY_HEADER_FILES})

target_link_libraries (entity-lib box2d-lib input-lib gameui-lib resources-pool-lib Candle-s)
target_include_directories(entity-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")