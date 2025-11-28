#include "ecs/ecs_entity.h"

Entity ecs_create(void) {
    for(int e = 0; e < MAX_ENTITIES; e++) {
        if(!ecs_entity_active(e)) {
            /* activate components to make entity usable immediately */
            ecs_activate_position(e);
            ecs_zero_position(e);   /* ensure zeroed */
            ecs_activate_velocity(e);
            ecs_zero_velocity(e);
            return e;
        }
    }

    return -1;
}

void ecs_kill(Entity e) {
    if(e < 0 || e >= MAX_ENTITIES) return;
    if(ecs_entity_active(e)) {
        ecs_zero_position(e);
        ecs_zero_velocity(e);
    }
}

int ecs_entity_active(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return 0;
    return ecs_has_position(e) && ecs_has_velocity(e);
}

void ecs_entity_activate(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    ecs_activate_velocity(e);
    ecs_activate_position(e);
}

void ecs_entity_deactivate(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    ecs_deactivate_velocity(e);
    ecs_deactivate_position(e);
}