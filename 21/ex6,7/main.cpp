#include "../../std_lib_facilities.h"
#include <numeric>
#include <set>
//ex6
struct Fruit{
    Fruit(string s, int i):name{s},count{i}{}
    string name;
    int count;
    double unit_price;
};
struct Fruit_order{
    bool operator()(const Fruit& a , const Fruit& b)const
    {
        return a.name<b.name;
    }
};
struct Fruit_comparsion{
    bool operator()(const Fruit *a , const Fruit *b)const
    {
        return a->name<b->name;
    }
};
//ex7
//For vector(random access iterator)
template<class Ran, class T>
bool binary_search_rai(Ran first, Ran last, const T& val)
{
    if(first==last)return false;
    Ran mid = first + (last-first)/2;
    if(val==*mid)return true;
    if(val>*mid)return binary_search(mid,last,val);
    if(val<*mid)return binary_search(first,mid,val);
    return false;
}
//For list(bidirectional itearator)
template<class Ran>
Ran mid_bid(Ran first, Ran last)
{
    int counter=0;
    Ran v = first;
    while(v!=last)
    {
        v++;
        counter++;
    }
    Ran mid= first;
    for(int i=0; i<counter;i++)
    {
        mid++;
    }
    return mid;
}

template<class Ran, class T>
bool binary_search_bid(Ran first, Ran last, const T& val)
{
    if(first==last)return false;
    Ran mid = mid_bid(first,last);
    if(val==*mid)return true;
    if(val>*mid && ++mid!=last)return binary_search(--mid,last,val);
    if(val<*mid)return binary_search(first,mid,val);
    return false;
}



void test()
{
    //ex6
    set<Fruit*,Fruit_comparsion> se;
    se.insert(new Fruit("jablko",1));
    se.insert(new Fruit("wisnia",21));
    se.insert(new Fruit("jeczmien",8));
    se.insert(new Fruit("arbuz",11));
    for(const auto& x:se)cout<<x->name<<" ";
    for(const auto& x:se)delete x;
    //ex7
    cout<<"\nVector:\n";
    vector<int> p {1,4,6,1,56,2683,287,12,7};
    sort(p);
    cout<<"result for 1= "<<binary_search_rai(p.begin(),p.end(),4)<<'\n';

    list<int> l {1,4,6,1,56,2683,287,12,7};
    l.sort();
    cout<<"Lista:\n";
    cout<<"result for 1= "<<binary_search_bid(l.begin(),l.end(),1)<<'\n';
    cout<<"result for 7547897= "<<binary_search_bid(l.begin(),l.end(),7547897);
  

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
