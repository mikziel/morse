#ifndef IO_H
#define IO_H

// text-system's properties 
typedef struct
{
  unsigned int *font;
  unsigned char *chars;
  unsigned char gap;
} TXT_BASE;

extern TXT_BASE *p_txt;
extern unsigned char txt_lut[256];
extern unsigned short current_key;
extern unsigned short previous_key;

// initialize the text system
void txt_init(void);

// free memory allocated for the text system
void txt_free(void);

void gba_putc(int x, int y, unsigned char c, int color);

void gba_puts(int x, int y, const char *str, int color);

// current state of keys
void poll_key(void);

unsigned short is_key_hit(unsigned short key);

#endif