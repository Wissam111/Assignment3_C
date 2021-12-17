
#include <stdio.h>
#include <string.h>
#include "sequence.h"
#include <ctype.h>
#define LINE 256
#define WORD 30
#define TXT 1024

int main()
{

    // char Line[LINE];

    readWord();
    readTxT();
    print_Gematria();
    print_Atbash();
    // print_Anagram();


    return 0;
}
