#include "../../std_lib_facilities.h"

template<class Iter>
void printt(Iter first, Iter last)
{
    cout << "{";
    while (first != last) {
        cout << " " << *first;
        ++first;
    }
    cout << " }\n";
}
void v(list<int>& p)
{
    vector<double> k ;
    list<int>::const_iterator it = p.begin();
    while(it!=p.end())
    {
        k.push_back(*it);
        it++;
    }
    cout<<"Vector size "<<k.size()<<'\n';
    cout<<"List size "<<p.size()<<'\n';

    cout<<"Vector elemnts:";printt(k.begin(),k.end());
    cout<<"List elements:";printt(p.begin(),p.end());

   
    sort(k.begin(),k.end());
    
    cout<<"Vector elements (sorted):";printt(k.begin(),k.end());
   


}
void test()
{
    list<int> i {1,65,2,1,4556,61};
    v(i);
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
