#include <stdio.h>

#include "engine/engine.h"
#include "engine/engine_def.h"

#include "ecs/ecs.h"

#include "game/game.h"

extern void game_register_with_engine(void);

int main(void) {
	game_register_with_engine();
	engine_run();
	return 0;
}