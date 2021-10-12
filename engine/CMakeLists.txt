cmake_minimum_required (VERSION 3.8)

add_subdirectory (fsm)

add_executable (
	engine
	"engine.cpp"
	"entity.cpp"
	"entity.h"
 "properties.h")

target_link_libraries (engine box2d-lib)
target_link_libraries (engine 
	${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-network.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-system.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-window.lib
)
