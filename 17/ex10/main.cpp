#include <math.h>

#include "../../std_lib_facilities.h"
class Link{
    public: 
        string value;
        Link(const string& v, Link*p =nullptr,Link*s =nullptr):
        value{v},prev{p},succ{s}{}

        Link* insert(Link* n);
        Link* add(Link* n);
        Link* erase();
        Link* find(const string& s);

        Link* advance(int n)const;
        Link * next(){return succ;}
        Link* previous(){return prev;}
    private:
        Link* prev;
        Link* succ ; 
};
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

// erase this object, return successor
Link* Link::erase() {
    if (this==0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find s in list; return 0 for "not found"
Link* Link::find(const string& s) {
    Link* p = this;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}

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
void print_all(Link *p){
    cout<<"{ ";
    while(p){
        cout<<p->value;
        if(p=p->next())cout<<", ";
    }
      cout<<" }";
}
int main(){
try {
    Link * norse_gods= new Link("Thor");
    norse_gods = norse_gods->insert(new Link{"Odyn"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freja"});

    Link * greek_gods= new Link("Thor");
    greek_gods = greek_gods->insert(new Link{"Atena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Posejdon"});

    Link* p = greek_gods->find("Mars");
    if(p)p->value="Ares";

    Link* p2= norse_gods->find("Zeus");
    if(p2){
        if(p2==norse_gods) norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }
    
    print_all(norse_gods);
    print_all(greek_gods);
    cout<<'\n';
   
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

}