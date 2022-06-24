#include <math.h>

#include "../../std_lib_facilities.h"

template<class T >class allocatr{

public:
  T* allocate(int n);
  void deallocate(T* p, int n){free(p);}

  void construct(T* p, const T& v){new(p) T(v);}
  void destroy(T* p){p->~T();}
  

};
template<class T >
 T* allocatr<T>::allocate(int n)
{
  if(n==0) error("Bad info\n");
  T* k =static_cast<T*>(malloc(n*sizeof(T)));
  return k;
}

template<class T, class A = allocatr<T> > class vectr {
    A alloc;    // used to handle memory for elements
    int sz;     // the size
    T* elem;    // a pointer to the elements
    int space;  // space + free space
public:
    vectr() : sz(0), elem(0), space(0) { }
    explicit vectr(int s);

    vectr(const vectr&);                        // copy constructor
    vectr& operator=(const vectr&);             // copy assignment

    ~vectr();                                   // destructor

    T& operator[](int n) { return elem[n]; }    // access; return reference
    const T& operator[](int n) const { return elem[n]; }

    T& at(int n);
    const T& at(int n) const;                   // checked access

    int size() const { return sz; }             // the current size
    int capacity() const { return space; }

    void resize(int newsize, T val = T());      // growth
    void push_back(const T& d);
    void reserve(int newalloc);

};
//------------------------------------------------------------------------------
template<class T, class A> vectr<T,A>::vectr(int s)
    : sz(s), elem(alloc.allocate(s)), space(s)
{
    for (int i = 0; i<sz; ++i)
        alloc.construct(&elem[i],T());
}

//------------------------------------------------------------------------------
template<class T, class A> void vectr<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    for (int i = sz; i<newsize; ++i)    // construct
        alloc.construct(&elem[i],val);
    for (int i = newsize; i<sz; ++i)    // destroy
        alloc.destroy(&elem[i]);
    sz = newsize;
}
//------------------------------------------------------------------------------

template<class T, class A> void vectr<T,A>::push_back(const T& val)
{
    if (space==0) reserve(8);               // start with space for 8 elements
    else if (sz==space) reserve(2*space);   // get more space
    alloc.construct(&elem[sz],val);         // add val at end
    ++sz;                                   // increase the size
}
//------------------------------------------------------------------------------
template<class T, class A> T& vectr<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw Range_error(n);
    return elem[n];
}
//------------------------------------------------------------------------------

template<class T, class A> void vectr<T,A>::reserve(int newalloc)
{
    if (newalloc<=space) return;        // never decrease allocation
    T* p = alloc.allocate(newalloc);    // allocate new space
    for (int i = 0; i<sz; ++i)          // copy
        alloc.construct(&p[i],elem[i]);
    for (int i = 0; i<sz; ++i)          // destroy
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);             // deallocate old space
    elem = p;
    space = newalloc;
}

template<class T, class A >
vectr<T, A>& vectr<T, A>::operator=(const vectr<T, A>& ok){
  if(this==&ok)return *this;
  if(a.size()<=space){
    for(int i=0; i<a.size();++i)alloc.construct(&this[i],a[i]); //or &elem[i], a.elem[i]
    sz=a.size();
    return *this;
  } 
  T* r =alloc.allocate(ok.size());
  for(int i=0; i<ok.size();++i)alloc.construct(&r[i],ok.elem[i]);
  for(int i=0; i<space;++i) alloc.destroy(elem[i]);
   alloc.deallocate(elem);
  space = sz = a.size();
  elem =p;
  return *this;


}
 
int main(){

  int a = 10;
  int b = 32;
  int c = 32;

  int d = 43;
  int e = 65;
  int f = 435;
  vector<int> xd1;
  xd1.push_back(a);
  xd1.push_back(b);
  xd1.push_back(c);

  vector<int> xd2;
  xd2.push_back(d);
  xd2.push_back(e);
  xd2.push_back(f);

  vector<int> xk;
  allocatr<vector<int>> p;
  cout<<sizeof(xd2)<<" ";
  vector<int>* o =p.allocate(10000);
  cout<<sizeof(*o);
  
  //Doesn't work

}