#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
#define TXT 1024
#define EOT '~' // end of text
char txt[TXT];
char *result;
char *atbash;
char *anagram;
char Word[WORD];
int n = 0;
int similar(char *s, char *t);
int char2Number(char c);
void print_Gematria();
char *to_AtbashWord(char *input);
char *reverse();
void print_Anagram();
int countCharacters2(char *words, char *chars);
bool countCharacters(char *str1);
int hasAllCharsInWord(char *str, char *word);

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
        Line[i] = EOT;
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
            strcat(txt, line);
            if (t == EOT)
            {
                break;
            }
        }
    }

    while (txt[n] != EOT)
    {
        n++;
    }
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
    result = (char *)malloc((TXT) * sizeof(char));
    int wordGema = 0;
    int track = 0;
    int i = 0, j, t;
    while (Word[i] != '\0')
    {
        wordGema += char2Number(Word[i]);
        i++;
    }

    for (i = 0; i < n; i++)
    {
        char temp[LINE] = "";
        t = 0;
        track = 0;
        if (!isalpha(txt[i]))
        {
            continue;
        }
        for (j = i; j < n; j++)
        {
            temp[t] = txt[j];

            if (isalpha(txt[j]))
            {
                temp[t] = txt[j];
                track += char2Number(temp[t]);
            }

            if (track == wordGema)
            {
                if (j < n - 2)
                {
                    temp[t + 1] = EOT;
                }
                strcat(result, temp);

                break;
            }
            t++;
        }
    }

    printf("Gematria Sequences: %s \n ", result);
    free(result);
}

void print_Atbash()
{
    int i = 0, j, t;
    atbash = (char *)malloc((TXT) * sizeof(char));
    for (i = 0; i < n; i++)
    {
        char temp[WORD] = "";

        t = 0;
        if (!isalpha(txt[i]))
        {
            continue;
        }
        for (j = i; j < n; j++)
        {

            temp[t] = txt[j];

            if (strcmp(Word, to_AtbashWord(temp)) == 0 || strcmp(reverse(), to_AtbashWord(temp)) == 0)
            {
                if (j < n - 2)
                {
                    temp[t + 1] = EOT;
                }
                strcat(atbash, temp);
                break;
            }

            t++;
        }
    }

    printf("Atbash Sequences: %s \n", atbash);
    free(atbash);
}

char *to_AtbashWord(char *input)
{
    char *res;
    char *new;
    res = (char *)malloc((strlen(input) + 1) * sizeof(char));
    new = (char *)malloc((strlen(input) + 1) * sizeof(char));
    int i;
    for (i = 0; i <= strlen(input) - 1; i++)
    {
        unsigned char c = input[i];
        if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
        {
            new[i] = c;
            continue;
        }
        int flag = 0;
        if (c <= 90)
        {
            c = c + 32;
            flag = 1;
        }
        int off = c - 'a';
        new[i] = 'z' - off;
        if (flag)
            new[i] = new[i] - 32;
    }
    int k = 0, j = 0;
    while (new[k] != '\0')
    {
        if (isalpha(new[k]))
        {
            res[j] = new[k];
            j++;
            k++;
        }
        else
        {
            k++;
        }
    }
    free(new);
    return res;
}
char *reverse()
{
    int i, j;
    char *rev;
    rev = (char *)malloc((WORD) * sizeof(char));
    int wordSize = strlen(Word);
    j = wordSize - 1;
    for (i = 0; i < wordSize; i++)
    {
        rev[i] = Word[j];
        j--;
    }

    return rev;
}

int countCharacters2(char *words, char *chars)
{

     if(strlen(chars) > strlen(words)){
         return false;
     }

    int j, temp;
    int c[27] = {0};

    for (j = 0; j < strlen(chars); j++)
    {
        if (chars[j] != ' ')
        {
            temp = char2Number(chars[j]);
            c[temp]++;
        }
    }

    int w[27] = {0};
    for (j = 0; j < strlen(words); j++)
    {
        temp = char2Number(words[j]);
        if (words[j] != ' ')
        {
            w[temp]++;
        }
        // Here, we check the result in-time to go faster.
        if (w[temp] > 0 &&
            c[temp] < w[temp])
        {

            return false;
        }
    }

    return true;
}

void print_Anagram()
{
   int i = 0, j, t;
    anagram = (char *)malloc((TXT) * sizeof(char));
    for (i = 0; i < n; i++)
    {
        char temp[WORD] = "";

        t = 0;
        if (!isalpha(txt[i]))
        {
            continue;
        }
        for (j = i; j < n; j++)
        {

            temp[t] = txt[j];

            if (countCharacters2(temp , Word))
            {
                if (j < n - 2)
                {
                    temp[t + 1] = EOT;
                }
                strcat(anagram, temp);
                break;
            }

            t++;
        }
    }

    
    printf("angram Sequences: %s \n ", anagram);
    free(anagram);
}
