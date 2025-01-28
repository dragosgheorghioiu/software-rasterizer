#include "helpers.h"
#include <math.h>

/*
  Calculate the minimum between three numbers
*/
inline float three_way_min(float x, float y, float z) {
  return (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
}

/*
  Calculate the maximum between three numbers
*/
inline float three_way_max(float x, float y, float z) {
  return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
}

/*
  Get the cross product of two vectors
*/
inline float cross_prod(vec2_t v1, vec2_t v2) {
  return v1.x * v2.y - v2.x * v1.y;
}

/*
  Rotate around the center of the window
*/
void vec2_rotate(vec2_t *v, vec2_t center, float angle) {
  v->x -= center.x;
  v->y -= center.y;
  v->x = v->x * cos(angle) - v->y * sin(angle);
  v->y = v->x * sin(angle) + v->y * cos(angle);
  v->x += center.x;
  v->y += center.y;
}

void draw_triangle(const vec2_t *p1, const vec2_t *p2, const vec2_t *p3,
                   Color color) {
  uint16_t x_min = floor(three_way_min(p1->x, p2->x, p3->x));
  uint16_t y_min = floor(three_way_min(p1->y, p2->y, p3->y));
  uint16_t x_max = ceil(three_way_max(p1->x, p2->x, p3->x));
  uint16_t y_max = ceil(three_way_max(p1->y, p2->y, p3->y));

  float bias0 = raster_rules_bias(p2, p1);
  float bias1 = raster_rules_bias(p3, p2);
  float bias2 = raster_rules_bias(p1, p3);

  for (int i = x_min; i < x_max; ++i) {
    for (int j = y_min; j < y_max; ++j) {
      vec2_t p = {i, j};
      float w0 = edge_cross(p1, p2, &p) + bias0;
      float w1 = edge_cross(p2, p3, &p) + bias1;
      float w2 = edge_cross(p3, p1, &p) + bias2;

      // check if pixel is inside of triangle
      bool is_inside = w0 >= 0 && w1 >= 0 && w2 >= 0;
      if (is_inside) {
        DrawPixel(i, j, color);
      }
    }
  }
}

float edge_cross(const vec2_t *a, const vec2_t *b, const vec2_t *p) {
  vec2_t ab = {.x = b->x - a->x, .y = b->y - a->y};
  vec2_t ap = {.x = p->x - a->x, .y = p->y - a->y};
  return cross_prod(ab, ap);
}

float raster_rules_bias(const vec2_t *a, const vec2_t *b) {
  vec2_t edge = {.x = b->x - a->x, .y = b->y - a->y};
  bool is_flat_top_edge = edge.y == 0 && edge.x > 0;
  bool is_left_edge = edge.y > 0;
  return ((is_left_edge || is_flat_top_edge) ? -0.0001f : 0.0f);
}
