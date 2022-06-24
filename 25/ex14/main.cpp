
#include "../../std_lib_facilities.h"

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
            is_used[i]=false;
            f++;
            return;
        }   
    }   
}

//------------------------------------------------------------------------------
int main()
{
 
    

     
}
//-----------------------------------------------------------------------------