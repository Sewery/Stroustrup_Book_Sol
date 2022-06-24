#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define ALLOC(T,n) ((T*)malloc(sizeof(T)*n))
#define M_NAME(s) (Link*)make_name(s)
#define GET_NAME(l) ((Name*)l)->p

typedef struct Link {
    struct Link* pre;
    struct Link* suc;
} Link;
//-----------------------------------------------------------------
typedef struct List {
    struct Link* first;
    struct Link* last;
} List;
//-----------------------------------------------------------------

void init(List* lst)
{
    assert(lst);
    lst->first = lst->last=0;
}
//-----------------------------------------------------------------
struct List* create ()
{
    List* lst = ALLOC(List,1);
    init(lst);
    return lst;
}
//-----------------------------------------------------------------
void clear( List* lst )
{
    assert(lst);
    {
        Link* curr=lst->first;
        while(curr)
        {
            Link* next= curr->suc;
            free(curr);
            curr=next;
        }
        lst->first=lst->last =0;
    }
}
//-----------------------------------------------------------------
void destroy(List* lst)
{
    assert(lst);
    clear(lst);
    free(lst);
}
//-----------------------------------------------------------------
void push_back(List* lst , Link* p )
{
    assert(lst);
    {
         Link* last = lst->last;
        if(last){
            last->suc = p;
            p->pre = last;
        }
        else{
            lst->first=p;
            p->pre=0;
        }
        lst->last=p;
        p->suc=0;
    }
}
//-----------------------------------------------------------------
void push_front(List* lst ,  Link* p )
{
    assert(lst);
     Link* first = lst->first;
    if(first){
        first->pre=p;
        p->suc=first;
    }
     else{
            first=p;
            p->suc=0;
    }
    lst->first=p;
    p->pre=0;
}
//-----------------------------------------------------------------
void insert( List* lst ,Link* p,  Link* q )
{
    assert(lst);
    if(p)
    {
        if(p->pre==0){
            q->pre=0;
        }else{
            p->pre->suc=q;
            q->pre=p->pre;
        }
        p->pre=q;
      
    }else{
        lst->first=lst->last=q;
    }
    q->suc=p;

}
//-----------------------------------------------------------------
struct Link* erase(List* lst ,  Link* p )
{
    assert(lst);
    if(p==0)
        return 0;
    
    if(p==lst->first){
        if(p->suc){
            lst->first= p->suc;
            p->suc->pre=0;
            return p->suc;
        }else {
            lst->first =lst->last =0;
            return 0;
        }
    }
    else if (p==lst->last)
    {
        if(p->pre){
            lst->last = p->pre;
            p->pre->suc=0;
        }else {
            lst->first=lst->last =0;
            return 0;
        }
    }
    else {
        p->suc->pre = p->pre;
        p->pre->suc = p->suc;
        return p->suc;
    }

}
//-----------------------------------------------------------------
Link* advance(Link* lst , int n)
{
    Link* l=lst;
    if(n>0){
        
        for(int i=0; i<n;i++)
            l=l->suc;
        return l;    

    }else{
        for(int i=0; i>n;i--)
            l=l->pre;
    }
    return l;
    
}
//-----------------------------------------------------------------
typedef struct Name {
    Link lnk;            /* the Link required by List operations */
    char* p;                    /* the name string */
} Name;

Name* make_name(char* n)
{
    Name* p =  ALLOC(Name,1);
    p->p = n;
    return p;
}
//-----------------------------------------------------------------
void print_list(struct List* lst)
{   
    Link* t = lst->first;
    for(Link * cur = t;cur!=0;cur=cur->suc )
        printf("%s, ",GET_NAME(cur));
    printf("\n");
}
//-----------------------------------------------------------------
int main()
{
    int count = 0;
    List names;              /* make a list */
    Link* curr;
    init(&names);

    /* make a few Names and add them to the list: */
    push_back(&names, M_NAME("Nora"));
    push_back(&names, M_NAME("Jacob"));
    push_back(&names, M_NAME("Caitlin"));

    /* remove the second name (with index 1): */
    erase(&names, advance(names.first, 1));

    curr = names.first;             /* write out all names */
    for (; curr != 0; curr = curr->suc) {
        count++;
        printf("element %d: %s\n", count, GET_NAME(curr));
    }
    push_front(&names, M_NAME("Adam"));
    print_list(&names);
    insert(&names,names.last, M_NAME("Eva"));
    print_list(&names);
    Link* l = advance(names.first,2);
    printf("%s",GET_NAME(l));

}
//-----------------------------------------------------------------