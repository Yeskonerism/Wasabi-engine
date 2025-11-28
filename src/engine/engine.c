#include <time.h>

#include <stdio.h>
#include <unistd.h>

#include "engine.h"
#include "util/log.h"
#include "ecs/ecs.h"
#include <linux/time.h>

int engine_active;

static game_init_fn g_game_init = NULL;
static game_update_fn g_game_update = NULL;
static game_shutdown_fn g_game_shutdown = NULL;

void engine_register_game(game_init_fn gi, game_update_fn gu, game_shutdown_fn gs) {
	g_game_init = gi;
	g_game_update = gu;
	g_game_shutdown = gs;
}

void engine_init(void) {
	printf("***---+| WASABI ENGINE |+---***\n");

	engine_active = 1;
	ecs_init();

	if(g_game_init)
		g_game_init();
}

void engine_update(float dt) {
	if(!engine_active) {
		log_error("Engine not active. Please run engine_init() to initialise engine\n");
		return;
	}

	if(g_game_update)
		g_game_update(dt);

	ecs_update(dt);
}

void engine_shutdown(int ecode) {
	engine_active = 0;

	if(g_game_shutdown)
		g_game_shutdown(ecode);

	ecs_shutdown();

	if(ecode != 0)
		log_error("Engine exited with error code %d.", ecode);
}

void engine_run(void) {
    engine_init();

    const double target = 1.0 / 60.0; // 60 FPS
    struct timespec prev_ts;
    clock_gettime(CLOCK_MONOTONIC, &prev_ts);

    while (engine_active) {
        struct timespec now_ts;
        clock_gettime(CLOCK_MONOTONIC, &now_ts);

        double dt = (now_ts.tv_sec - prev_ts.tv_sec) + (now_ts.tv_nsec - prev_ts.tv_nsec) / 1e9;
        prev_ts = now_ts;

        engine_update((float)dt);

        // frame cap
        if (dt < target) {
            double sleep_sec = target - dt;
            struct timespec sleep_ts = {
                .tv_sec = (time_t)sleep_sec,
                .tv_nsec = (long)((sleep_sec - (time_t)sleep_sec) * 1e9)
            };
            nanosleep(&sleep_ts, NULL);
        }
    }

    /* ensure shutdown sequence runs when loop exits normally */
    engine_shutdown(0);
}