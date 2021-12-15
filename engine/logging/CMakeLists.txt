set (LOGGING_HEADER_FILES "include/logging/log.h")

add_library (logging-lib ${LOGGING_HEADER_FILES} "log.cpp")

target_include_directories(logging-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")