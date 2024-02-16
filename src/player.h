#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>

typedef struct {
    Vector3 position;
    bool control;
    Camera3D camera;
} Player;

void player_update(Player*);

#endif /* PLAYER_H */
