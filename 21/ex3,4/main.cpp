#include "../../std_lib_facilities.h"
#include <numeric>

template <class InputIterator, class T>
int count_m(InputIterator first, InputIterator last, const T& val)
{
    int count =0;
    while(first!=last)
    {
        if(*first==val)count++;
        first++;
    }
    if(*first==val)count++;
    return count;
}

template <class InputIterator, class T>
InputIterator find_m(InputIterator first, InputIterator last, const T& val)
{
   
    while(first!=last)
    {
        if(*first==val)return first;
        first++;
    }
    if(*first==val)return first;
    return ++first;
}

void test()
{
    vector<int> p {1,5,3,423,1,1,8};
    int c = count_m(p.begin(),p.end()-1,8);
    int d = count_m(p.begin(),p.end()-1,869);
    cout<<c<<'\t'<<d<<'\n';

    auto it = find_m(p.begin(),p.end()-1,8);
    auto it2 = find_m(p.begin(),p.end()-1,879);
    cout<<*it<<'\t'<<*it2<<'\n';


}

int main()
{

    try
    {
        test();
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
