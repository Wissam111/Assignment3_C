#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define TXT 1024

char txt[TXT];



void getLine(char Line[]){
int i =1;

char c;
// getc(stdin) -> read  next chararcter from a file
while(c = getc(stdin) != '\n'){
    Line[i] = c;
    i++;
}

Line[i] = '\n';
Line[i+1] = '\0';

}

void getWord(char Word[]){
int i =0;
char c = getc(stdin);

if(c== EOF){
    return;
}

while(c!= ' ' && c !='t' && c !='\n'&& c!=EOF){
Word[i] = c;
i++;
c = getc(stdin);
}

Word[i] = '\0';

}