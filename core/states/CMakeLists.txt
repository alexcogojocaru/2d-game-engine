set(STATE_SOURCE_FILES "menu_state.cpp" "play_state.cpp" "state.cpp")
set(STATE_HEADER_FILES "include/state/state.h" "include/state/menu_state.h" "include/state/play_state.h")

add_library(states-lib ${STATE_SOURCE_FILES} ${STATE_HEADER_FILES})

target_link_libraries(states-lib box2d-lib gameui-lib resources-pool-lib logging-lib gameui-lib entity-lib map-lib)
target_include_directories(states-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")