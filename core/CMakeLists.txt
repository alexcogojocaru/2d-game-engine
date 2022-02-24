cmake_minimum_required (VERSION 3.8)

add_subdirectory(entity)
add_subdirectory(ui)
add_subdirectory(map)
add_subdirectory(states)

add_executable (demo "demo.cpp")
target_compile_features (demo PRIVATE cxx_std_17)

target_link_libraries (demo box2d-lib 
	input-lib 
	ui-lib 
	logging-lib 
	entity-lib 
	gameui-lib
	resources-pool-lib
	map-lib
	states-lib
)

target_link_libraries (demo 
	${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-network.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-system.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-window.lib
)

add_executable (TheRuinedKing "game.cpp")
target_compile_features (TheRuinedKing PRIVATE cxx_std_17)

target_link_libraries (TheRuinedKing box2d-lib 
	input-lib 
	ui-lib 
	logging-lib 
	entity-lib 
	gameui-lib
	resources-pool-lib
	map-lib
	states-lib
)

target_link_libraries (TheRuinedKing 
	${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-network.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-system.lib
	${CMAKE_SOURCE_DIR}/lib/sfml-window.lib
)