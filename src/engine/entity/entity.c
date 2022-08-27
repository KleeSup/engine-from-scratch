#include "../array_list.h"
#include "../entity.h"

static Array_List *entity_list;

void entity_init(void)
{
	entity_list = array_list_create(sizeof(Entity), 0);
}

usize entity_create(vec2 position, vec2 size, vec2 velocity, u8 collision_layer, u8 collision_mask, On_Hit on_hit, On_Hit_Static on_hit_static)
{
	vec2_scale(size, size, 0.5);

	Entity entity = {
		.body_id = physics_body_create(position, size, velocity, collision_layer, collision_mask, on_hit, on_hit_static),
		.is_active = true,
	};

	return array_list_append(entity_list, &entity);
}

Entity *entity_get(usize id)
{
	return array_list_get(entity_list, id);
}

usize entity_count()
{
	return entity_list->len;
}

