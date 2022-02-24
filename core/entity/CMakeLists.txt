set (ENTITY_SOURCE_FILES "entity.cpp" "player.cpp" "enemy.cpp" "animation.cpp" "item.cpp" "drawable.cpp")
set (ENTITY_HEADER_FILES 
	"include/entity/entity.h" 
	"include/entity/player.h" 
	"include/entity/properties.h" 
	"include/entity/enemy.h" 
	"include/entity/animation.h"
	"include/entity/drawable.h"
	"include/items/item.h"
)

add_library (entity-lib ${ENTITY_SOURCE_FILES} ${ENTITY_HEADER_FILES} "include/items/weapon.h" "weapon.cpp"   "include/items/collider.h" "collider.cpp" "include/entity/entities.h" "include/items/items.h" )

target_link_libraries (entity-lib box2d-lib input-lib gameui-lib resources-pool-lib)
target_include_directories(entity-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")