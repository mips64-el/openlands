#include "game.h"

#include <raylib.h>
#include <stddef.h>

#define MAX(a, b) ((a)>(b)? (a) : (b))
#define MIN(a, b) ((a)<(b)? (a) : (b))

void game_update(void);

Game* game;

void game_start() {
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "test");

    Game g = (Game) {
        .land = NULL,
        .menu = NULL,
        .framebuffer = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT),
    };

    game = &g;

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    while (!WindowShouldClose()) game_update();
    UnloadRenderTexture(g.framebuffer); 
    CloseWindow();
}

void game_update() {
    RenderTexture2D* fb = &game->framebuffer;
    BeginTextureMode(*fb);
        ClearBackground(RAYWHITE);
        DrawText("hello", 20, 20, 30, LIGHTGRAY);
    EndTextureMode();
    
    float screenWidth = GetScreenWidth();
    float screenHeight = GetScreenHeight();

    float scale = MIN(screenWidth/GAME_WIDTH, screenHeight/GAME_HEIGHT);
    BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(
            fb->texture, 
            (Rectangle) {0.f, 0.f, fb->texture.width, -fb->texture.height},
            (Rectangle) {
                (screenWidth - (GAME_WIDTH*scale))*0.5f, 
                (screenHeight - (GAME_HEIGHT*scale))*0.5f, 
                GAME_WIDTH*scale, 
                GAME_HEIGHT*scale
            },
            (Vector2) {0, 0},
            0,
            WHITE
        );
    EndDrawing();
}

void game_close() {
    CloseWindow();
}