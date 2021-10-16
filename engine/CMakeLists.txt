cmake_minimum_required (VERSION 3.8)

add_subdirectory (fsm)
add_subdirectory (input)

add_executable (
	engine
	"engine.cpp"
	"entity.cpp"
	"entity.h"
 "properties.h")


if (WIN32)
	target_link_libraries (engine box2d-lib input-lib)
	target_link_libraries (engine 
		${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-network.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-system.lib
		${CMAKE_SOURCE_DIR}/lib/sfml-window.lib
	)
endif (WIN32)

if (UNIX)
	target_include_directories (engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
	target_link_libraries (engine box2d-lib input-lib)
	target_link_libraries(engine sfml-graphics sfml-window sfml-system)
endif (UNIX)