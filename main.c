#include "helpers.h"
#include "include/raylib.h"
#include "main_loop.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// window dimensions
uint16_t screenWidth = 512, screenHeight = 512;
uint16_t virtualWidth = 128, virtualHeight = 128;
float scale = 1.0f;

int main(int argc, char** argv) {
  if (argc > 1) {
    scale = atof(argv[1]);
  }
  InitWindow(screenWidth, screenHeight, "Rasterizer");
  SetExitKey(KEY_Q);

  vec2_t vertices[5] = {
      {.x = scale * 64.0f,  .y = scale * 25.0f },  
      {.x = scale * 96.0f,  .y = scale * 72.0f },
      {.x = scale * 16.0f,  .y = scale * 72.0f },  
      {.x = scale * 72.0f,  .y = scale * 100.0f},
      {.x = scale * 100.0f, .y = scale * 32.0f },
  };

  vec2_t center = {.x = scale * (float)virtualWidth / 2, .y = scale * (float)virtualHeight / 2};

  RenderTexture2D framebuffer = LoadRenderTexture(scale * (float)virtualWidth, scale * (float)virtualHeight);
  while (!WindowShouldClose()) {
    Input();
    Update(vertices, center);
    Render(vertices, framebuffer);
  }

  UnloadRenderTexture(framebuffer);
  CloseWindow();

  return 0;
}
