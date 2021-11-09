set (INPUT_SOURCE_FILES keyboard_input.cpp)
set (INPUT_HEADER_FILES include/input/input_properties.h include/input/keyboard_input.h)

add_library (input-lib ${INPUT_SOURCE_FILES} ${INPUT_HEADER_FILES} "include/input/controller_input.h" "controller_input.cpp")

target_link_libraries (input-lib box2d-lib)
target_include_directories(input-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")