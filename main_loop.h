#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include "helpers.h"

#include <stdbool.h>

void Input();
void Render(vec2_t *vertices, RenderTexture2D framebuffer);
void Update(vec2_t *vertices, vec2_t center);

#endif // MAIN_LOOP_H
