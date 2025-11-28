#ifndef __ECS_VELOCITY_H__
#define __ECS_VELOCITY_H__

#include "ecs/ecs.h"

int ecs_has_velocity(Entity e);
void ecs_set_velocity(Entity e, float vx, float vy);
void ecs_get_velocity(Entity e, float* out_vx, float* out_vy);
void ecs_zero_velocity(Entity e);
void ecs_activate_velocity(Entity e);
void ecs_deactivate_velocity(Entity e);

#endif