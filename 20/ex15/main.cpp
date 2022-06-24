#include <math.h>

#include "../../std_lib_facilities.h"
template<class Elem>
struct Link{
    Link(const Elem& v = Elem(), Link* s = 0)
        : succ(s), val(v) { }
   
    Link*succ;
    Elem val;
};
template<class Elem>
class pvector{
    vector<Elem*> elems;
  
public:
    typedef typename vector<Elem*>::iterator iterator;
    typedef typename vector<Elem*>::const_iterator const_iterator;

    
    class iterator;

    
    pvector() : elems() { }
    explicit pvector(size_type n) : elems(vector<Elem*>(n)) { }
    ~pvector();
   

    iterator begin(){ return  elems.begin(); }
    iterator end(){ return  elems.end()); }

    iterator insert( iterator p, const Elem& v )
    {
        elems.insert(p,*v);
    }
    iterator erase( iterator p ){ elems.erase(p,*v);}
  
    void push_back(const Elem &v){ elems.push_back(*v); }
    void push_front(const Elem& v){ elems.push_front(*v); }
    
    Elem* operator[](int n){return elems[n];}
    int size()const{return elems.size(); }
    
    Elem& front();
    Elem& back();
    

};
template<class Elem>
pvector<Elem>::~pvector()
{
    for( const auto &k : elems)delete *k;
}
template<class Elem>
class pvector<Elem>::iterator{
    Elem* curr;
public:
    iterator(Elem* p): curr{p} {}

    iterator& operator++(){ curr= curr->succ; return *this;}
   
    Elem& operator*() { return curr->val;}

    bool operator==(const iterator&b)const {return curr == b.curr;}
    bool operator!=(const iterator&b)const {return curr != b.curr;}
};
int main(){

  
  
  

}