#include <stdlib.h>
#include "macros.h"
#include "io.h"
#include "font.h"
#include "gfx.h"

unsigned short current_key = 0;
unsigned short previous_key = 0;
TXT_BASE *p_txt;
unsigned char txt_lut[256];

void txt_init(void)
{
  p_txt = (TXT_BASE *)malloc(sizeof(TXT_BASE));
  p_txt->gap = 8;
  p_txt->font = (unsigned int *)font_tiles;
  p_txt->chars = txt_lut;

  for (int i = 0; i < 96; i++)
    p_txt->chars[i + 32] = i;
}

void txt_free(void)
{
  free(p_txt);
  p_txt = NULL;
}

void gba_putc(int x, int y, unsigned char c, int color)
{
  int ix, iy;
  unsigned int row;
  unsigned char *p_ch = (unsigned char *)&p_txt->font[2 * p_txt->chars[c]];

  for (iy = 0; iy < 8; iy++)
  {
    row = p_ch[iy];

    for (ix = 0; row > 0; row >>= 1, ix++)
      if (row & 1)
        draw_pixel(ix + x, iy + y, color);
  }
}

void gba_puts(int x, int y, const char *str, int color)
{
    int c, gap=0;

    while((c = *str++) != 0)
    {
        if(c == '\n')
        {    
            x += SCREEN_WIDTH*p_txt->gap;
            y += p_txt->gap;  
            gap = 0;    
        }
        else
        {
            int ix, iy;
            unsigned int row;
            unsigned char *p_ch= (unsigned char*)&p_txt->font[2 * p_txt->chars[c]];

            for(iy = 0; iy < 8; iy++)
            {
                row= p_ch[iy];

                for(ix = gap; row > 0; row >>= 1, ix++)
                    if(row & 1)
                        draw_pixel(ix + x, iy + y, color);
            }
            gap += p_txt->gap;
        }
    }
}

void poll_key(void)
{
  previous_key = current_key;
  current_key = ~REG_KEYINPUT & KEY_MASK;
}

unsigned short is_key_hit(unsigned short key)
{
  return (current_key & ~(previous_key)) & key;
}