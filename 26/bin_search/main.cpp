#include "../../std_lib_facilities.h"
//------------------------------------------------------------------------------

template<class Iterator,class T>
bool bin_search(Iterator begin ,Iterator end, const T& value)
{
    int size = end - begin;
    if(size==0)
        return false;
    int mid = size / 2;
    Iterator t = begin + mid;
    if (*t == value)
        return true;
    if (t == begin)
        return false;
    else if (*t > value)
        return bin_search(begin, t, value);
    else if (*t < value)
        return bin_search(t, end, value);
    return false;
}
//------------------------------------------------------------------------------
template<class Iterator,class T>
bool bin_search_nor(Iterator begin ,Iterator end, const T& value)
{
    int size= end- begin;
    int mid = size/2;
    Iterator t = begin+ mid; 
    while(true)
    {
       
        if(*t==value)
            return true;
        mid = (t-begin)/2;
        if(t==end|| 0==t-begin)
            return false;
        else if(*t>value){
            mid = (t-begin)/2;
            t=  begin+ mid;
        }    
        else if(*t<value){
            mid = (end-t)/2; 
            t=  end - mid; 
        }   
        else
            return false;
    }
}
//------------------------------------------------------------------------------
int main()
{
    vector<int> vec{1,3,4,5,6,7,8,9};
    cout<<bin_search(vec.begin(),vec.end(),1)<<bin_search_nor(vec.begin(),vec.end(),2)<<'\n';
    cout<<bin_search(vec.begin(),vec.end(),-1)<<bin_search_nor(vec.begin(),vec.end(),-1)<<'\n';
    cout<<bin_search(vec.begin(),vec.end(),9)<<bin_search_nor(vec.begin(),vec.end(),9)<<'\n';
    cout<<bin_search(vec.begin(),vec.end(),100)<<bin_search_nor(vec.begin(),vec.end(),100)<<'\n';

}
//------------------------------------------------------------------------------
