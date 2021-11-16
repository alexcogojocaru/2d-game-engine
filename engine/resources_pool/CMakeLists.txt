set (RESOURCES_POOL_SOURCE_FILES "texture_manager.cpp")
set (RESOURCES_POOL_HEADER_FILES "include/resources_pool/texture_manager.h")

add_library (resources-pool-lib ${RESOURCES_POOL_SOURCE_FILES} ${RESOURCES_POOL_HEADER_FILES})

target_link_libraries (resources-pool-lib box2d-lib logging-lib)
target_include_directories(resources-pool-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")