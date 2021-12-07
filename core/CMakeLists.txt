cmake_minimum_required (VERSION 3.8)

add_subdirectory(entity)
add_subdirectory(ui)
add_subdirectory(map)
add_subdirectory(states)

add_executable (demo "demo.cpp")

if (WIN32)
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
endif (WIN32)

if (UNIX)
	target_include_directories (demo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")
	target_link_libraries (demo box2d-lib input-lib ui-lib logging-lib entity-lib gameui-lib resources-pool-lib map-lib states-lib)
	target_link_libraries(demo sfml-graphics sfml-window sfml-system)
endif (UNIX)