#ifndef __ENGINE_H__
#define __ENGINE_H__

void engine_init(void);
void engine_update(float dt);
void engine_shutdown(int ecode);

void engine_run(void);

// engine to game api
typedef void (*game_init_fn)(void);
typedef void (*game_update_fn)(float);
typedef void (*game_shutdown_fn)(int);

void engine_register_game(game_init_fn gi, game_update_fn gu, game_shutdown_fn gs);

#endif