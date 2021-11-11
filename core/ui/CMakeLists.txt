set (GAMEUI_SOURCE_FILES "healthbar.cpp")
set (GAMEUI_HEADER_FILES "include/gameui/healthbar.h")

add_library (gameui-lib ${GAMEUI_SOURCE_FILES} ${GAMEUI_HEADER_FILES})

target_link_libraries (gameui-lib box2d-lib ui-lib)
target_include_directories(gameui-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")