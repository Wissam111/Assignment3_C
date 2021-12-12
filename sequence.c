#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LINE 256
#define WORD 30
#define TXT 1024
#define EOT '~' // end of text
char txt[TXT];
char Word[WORD];
//getting Line in the txt
void getLine(char Line[])
{
    int i = 1;

    char c = getc(stdin);

    while (c != '\n' && c != EOT)
    {
       
        Line[i] = c;
        i++;
        c =  getc(stdin);;
    }

    Line[i] = '\n';
    Line[i + 1] = '\0';
}

//getting the full Word with getc function
void getWord()
{
    int i = 0;
    char c = getc(stdin);

    if (c == EOT)
    {
        return;
    }

    while (c != ' ' && c != 't' && c != '\n' && c != EOT)
    {
        Word[i] = c;
        i++;
        c = getc(stdin);
    }

    Word[i] = '\0';
  
}
