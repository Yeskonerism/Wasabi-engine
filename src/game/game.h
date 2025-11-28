#ifndef __GAME_H__
#define __GAME_H__

#include "engine/engine.h"

void game_init(void);
void game_update(float dt);
void game_shutdown(int code);

#endif