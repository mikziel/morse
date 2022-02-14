#include "gfx.h"
#include "macros.h"

void draw_pixel(int x, int y, int color)
{
  MEM_VRAM[x + y * SCREEN_WIDTH] = color;
}

void clear_screen(void)
{
  for (int y = 0; y < SCREEN_HEIGHT; y++)
    for (int x = 0; x < SCREEN_WIDTH; x++)
      draw_pixel(x, y, COLOR_BLACK);
}