#include <stddef.h>
#include "raylib.h"
#include "raylib-nuklear.h"

int main(void) {
    InitWindow(800, 450, "Raylib + Nuklear Test");
    SetTargetFPS(60);

    // Initialize Nuklear with default Raylib font (size 10pt)
    struct nk_context *ctx = InitNuklear(10);

    while (!WindowShouldClose()) {
        // Send Raylib input events to Nuklear
        UpdateNuklear(ctx);

        // Create UI Layout
        if (nk_begin(ctx, "Nuklear Demo", nk_rect(50, 50, 220, 200),
                     NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE)) {
            
            nk_layout_row_static(ctx, 30, 120, 1);
            if (nk_button_label(ctx, "Click Me")) {
                TraceLog(LOG_INFO, "Nuklear Button Clicked!");
            }
        }
        nk_end(ctx);

        // Render
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawNuklear(ctx);
        EndDrawing();
    }

    UnloadNuklear(ctx);
    CloseWindow();
    return 0;
}