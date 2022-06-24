#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define ALLOC(T,n) ((T*)malloc(sizeof(T)*n))


void foo(char* p, int x )
{
    printf("p is %s and x is %d \n",p,x);
}
void main(void)
{

    printf("Hello world !");

    char* s= "Hello";
    char* s2 = "world";
    int sz= strlen(s)+ strlen(s2)+2;
    char* s3= ALLOC(char,sz);
    strcpy(s3,s);
    s3[strlen(s)]=' ';
    strcpy(s3+strlen(s)+1,s2);
    s3[sz-1]=0;
    printf("%s",s3);
    
    //
    foo(s,100);
    foo("xd ez",100.443);
    foo("another one", 0.121);
}
