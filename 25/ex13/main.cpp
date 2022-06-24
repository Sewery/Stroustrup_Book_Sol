
#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------
template<class T, int N>
class Pool{
    public: 
        Pool();
        T* get();
        void free(T* t);
        int available() const{ return f;};
    private:
    
        T tr[N] ;
        bool is_used[N];
        int sz;
        int f;      
};
//------------------------------------------------------------------------------
template<class T, int N> 
Pool<T, N>::Pool():sz(N),f(N),tr{T()},is_used(){}

template<class T, int N>
T* Pool<T, N>::get()
{
    T* t ;
    if(f==0)
    {
        cerr<<"Your pool is full\n";
        return nullptr;
    }
    for(int i=0;i<sz;i++)
    {
         if (!is_used[i])
         { 
            t = &tr[i];
            f--;
            is_used[i]=true;
            return t;
         }
    }
   
}
//------------------------------------------------------------------------------
template<class T, int N>
void Pool<T, N>::free(T* t)
{
    if(*t==T() ||t==nullptr)
        cerr<<"It doesn't point anything\n";
    for(int i=0; i<sz;i++)
    {
        if(t==&tr[i])
        {
            *t = T();
           
            f++;
            return;
        }   
    }   
}
//------------------------------------------------------------------------------
template<class T, int N>
class vector_p{
public:
    vector_p();
    vector_p(int size);
    T& operator[](int n);
    void push_back(T elem);
    int size() { return sz; }
private:
    int sz;
    Pool<T, N> pool;
    T* first;
};
//------------------------------------------------------------------------------
template<class T, int N>
vector_p<T,N>::vector_p():sz(0),pool()
{
    
}
//------------------------------------------------------------------------------
template<class T, int N>
vector_p<T,N>::vector_p(int size):sz(size),pool()
{
   
    first=pool.get();
}
//------------------------------------------------------------------------------
template<class T, int N>
T& vector_p<T,N>::operator[](int n)
{
    if(n>=N || n<0 )
    {
        cerr<<"bad index\n";
        return *first;
    }
    if(n==0)
        return *first;
    int k=0; 
    T * p = first;
    
    while(k!=n)
    {
        p++;
        k++;
    }  
    return *p;

}
//------------------------------------------------------------------------------
template<class T, int N>
void vector_p<T,N>::push_back(T elem)
{
    if(sz==0 )
    {
        
        first=pool.get();
        *first=elem;
        sz++;
    }else
    {
        T*c =pool.get();
        *c=elem;
        sz++; 
    }
}
//------------------------------------------------------------------------------
int main()
{
 
    

    vector_p<int,7> v;
    v.push_back(5);
    cout << "v size: " << v.size() << '\n';
    cout << "v[0]: " << v[0] << '\n';

    vector_p<int,1000> v3;
    for (int i = 0; i<1000; ++i)
        v3.push_back(i);
    cout << "v3 size: " << v3.size() << '\n';
    for (int i = 0; i<1000; ++i)
        cout<<v3[i];
     
}
//-----------------------------------------------------------------------------