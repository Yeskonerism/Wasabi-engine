#include "ecs/ecs_debug.h"
#include "util/log.h"

void ecs_print(void) {
    for (int e = 0; e < MAX_ENTITIES; e++) {
        if (!ecs_has_position(e))
            continue;

        float x = 0.0f, y = 0.0f;
        ecs_get_position(e, &x, &y);

        log_info("Entity %d - (%.2f, %.2f)\n", e, x, y);
    }
}

void ecs_entity_print(Entity e) {
    if (!ecs_has_position(e)) {
        log_info("Entity of ID %d not active.\n", e);
        return;
    }

    float x = 0.0f, y = 0.0f;
    ecs_get_position(e, &x, &y);

    log_info("Entity %d - (%.2f, %.2f)\n", e, x, y);
}