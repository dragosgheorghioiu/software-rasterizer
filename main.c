#include "helpers.h"
#include "include/raylib.h"
#include "main_loop.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// window dimensions
uint16_t screenWidth = 512, screenHeight = 512;
uint16_t virtualWidth = 128, virtualHeight = 128;

int main(void) {
  InitWindow(screenWidth, screenHeight, "Rasterizer");

  vec2_t vertices[5] = {
      {.x = 64.0f, .y = 25.0f},  {.x = 96.0f, .y = 72.0f},
      {.x = 16.0f, .y = 72.0f},  {.x = 72.0f, .y = 100.0f},
      {.x = 120.0f, .y = 32.0f},
  };

  vec2_t center = {.x = (float)virtualWidth / 2, .y = (float)virtualHeight / 2};

  RenderTexture2D framebuffer = LoadRenderTexture(virtualWidth, virtualHeight);

  while (!WindowShouldClose()) {
    Input();
    Update(vertices, center);
    Render(vertices, framebuffer);
  }

  UnloadRenderTexture(framebuffer);
  CloseWindow();

  return 0;
}
