
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define LEN 256
#define ALLOC(T, n) ((T *)malloc(sizeof(T) * n))

//-----------------------------------------------------------------
char* getword()
{
    char *fir=ALLOC(char, LEN);
    char *w = fir;
    int c;
    while ((c = getchar()) != EOF && c!=' ' && c!='\n')
    {
        *w = c;
        w++;
    }
    *w=0;

    return fir;
}
//-----------------------------------------------------------------
void main()
{
    
    while(1)
    {
        char* word=getword();
        if (!strcmp(word,"quit")) break;
        printf("%s\n",word);

    }
}

//-----------------------------------------------------------------