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
char readLine(char Line[])
{
    int i = 1;
    char c = getc(stdin);

    while (c != '\n')
    {

         
        Line[i] = c;
        i++;
        c = getc(stdin);
        
          if(c==EOT){
              break;
          } 
     
    }
      
    Line[i] = '\n';
    Line[i + 1] = '\0';

    return c;
}
void readTxT(char * str){
    char line[LINE] = "";
    char c;
    while((c = getc(stdin)) != EOT){
        if(c != '\n'){
            line[0] = c;
           char t =  readLine(line);
            strcat(txt, line);
             if(t==EOT){
               break;
           }
            
        }
    }
        printf("txt --> :\n%s", txt);
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
