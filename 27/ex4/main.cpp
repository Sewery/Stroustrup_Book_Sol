

#include <iostream>
#include <vector>
#include <exception>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

struct Link {
    Link():pre(0),suc(0){} 
    Link* pre;
    Link* suc;
    virtual void print(ostream& os)const{}
};
//-----------------------------------------------------------------

class Name : public Link{
private:
    string n;       // the name string 
public:
    Name():Link(),n(string()){}
    Name(string s):Link(),n(s){} 
    string get_name(){ return n;}
    void print(ostream& os) const  override { os<<n; }

};

//----------------------------------------------------------------
ostream& operator<<(ostream& os,const Link& link)
{
    link.print(os);
    return os;
}
//----------------------------------------------------------------
class List {
private:   
    Link* first;
    Link* last;
public:
    List():first(0),last(0){} 
    ~List();

    Link* begin() const{return first;}
    Link* end() const{return last;}//last element not 0

    void push_back( Link* p );
    void push_front( Link* p );
    void insert( Link* p,  Link* q );
    Link* erase(  Link* p );
    Link* advance(Link* lst , int n);

};

//-----------------------------------------------------------------
List::~List()
{
    Link* p=first;
    while(p!=last){
        Link* q = p->suc;
        delete p;
        p = q;
    }    
}
//-----------------------------------------------------------------
void List::push_back( Link* p )
{
        if(last){
            last->suc = p;
            p->pre = last;
        }
        else{
            first=p;
            p->pre=0;
        }
        last=p;
        p->suc=0;
}
//-----------------------------------------------------------------
void List::push_front( Link* p )
{
    
    if(first){
        first->pre=p;
        p->suc=first;
    }
     else{
            first=p;
            p->suc=0;
    }
    first=p;
    p->pre=0;
}
//-----------------------------------------------------------------
void List::insert(Link* p,  Link* q )
{
    if (p==0 || q==0) return;
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
        first=last=q;
    }
    q->suc=p;

}
//-----------------------------------------------------------------
 Link* List::erase( Link* p )
{
    if(p==0)
        return 0;
    
    if(p==first){
        if(p->suc){
            first= p->suc;
            p->suc->pre=0;
            return p->suc;
        }else {
            first =last =0;
            return 0;
        }
    }
    else if (p==last)
    {
        if(p->pre){
            last = p->pre;
            p->pre->suc=0;
        }else {
            first=last =0;
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
 Link* List::advance(Link* lst , int n)
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

void print_list( const List& lst)
{   
    for(Link * cur = lst.begin();cur!=lst.end()->suc;cur=cur->suc )
        cout<<*cur<<" ";
    cout<<"\n";
}
//-----------------------------------------------------------------
int main()
{
    int count = 0;
    List names;              /* make a list */
    Link* curr;
    
    names.push_back( new Name("Anna"));
    names.push_back( new Name("Casper"));
    names.push_back( new Name("Caitlin"));

    /* remove the second name (with index 1): */
    names.erase( names.advance(names.begin(), 1));

    curr = names.begin();             /* write out all names */
    for (; curr != names.end(); curr = curr->suc) {
        count++;
        cout<<"element "<<count<<" is "<< *curr<<'\n';
    }
    names.push_front(new Name("Adam"));
    print_list(names);
    names.insert(names.end(), new Name("Eva"));
    print_list(names);
    Link* l = names.advance(names.begin(),2);
    cout<< *l<<'\n';

}
//-----------------------------------------------------------------