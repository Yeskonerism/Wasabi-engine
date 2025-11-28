#include "ecs/ecs_position.h"

static PositionComponent g_pos;

int ecs_has_position(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return 0;
    return g_pos.active[e];
}

void ecs_set_position(Entity e, float x, float y) {
    if (e < 0 || e >= MAX_ENTITIES) return;

    /* activate this component and set values (do not require other components) */
    g_pos.active[e] = 1;
    g_pos.x[e] = x;   /* use assignment, not += */
    g_pos.y[e] = y;
}

void ecs_get_position(Entity e, float* out_x, float* out_y) {
    if (out_x) *out_x = 0.0f;
    if (out_y) *out_y = 0.0f;

    if (e < 0 || e >= MAX_ENTITIES) return;
    if (!g_pos.active[e]) return;

    if (out_x) *out_x = g_pos.x[e];
    if (out_y) *out_y = g_pos.y[e];
}

void ecs_zero_position(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_pos.active[e] = 0;
    g_pos.x[e] = 0;
    g_pos.y[e] = 0;
}

void ecs_activate_position(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_pos.active[e] = 1;
}

void ecs_deactivate_position(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_pos.active[e] = 0;
}