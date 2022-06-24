#include "../../std_lib_facilities.h"
template<class Iter>
Iter find_biggest_string(Iter first, Iter last)
{
    Iter high = first;
    while(first!=last)
    {
        if(*high<*first)
        {
            high=first;
        }
        first++;
    }
    return high;
}
void test()
{
    vector<string> vec{"Anna","Marcin","XYZZZZZZ","IamTheBestInTheWorld","XYowoqwo"};
    cout<<*find_biggest_string(vec.begin(),vec.end());

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
