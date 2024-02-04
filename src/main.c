#include <stdio.h>
#include <raylib.h>

int main() {
    
    InitWindow(640, 480, "test");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("hello!", 20, 20, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
