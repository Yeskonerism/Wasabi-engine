#include <stdio.h>

#include "ecs/ecs.h"
#include "util/log.h"

void ecs_init(void) {
	for(int e = 0; e < MAX_ENTITIES; e++) {
		ecs_zero_position(e);
		ecs_zero_velocity(e);
	}
}

void ecs_update(float dt) {
    // apply velocity
    for (int e = 0; e < MAX_ENTITIES; e++) {
        /* require both components to be present; otherwise skip */
        if (!ecs_has_velocity(e) || !ecs_has_position(e))
            continue;

        float vx = 0.0f, vy = 0.0f;
        ecs_get_velocity(e, &vx, &vy);

        /* apply even if only one axis moves (use OR) */
        if (vx == 0.0f && vy == 0.0f)
            continue;

        float x = 0.0f, y = 0.0f;
        ecs_get_position(e, &x, &y);

        x += vx * dt;
        y += vy * dt;

        ecs_set_position(e, x, y);
    }
}

void ecs_shutdown(void) {
	for(int e = 0; e < MAX_ENTITIES; e++) {
		ecs_zero_position(e); 
		ecs_zero_velocity(e);
	}
}