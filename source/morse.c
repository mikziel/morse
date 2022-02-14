#include <string.h>
#include "morse.h"

const struct morse_code morse_alphabet[26] =
{
    {".-",      'A'},
    {"-...",    'B'},
    {"-.-",     'C'},
    {"-..",     'D'},
    {".",       'E'},
    {"..-.",    'F'},
    {"--.",     'G'},
    {"....",    'H'},
    {"..",      'I'},
    {".---",    'J'},
    {"-.-",     'K'},
    {".-..",    'L'},
    {"--",      'M'},
    {"-.",      'N'},
    {"---",     'O'},
    {".--.",    'P'},
    {"--.-",    'Q'},
    {".-.",     'R'},
    {"...",     'S'},
    {"-",       'T'},
    {"..-",     'U'},
    {"...-",    'V'},
    {".--",     'W'},
    {"-..-",    'X'},
    {"-.--",    'Y'},
    {"--..",    'Z'}
};

char translate_letter(char *code)
{
    for (int i = 0; i < 26; i++)
        if (!strcmp(code, morse_alphabet[i].code))
            return morse_alphabet[i].letter;

    return '!';
}