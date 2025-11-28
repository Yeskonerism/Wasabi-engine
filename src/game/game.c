#include "engine/engine.h"
#include "util/log.h"
#include "ecs/ecs.h"

#include "game.h"

extern int engine_active;

int cycles = 0;

void game_init(void) {
    log_info("Game init\n");

    Entity ent = ecs_create();
    
    if(ent != -1) {
        ecs_set_position(ent, 0, 0);
        ecs_set_velocity(ent, 2, 2);
    }
}

void game_update(float dt) {
    ecs_print();

    cycles++;

    if(MAX_FPS == cycles)
        engine_active = 0;
}

void game_shutdown(int code) {
    log_info("Game shutdown, code %d\n", code);
}

// register game module with the engine
void game_register_with_engine(void) {
    engine_register_game(game_init, game_update, game_shutdown);
}