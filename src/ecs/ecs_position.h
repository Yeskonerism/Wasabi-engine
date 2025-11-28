#ifndef __ECS_POSITION_H__
#define __ECS_POSITION_H__

#include "ecs/ecs.h"

int ecs_has_position(Entity e);
void ecs_set_position(Entity e, float x, float y);
void ecs_get_position(Entity e, float* out_x, float* out_y);
void ecs_zero_position(Entity e);

void ecs_activate_position(Entity e);
void ecs_deactivate_position(Entity e);

#endif