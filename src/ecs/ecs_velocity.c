#include "ecs/ecs_velocity.h"

static VelocityComponent g_vel;

int ecs_has_velocity(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return 0;
    return g_vel.active[e];
}

void ecs_set_velocity(Entity e, float vx, float vy) {
    if (e < 0 || e >= MAX_ENTITIES) return;

    /* activate this component and set values (do not require other components) */
    g_vel.active[e] = 1;
    g_vel.vx[e] = vx;   /* use assignment, not += */
    g_vel.vy[e] = vy;
}

void ecs_get_velocity(Entity e, float* out_vx, float* out_vy) {
    if (out_vx) *out_vx = 0.0f;
    if (out_vy) *out_vy = 0.0f;

    if (e < 0 || e >= MAX_ENTITIES) return;
    if (!g_vel.active[e]) return;

    if (out_vx) *out_vx = g_vel.vx[e];
    if (out_vy) *out_vy = g_vel.vy[e];
}

void ecs_zero_velocity(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_vel.active[e] = 0;
    g_vel.vx[e] = 0;
    g_vel.vy[e] = 0;
}

void ecs_activate_velocity(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_vel.active[e] = 1;
}

void ecs_deactivate_velocity(Entity e) {
    if (e < 0 || e >= MAX_ENTITIES) return;
    g_vel.active[e] = 0;
}