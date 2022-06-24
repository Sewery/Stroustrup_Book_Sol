
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define LEN 256
#define ALLOC(T, n) ((T *)malloc(sizeof(T) * n))




//-----------------------------------------------------------------
struct table
{
   const char* arp[LEN];
    int  k[LEN];
};
//-----------------------------------------------------------------

void init(struct table* lst)
{
    assert(lst);
    for(int i=0; i<LEN; i++)
    {
        lst->k[i]=0;
        lst->arp[i]=0;
    }
}
//-----------------------------------------------------------------
struct table* create ()
{
    struct table*  t = ALLOC(struct table,1);
    init(t);
    return t;
}
//-----------------------------------------------------------------
void destroy(struct table* lst)
{
    assert(lst);
    free(lst->k);
    free(lst->arp);
    free(lst);
}
//-----------------------------------------------------------------
int find(struct table * t, const char* c)
{
    const char ** w= t->arp;
    int count =0;
    while(count!=LEN-1 )
    {
        if(*w!=0 && strcmp(*w,c)==0)
        {
            printf("%s",*w);
            return 1;
        }
            
        w++; 
        count++;
    }
    return 0;
}
//-----------------------------------------------------------------
int insert(struct table * t, const char* c, int i)
{
    double ret = 0.0;
    const char ** w= t->arp;
    int count =0;
    while(w || count==LEN)
    {
        if(*w==0)
        {
            *w=c;
            ret=0.5;
            break;
            
        }
        w++; 
        count++;   
    }
    //
    int * ke= t->k;
    while(ke)
    {
        if(*ke==0)
        {
            *ke=i;
            ret+=0.5;
            break;
        }
        ke++;    
    }
    return ret;
} 
//-----------------------------------------------------------------
int remover(struct table * t, const char* c)
{
    const char ** w= t->arp;
    int count =0;
    while(count!=LEN-1)
    {
        if(*w==c)
        {
            *w=0;
            return 1;
        }
        w++;
        count++;    
    }
    return 0;
}
//-----------------------------------------------------------------
void print(struct table *t)
{
    const char ** w= t->arp;
    int * i= t->k; 
    while(*w || *i)
    {
        printf("%s %d\n", *w, *i);
        w++;i++;
    }
}

//-----------------------------------------------------------------

void main()
{
    struct table* t = create(); 

    const char ** w= t->arp;
    int * i= t->k;
    insert(t,"Eating",12);
    insert(t,"fast ",232);
    insert(t,"is forbidden",32);
    insert(t,"!",2);
    print(t);
  
    printf("Result should be 1 but is:%d\n", find(t,"fast "));
    printf("Result should be 0 but is:%d\n", find(t,"forbidden"));
    printf("Result should be 0 but is:%d\n", find(t,"  !  "));

    printf("Result after removing 'fast'\n");
    remover(t,"forbidden ");
    remover(t,"fast ");
    print(t);
  
}

//-----------------------------------------------------------------