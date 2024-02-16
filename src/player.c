#include "player.h"
#include <raylib.h>

void player_update(Player* player) {
    
    if (!player->control) return;

    Vector3 movement = {0, 0, 0};
    if (IsKeyPressed(KEY_W)) {
        movement.y = 1;
    }
    if (IsKeyPressed(KEY_S)) {
        movement.y = -1;
    }

    UpdateCameraPro(&player->camera, movement, (Vector3){0, 1, 0}, 90);
}