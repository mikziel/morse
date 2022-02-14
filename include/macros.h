#ifndef MACROS_H
#define MACROS_H

#define MEM_IO ((volatile unsigned short *)(0x04000000))
#define MEM_VRAM ((volatile unsigned short *)(0x06000000))
#define REG_DISPCNT *((volatile unsigned int *)(MEM_IO))
#define REG_KEYINPUT *((volatile unsigned int *)(0x4000130))

#define DCNT_MODE3 0x0003
#define DCNT_BG2 0x0400

#define KEY_A 0x1
#define KEY_B 0x2
#define KEY_SELECT 0x4
#define KEY_R 0x100
#define KEY_L 0x200
#define KEY_MASK 0x03FF

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

#define COLOR_RED 0x001F
#define COLOR_BLACK 0x0000

#define MAX_CODE_LEN 4

#endif