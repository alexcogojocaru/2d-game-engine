set (UI_SOURCE_FILES button.cpp)
set (UI_HEADER_FILES include/ui/button.h)

add_library (ui-lib ${UI_SOURCE_FILES} ${UI_HEADER_FILES} "include/ui/ui.h" "include/ui/icon.h" "icon.cpp"  )

target_link_libraries (ui-lib box2d-lib)
target_include_directories(ui-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")