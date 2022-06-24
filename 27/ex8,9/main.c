#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define LEN 128
#define ALLOC(T, n) ((T *)malloc(sizeof(T) * n))
char* getword()
{
    char *fir=ALLOC(char, LEN);
    char *w = fir;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n'){
            w =0;
            break;
        }   
        *w = c;
        w++;
    }
    return fir;
}
void print(char *s)
{
    int i = 0;
    while (s[i])
    {
        printf("%d-'%c'\n", (int)s[i], s[i]);
        i++;
    }
}
int ascending(void const *a, void const *b)
{
    return (*(char *)a - *(char *)b);
}
int main()
{
    char *c = "`1234567890-=~!@#$%^&*()_+[];',./\{}|:<>?";
    char *b = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    int sz = strlen(c) + strlen(b) + 1;

    
    char p[LEN];
    strcpy(p, c);
    strcat(p, b);
    qsort(p, sz-1, sizeof(char), ascending);
    //print(p);
    char * guess;
    char* final ="";
    printf("%d",strlen(final));
    while( strcmp(guess= getword(),"quit")){

        char* c = final;
        final = ALLOC(char,strlen(guess)+strlen(final));
        strcpy(final,c);
        strcat(final,guess);
        printf("final: %s \n",final);

       
    }
    qsort(final, strlen(final), sizeof(char), ascending);
    print(final);

}