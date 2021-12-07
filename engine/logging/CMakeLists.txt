set (LOGGING_HEADER_FILES "include/logging/log.h")

add_library (logging-lib ${LOGGING_HEADER_FILES} "log.cpp")
set_target_properties(logging-lib PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries (logging-lib)
target_include_directories(logging-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")