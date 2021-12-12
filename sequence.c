#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LINE 256
#define WORD 30
#define TXT 1024
#define EOT '~' // end of text
char txt[TXT];
char result[TXT];
char Word[WORD];
int k = 0;
//getting Line in the txt
int char2Number(char c);
void print_Gematria();
char readLine(char Line[])
{
    int i = 1;
    char c = getc(stdin);

    while (c != '\n')
    {

        Line[i] = c;
        i++;
        c = getc(stdin);

        if (c == EOT)
        {
            break;
        }
    }

    if (c == EOT)
    {
        Line[i] = '~';
        Line[i + 1] = '\n';
        Line[i + 2] = '\0';
    }
    else
    {
        Line[i] = '\n';
        Line[i + 1] = '\0';
    }
    return c;
}
void readTxT(char *str)
{

    char line[LINE] = "";
    char c;
    while ((c = getc(stdin)) != EOT)
    {
        if (c != '\n')
        {
            line[0] = c;
            char t = readLine(line);
            k++;
            strcat(txt, line);
            if (t == EOT)
            {
                break;
            }
        }
    }

    

    printf("txt --> :\n %s", txt);
}

void readWord()
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

int char2Number(char c)
{

    int num;

    if (c >= 'A' && c <= 'Z')
    {

        num = c - 'A' + 1;
    }
    else if (c >= 'a' && c <= 'z')
    {

        num = c - 'a' + 1;
    }
    return num;
}

void print_Gematria()
{
    
    int wordGema = 0;
    int track = 0;
    int i = 0;
    while (Word[i] != '\0')
    {
        wordGema += char2Number(Word[i]);
        i++;
    }

    int j = 0, k;
    while (txt[j] != EOT)
    {

        int t = 1;
        k = j + 1;
        char temp[LINE] = "";
        temp[0] = txt[j];
           if(isalpha(temp[0]))
           {
            track = char2Number(temp[0]);
           }
            while (txt[k] != EOT)
            {
        
                if (track == wordGema)
                {
                    temp[t] = EOT;
                    printf("%s", temp);
                    strcat(result, temp);
                    break;
                }
                if (isalpha(txt[k]))
                {
                    track += char2Number(txt[k]);
                }
                temp[t] = txt[k];
                t++;
                k++;
             }
       
        j++;
    }

    printf("Gematria Sequences: %s ", result);
}