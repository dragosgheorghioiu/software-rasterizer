#ifndef HELPERS_H
#define HELPERS_H

#include "include/raylib.h"
#include <stdint.h>

typedef struct {
  float x;
  float y;
} vec2_t;

float three_way_max(float x, float y, float z);
float three_way_min(float x, float y, float z);

float cross_prod(vec2_t v1, vec2_t v2);
float edge_cross(const vec2_t *a, const vec2_t *b, const vec2_t *p);

float raster_rules_bias(const vec2_t *a, const vec2_t *b);

void draw_triangle(const vec2_t *p1, const vec2_t *p2, const vec2_t *p3,
                   Color color);

void vec2_rotate(vec2_t *v, vec2_t center, float angle);

#endif // HELPERS_H
