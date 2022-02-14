#include <string.h>
#include <stdlib.h>
#include "macros.h"
#include "io.h"
#include "morse.h"
#include "gfx.h"

int main(void)
{
	char code[MAX_CODE_LEN + 1] = {'\0'};
	int max_symbols = 0, screen_centre = SCREEN_WIDTH / 2 - 3;
	
	// set video mode 3 (bitmap), background 2
	REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

	txt_init();

	while (1)
	{
		poll_key();

		if (is_key_hit(KEY_A) && max_symbols < 4)
		{
			clear_screen();
			code[max_symbols++] = '.';
			gba_puts(screen_centre, SCREEN_HEIGHT / 4 - 3, code, COLOR_RED);
			screen_centre -= 4;
		}
		else if (is_key_hit(KEY_B) && max_symbols < 4)
		{
			clear_screen();
			code[max_symbols++] = '-';
			gba_puts(screen_centre, SCREEN_HEIGHT / 4 - 3, code, COLOR_RED);
			screen_centre -= 4;
		}
		else if (is_key_hit(KEY_R) && max_symbols != 0)
		{
			gba_putc(SCREEN_WIDTH / 2 - 3, 3 * (SCREEN_HEIGHT / 4) - 3, translate_letter(code), COLOR_RED);
			memset(code, 0, sizeof(code));
			max_symbols = 0;
			screen_centre = SCREEN_WIDTH / 2 - 3;
		}
		else if (is_key_hit(KEY_L))
		{
			clear_screen();
			memset(code, 0, sizeof(code));
			max_symbols = 0;
			screen_centre = SCREEN_WIDTH / 2 - 3;
		}
		else if (is_key_hit(KEY_SELECT))
		{
			clear_screen();
			memset(code, 0, sizeof(code));
			max_symbols = 0;
			screen_centre = SCREEN_WIDTH / 2 - 3;
			gba_puts(screen_centre - 20, 10, "MANUAL", COLOR_RED);
			gba_puts(10, 26, "A - dot\nB - dash\nR - translate\nL - reset", COLOR_RED);
			gba_puts(10, 142, "Press SELECT to return...", COLOR_RED);

			do
			{
				poll_key();
			} while (!is_key_hit(KEY_SELECT));
			
			clear_screen();
		}
	}

	txt_free();
	return 0;
}