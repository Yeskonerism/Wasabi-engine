#ifndef __ECS_ENTITY_H__
#define __ECS_ENTITY_H__

#include "ecs/ecs.h"

Entity ecs_create(void);
void ecs_kill(Entity e);

int ecs_entity_active(Entity e);

void ecs_entity_activate(Entity e);
void ecs_entity_deactivate(Entity e);

#endif