#include <math.h>

#include "../../std_lib_facilities.h"
struct God{
    God(const string s1,const string s2,const string s3 ,const string s4):
    name{s1}, mythology{s2},vehicle{s3}, weapon{s4}{}
   
 
        string name;
        string mythology;
        string vehicle;
        string weapon; 
};
//----------------------------------------------------------
 bool operator==(const God& a, const God& k){return a.name == k.name && a.mythology == k.mythology
    && a.vehicle == k.vehicle && a.weapon == k.weapon; }
//----------------------------------------------------------
class Link{
    public: 
        God value;
        Link(const God& v, Link*p =nullptr,Link*s =nullptr):
        value{v},prev{p},succ{s}{}

        Link* insert(Link* n);
        Link* add(Link* n);
        Link* erase();
        Link* find(const  God& s);
        Link* add_ordered(Link* n);   
        Link* advance(int n)const;
        Link * next(){return succ;}
        Link* previous(){return prev;}
    private:
        Link* prev;
        Link* succ ; 
};
//----------------------------------------------------------
Link* Link::insert(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;

    n->succ =this;
    if(prev) prev->succ=n;
    n->prev=prev;
    prev= n;
    return n;
}
//----------------------------------------------------------
// insert n after this object
Link* Link::add(Link* n) {
    if (n==0) return this;
    if (this==0) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}
//----------------------------------------------------------
Link* Link::add_ordered(Link* n){
    if (n==0) return this;
    if (this==0) return n;
    if(n->value.name< this->value.name){
        Link* k = insert(n);
        return k;
    }
    Link* p = this;
    while (n->value.name >= p->value.name) {
        if (p->succ==0) {  
            p->add(n);    
            return this;    
        }
        p = p->succ;
    }
    p->insert(n);
    return this;
}   
//----------------------------------------------------------
// erase this object, return successor
Link* Link::erase() {
    if (this==0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}
//----------------------------------------------------------
// find s in list; return 0 for "not found"
Link* Link::find(const  God& s) {
    Link* p = this;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}
//----------------------------------------------------------
// move n positions in list, return 0 for "not found"
// positive n moves forward, negative backward
Link* Link::advance(int n) const {
    if (this==0) return 0;
    Link* p = const_cast<Link*>(this);  // UGLY
    if (0 < n) {
        while (n--) {
            if (p->succ==0) return 0;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev==0) return 0;
            p = p->prev;
        }
    }
    return p;
}
//----------------------------------------------------------
//ptinting all gods in list
void print_all(Link *p){
    cout<<"{ ";
    while(p){
        cout<<p->value.name<<", "<<p->value.mythology<<", "<<p->value.vehicle<<", "<<p->value.weapon;
        if(p=p->next())cout<<" \n";
    }
      cout<<" }";
}
//----------------------------------------------------------
int main(){
try {
    God zeus {"zeus", "grecka", "piorunów ","nieba"};
    God hades {"hades", "grecka", "piorunów ","nieba"};
    God posejdon {"posejdon", "grecka", "piorunów ","nieba"};
    God hera {"hera", "grecka", "piorunów ","nieba"};
    God hestia {"hestia", "grecka", "piorunów ","nieba"};
    Link * g = new Link(zeus);
    g = g->insert(new Link(hades));
    g = g->insert(new Link(posejdon));
    g = g->insert(new Link(hera));
    g = g->insert(new Link(hestia));  


    God amon {"amon", "egipska", "piorunów ","nieba"};
    God re {"re", "egipska", "piorunów ","nieba"};
    God ozyrys {"ozyrys", "egipska", "piorunów ","nieba"};
    God izyda {"Izyda", "egipska", "piorunów ","nieba"};
    God anubis {"anubis", "egipska", "piorunów ","nieba"};
    Link * e = new Link(amon);
    e = e->insert(new Link(re));
    e = e->insert(new Link(ozyrys));
    e = e->insert(new Link(izyda));
    e = e->insert(new Link(anubis));  

    God apollo {"apollo", "rzymska", "piorunów ","nieba"};
    God ceres {"ceres", "rzymska", "piorunów ","nieba"};
    God mars {"mars", "rzymska", "piorunów ","nieba"};
    God merkury {"merkury", "rzymska", "piorunów ","nieba"};
    God jowisz {"jowisz", "rzymska", "piorunów ","nieba"};
    Link * r = new Link(apollo);
    r = r->insert(new Link(ceres));
    r = r->insert(new Link(mars));
    r = r->insert(new Link(merkury));
    r = r->insert(new Link(jowisz));  
    
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

}