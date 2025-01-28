#include "main_loop.h"
#include <stdint.h>

static bool show_triangle_1 = true;
static bool show_triangle_2 = true;
static bool show_triangle_3 = true;
static bool enable_rotation = true;

extern uint16_t screenWidth, screenHeight;
extern uint16_t virtualWidth, virtualHeight;

void Render(vec2_t *vertices, RenderTexture2D framebuffer) {
  BeginTextureMode(framebuffer);
  ClearBackground(BLACK);
  if (show_triangle_1) {
    draw_triangle(&vertices[0], &vertices[1], &vertices[2], RED);
  }
  if (show_triangle_2) {
    draw_triangle(&vertices[3], &vertices[2], &vertices[1], BLUE);
  }
  if (show_triangle_3) {
    draw_triangle(&vertices[4], &vertices[1], &vertices[0], GREEN);
  }
  EndTextureMode();

  BeginDrawing();
  ClearBackground(BLACK);

  DrawTexturePro(framebuffer.texture,
                 (Rectangle){0, 0, virtualWidth, -virtualHeight},
                 (Rectangle){0, 0, screenWidth, screenHeight}, (Vector2){0, 0},
                 0.0f, WHITE);

  EndDrawing();
}

void Update(vec2_t *vertices, vec2_t center) {
  float angle = 0;
  if (enable_rotation) {
    angle = 0.2f * GetFrameTime();
  } else {
    angle = 0.0f;
  }

  // rotate all the vertexes
  for (int i = 0; i < 5; ++i) {
    vec2_rotate(&vertices[i], center, angle);
  }
}

void Input() {
  if (IsKeyPressed(KEY_ONE)) {
    show_triangle_1 = !show_triangle_1;
  }
  if (IsKeyPressed(KEY_TWO)) {
    show_triangle_2 = !show_triangle_2;
  }
  if (IsKeyPressed(KEY_THREE)) {
    show_triangle_3 = !show_triangle_3;
  }
  if (IsKeyPressed(KEY_SPACE)) {
    enable_rotation = !enable_rotation;
  }
}
