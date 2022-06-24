#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//-----------------------------------------------------------------
size_t strlength(const char* a)
{
   size_t i=0;
    while(*a++!=0)
        i++;
    return i;
}
//-----------------------------------------------------------------
char* strcopy(char* s1,const char* s2 )
{
    char* p = s1;
    while (*s1++ = *s2++);
    return p;
}

//-----------------------------------------------------------------
int strcompare(const char* s1,const char* s2 )
{
    while(*s1!=0)
    {
        if(*s1!=*s2)
            return *s1>*s2?1:-1;
        s1++;s2++;      
          
    }
    return *s2!=0?-1:0;
}
//-----------------------------------------------------------------
void main()
{
    char * s= "xdaledweweew   ";
    printf("strlength test:\n");
    printf("My: %d , Lib: %d\n",strlength(s), strlen(s));


    char* a1= "dog";
    char* a2= "dog";
    char* a3= "dogie";
    char* a4= "do";
    printf("Strcompare test:\n");
    printf("My: %d , Lib: %d\n",strcompare(a1,a2), strcmp(a1,a2));
    printf("My: %d , Lib: %d\n",strcompare(a1,a3), strcmp(a1,a3));
    printf("My: %d , Lib: %d\n",strcompare(a1,a4), strcmp(a1,a4));

    //ATTENTION copied data cannot be bigger than  a place where the need to be placed
    char* b1= "dog";
    char* b2= "dow";
    char* b3= "do";
    char* b4= "";
    char c1[] = "ABCewe";
    char c2[] = "abcewew";
    char c3[] = "ABewew";
    char c4[] = "x";
    printf("strcopy test:\n");
    printf("My result: %s, should be: %s \n",strcopy(c1,b1),b1);
    printf("My result: %s, should be: %s \n",strcopy(c2,b2),b2);
    printf("My result: %s, should be: %s \n",strcopy(c3,b3),b3);  
    printf("My result: %s, should be: %s \n",strcopy(c4,b4),b4);  
 





}