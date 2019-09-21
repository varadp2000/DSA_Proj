#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *got(){
    char *a;
    scanf("%s",&a);
    printf("%s",&a);
    return a;
}

void main(){
    char *getstring;
    getstring=got();
    printf("%s",&getstring);
    getchar();
}
