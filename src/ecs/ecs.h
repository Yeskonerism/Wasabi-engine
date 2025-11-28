#ifndef __ECS_H__
#define __ECS_H__

#include "engine/engine_def.h"
#include "ecs/ecs_components.h"

typedef int Entity;

void ecs_init(void);
void ecs_update(float dt);
void ecs_shutdown(void);

Entity ecs_create(void);
void ecs_kill(Entity e);

int ecs_entity_active(Entity e);

void ecs_entity_activate(Entity e);
void ecs_entity_deactivate(Entity e);

int ecs_has_position(Entity e);
void ecs_set_position(Entity e, float x, float y);
void ecs_get_position(Entity e, float* out_x, float* out_y);
void ecs_zero_position(Entity e);
void ecs_activate_position(Entity e);
void ecs_deactivate_position(Entity e);

int ecs_has_velocity(Entity e);
void ecs_set_velocity(Entity e, float vx, float vy);
void ecs_get_velocity(Entity e, float* out_vx, float* out_vy);
void ecs_zero_velocity(Entity e);
void ecs_activate_velocity(Entity e);
void ecs_deactivate_velocity(Entity e);

void ecs_print(void);
void ecs_entity_print(Entity e);

#endif // __ECS_H__