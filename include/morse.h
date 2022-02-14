#ifndef MORSE_H
#define MORSE_H

struct morse_code
{
    char *code;
    char letter;
};

extern const struct morse_code morse_alphabet[26];

// Morse decoder
char translate_letter(char *code);

#endif