#ifndef GAME_H
#define GAME_H

#include "land.h"
#include "menu.h"

#include <raylib.h>

#define GAME_WIDTH 100
#define GAME_HEIGHT 100

typedef struct {
    Land* land;
    Menu* menu;
    RenderTexture2D framebuffer;
} Game;

extern Game* game;

void game_start(void);
void game_close(void);

#endif /* GAME_H */
