#include "../../std_lib_facilities.h"
#include <numeric>
//ex3
template <class InputIterator, class T>
int count_m(InputIterator first, InputIterator last, const T& val)
{
    int count =0;
    while(first!=last)
    {
        if(*first==val)count++;
        first++;
    }
    return count;
}
//ex4
template <class InputIterator, class Pred>
int count_if_m(InputIterator first, InputIterator last,Pred p)
{
    int count =0;
    while(first!=last)
    {
        if(p(*first))count++;
        first++;
    }
    return count;
}

void test()
{
    //ex3
    vector<int> p {1,5,3,423,1,1,8};
    cout<<count_m(p.begin(),p.end(),1)<<'\n';

    list<string> ls{"ewe","Jhew","hnuhe","ewe","poqo"};
    cout<<count_m(ls.begin(),ls.end(),"ewe")<<'\n';

    //ex4
    cout<<count_if_m(ls.begin(),ls.end(),[](string& p){return "What">p;})<<'\n';
    cout<<count_if_m(p.begin(),p.end(),[](int& pr){return pr%2==0;})<<'\n';
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
