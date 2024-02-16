#include "game.h"
#include <stddef.h>

void land_load(Land* land) {
    game->land = land;
}

void land_update(Land* land) {
    if (land->update) land->update();
}

void land_unload(Land* land) {
    game->land = NULL;
}