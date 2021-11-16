set(STATE_SOURCE_FILES "menu_state.cpp")
set(STATE_HEADER_FILES "include/state/state.h" "include/state/menu_state.h")

add_library(states-lib ${STATE_SOURCE_FILES} ${STATE_HEADER_FILES} "state.cpp")

target_link_libraries(states-lib box2d-lib gameui-lib resources-pool-lib logging-lib)
target_include_directories(states-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")