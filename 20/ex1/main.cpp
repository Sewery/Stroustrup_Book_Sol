#include "../../std_lib_facilities.h"

void copy1(int* f1, int* e1 , int* f2){
    if(e1==f1)return;
    int *rr= f2;
    for(int* p = f1; p!=e1;p++)
    {
        *rr=*p;
        rr++;
    }
   
}
//*****************************************
//VECTOR WITH ALLOCATOR CLASSES
//*****************************************
template<class T> class allocatr {
public:
    // allocate space for n objects of type T
    T* allocate(int n);

    // deallocate n objects of type T starting at p
    void deallocate(T* p) { free(p); }

    // construct a T with the value v in p
    void construct(T* p, const T& v) { new(p) T(v); }

    // destroy the T in p
    void destroy(T* p) { p->~T(); }
};

//------------------------------------------------------------------------------

// allocate space for n objects of type T
template<class T> T* allocatr<T>::allocate(int n)
{
    T* p = static_cast<T*>(malloc(n*sizeof(T)));
    if (p==0) error("allocate: could not allocate memory");
    return p;
}

//------------------------------------------------------------------------------

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
    void push_front(const T& d);
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

template<class T, class A> vectr<T,A>::vectr(const vectr& a)
    : sz(a.sz), elem(alloc.allocate(a.sz)), space(a.sz)
{
    for (int i = 0; i<sz; ++i)
        alloc.construct(&elem[i],a.elem[i]);
}

//------------------------------------------------------------------------------

template<class T, class A>
vectr<T,A>& vectr<T,A>::operator=(const vectr<T,A>& a)
{
    if (this==&a) return *this; // self-assignment, no work needed

    if (a.sz<=space) {          // enough space, no need for new allocation
        for (int i = 0; i<a.sz; ++i)
            alloc.construct(&elem[i],a.elem[i]);
        sz = a.sz;
        return *this;
    }

    T* p = alloc.allocate(a.sz);            // allocate new space
    for (int i = 0; i<a.sz; ++i)            // copy elements
        alloc.construct(&p[i],a.elem[i]);
    for (int i = 0; i<sz; ++i)              // destroy old objects
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);                 // deallocate old space
    space = sz = a.sz;                      // set new size
    elem = p;                               // set new elements
    return *this;
}

//------------------------------------------------------------------------------

template<class T, class A> vectr<T,A>::~vectr()
{
    for (int i = 0; i<sz; ++i)
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);
}

//------------------------------------------------------------------------------

template<class T, class A> T& vectr<T,A>::at(int n)
{
    if (n<0 || sz<=n) throw Range_error(n);
    return elem[n];
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

//------------------------------------------------------------------------------
 //**********************************************
 template<class T, class A> void vectr<T,A>::push_front(const T& val)
{
    T* p;
    int s=space;
    if (space==0) {p= alloc.allocate(8);s=8;}               
    else if (sz==space){p= alloc.allocate(2*space);s=space*2;}
    else{p= alloc.allocate(space);}
    alloc.construct(&p[0],val); 
    for (int i = 0; i<sz; ++i)         
        alloc.construct(&p[i+1],elem[i]);
    for (int i = 0; i<sz; ++i)         
        alloc.destroy(&elem[i]);
    alloc.deallocate(elem);     
    elem = p;    
    sz= sz+1;
    space = s;
                                   
}

void f(string s){
    cout<<"Size of it "<<s.size()<<'\n';
    if("Witam"<=s)cout<<"s jest wieksze badz rowne witam\n";
    if("Czesc"<s)cout<<"s jest wieksze badz rowne czesc\n";
    string k =s;
    for(auto p: k)cout<<p;
}
template<class Iter>
void fr(Iter c1, Iter c2){

    
    
    Iter c= c1;
    string s = "Witam";
    int o=0;
    while(true){
        
        if(s[o]!=*c){cout<<"c nie jest rowne  rowne witam\n";break;}
        if(c==c2){cout<<"c jest rowne  rowne witam\n";break;}
        o++;
        c++;
    }
    cout<<"Size of it "<<o<<'\n';
    c = c1;
    string ss = "Czesc";
    o=0;
    while(true){
        
        if(ss[o]!=*c){cout<<"c nie jest rowne  rowne Czesc\n";break;}
        if(c==c2){cout<<"c jest rowne  rowne Czesc\n";break;}
        o++;
        c++;
    }
     cout<<"Size of it "<<o<<'\n';
    string kpr =s;
    for(auto p: kpr)cout<<p;
}
int main()
{

    try
    {
        int o[] = {3,4,5,6,2,3};
        int o1[] = {33,45,43,6,2,43};
        copy1(begin(o),end(o),begin(o1));
        for(auto p: o1)cout<<p<<" ";
        cout<<'\n';

        vectr<int> p;
        p.push_back(34);
        p.push_back(54);
        p.push_back(34);
        p.push_back(14);
        p.push_front(1);
        for(int i=0; i<p.size();i++)cout<<p[i]<<" ";

        //
        vector<char> r{'W','i','t','a','m'};
        fr(r.begin(),r.end());
        cout<<'\n';
        list<char> e{'W','i','t','a','m'};
        fr(e.begin(),e.end());
        cout<<'\n';
        string ss= "Witam";
        f(ss);
        cout<<'\n';
        
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "exception\n";
    }
}
