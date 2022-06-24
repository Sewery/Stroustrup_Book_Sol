#include <math.h>

#include "../../std_lib_facilities.h"
template<class T > struct p_vec{
    T* elem;
    int sz;
    int space;
    p_vec() : sz(0), elem(0), space(0) { }
    p_vec(int s): sz(s),elem(new T[s]), space(s){
        for(int i=0 ; i<sz; i++)elem[i]= T();
    }
};

template<class T > class vectr {
    p_vec<T>* p;
public:
    vectr() : p(new p_vec<T>()) { }
    explicit vectr(int s): p( new p_vec<T>(s)){}

    vectr(const vectr& r):p(new p_vec<T>(r.p->sz)){
        for(int i=0; i<r->p.sz;i++) p->elem[i]= r.p->elem[i];
    }                        
    vectr& operator=(const vectr& r){
        if(&r==this) return *this;
        delete p;
        p= new p_vec<T>(r.p->sz);
        for(int i=0; i<r.p->sz;i++) p->elem[i]= r.p->elem[i];        
    }
                

    ~vectr(){delete p;}                                  // destructor

    T& operator[](int n) { return p->elem[n]; }    // access; return reference
    const T& operator[](int n) const { return p->elem[n]; }

    int size() const { return p->sz; }             // the current size
    int capacity() const { return p->space; }

    void resize(int newsize)
    {
        reserve(newsize);
        p->sz = newsize;
    }   
    void push_back(const T& d){
        if(p->sz==0) resize(8);
        else if(p->sz==p->space)
        {
            resize(p->sz*2);
            
        }
        p->elem[p->sz-1]= d;

    }
    void reserve(int newalloc)
    {
        if(newalloc<=p->space)return;
        p_vec<T>*k = new p_vec<T>(newalloc);
        for(int i=0; i<p->sz;i++)  k->elem[i]=p->elem[i];
        delete p;
        p=k;

    }

};

int main(){

    vectr<int>  p;
    p.push_back(20);
    cout<<sizeof(p)<<" ";
    int *k =new int[1];

    cout<<sizeof(k)<<": ";
    k =new int[1023221];
     cout<<sizeof(k);

}