set(STATE_SOURCE_FILES state.cpp)
set(STATE_HEADER_FILES include/state/state.h include / input / keyboard_input.h)

add_library(states-lib ${STATE_SOURCE_FILES} ${STATE_HEADER_FILES})

target_link_libraries(states-lib box2d-lib)
target_include_directories(states-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")