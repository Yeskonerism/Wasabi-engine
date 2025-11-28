#ifndef __ECS_COMPONENTS_H__
#define __ECS_COMPONENTS_H__

#include "engine/engine_def.h"

// position component
typedef struct {
	int active[MAX_ENTITIES];
	float x[MAX_ENTITIES];
	float y[MAX_ENTITIES];
} PositionComponent;

// velocity component
typedef struct {
	int active[MAX_ENTITIES];
	float vx[MAX_ENTITIES];
	float vy[MAX_ENTITIES];
} VelocityComponent;

#endif