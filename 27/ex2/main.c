#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct Link {
    struct Link* pre;
    struct Link* suc;
};
//-----------------------------------------------------------------
struct List {
    struct Link* first;
    struct Link* last;
};
//-----------------------------------------------------------------

void init(struct List* lst)
{
    assert(lst);
    lst->first = lst->last=0;
}
//-----------------------------------------------------------------
struct List* create ()
{
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    init(lst);
    return lst;
}
//-----------------------------------------------------------------
void clear(struct List* lst )
{
    assert(lst);
    {
        struct Link* curr=lst->first;
        while(curr)
        {
            struct Link* next= curr->suc;
            free(curr);
            curr=next;
        }
        lst->first=lst->last =0;
    }
}
//-----------------------------------------------------------------
void destroy(struct List* lst)
{
    assert(lst);
    clear(lst);
    free(lst);
}
//-----------------------------------------------------------------
void push_back(struct List* lst , struct Link* p )
{
    assert(lst);
    {
        struct Link* last = lst->last;
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
void push_front(struct List* lst , struct Link* p )
{
    assert(lst);
    struct Link* first = lst->first;
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
void insert(struct List* lst , struct Link* p, struct Link* q )
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
struct Link* erase(struct List* lst , struct Link* p )
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
struct Link* advance(struct Link* lst , int n)
{
    struct Link* l=lst;
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
struct Name {
    struct Link lnk;            /* the Link required by List operations */
    char* p;                    /* the name string */
};

struct Name* make_name(char* n)
{
    struct Name* p = (struct Name*) malloc(sizeof(struct Name));
    p->p = n;
    return p;
}
//-----------------------------------------------------------------
void print_list(struct List* lst)
{   
    struct Link* t = lst->first;
    for(struct Link * cur = t;cur!=0;cur=cur->suc )
        printf("%s, ",((struct Name *)cur)->p);
    printf("\n");
}
//-----------------------------------------------------------------
int main()
{
    int count = 0;
    struct List names;              /* make a list */
    struct Link* curr;
    init(&names);

    /* make a few Names and add them to the list: */
    push_back(&names, (struct Link*)make_name("Nora"));
    push_back(&names, (struct Link*)make_name("Jacob"));
    push_back(&names, (struct Link*)make_name("Caitlin"));

    /* remove the second name (with index 1): */
    erase(&names, advance(names.first, 1));

    curr = names.first;             /* write out all names */
    for (; curr != 0; curr = curr->suc) {
        count++;
        printf("element %d: %s\n", count, ((struct Name*) curr)->p);
    }
    push_front(&names, (struct Link*)make_name("Adam"));
    print_list(&names);
    insert(&names,names.last, (struct Link*)make_name("Eva"));
    print_list(&names);
    struct Link* l = advance(names.first,2);
    printf("%s",((struct Name*)l)->p);

}
//-----------------------------------------------------------------