#include "../../std_lib_facilities.h"
template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    cout<<"{";
    for(auto p: vec)
    {
        if(*(vec.end()-1)==p)cout<<" "<<p<<" }";
        else cout<<" "<<p<<",";
    }
    return os;
}
template<class T>
istream& operator>>(istream& is,  vector<T>& vec)
{
    T k;
    char c;
    while(is>>c)
    {
        if(c=='.')break;
        else is.unget();
        is>>k;
        if(!is)error("Bad input");
        vec.push_back(k);
    }
    return is;
}


int main()
{

    try
    {

        vector<int> p;
        p.push_back(34);
        p.push_back(54);
        p.push_back(34);
        p.push_back(14);
        p.push_back(64);

        cout<<p;
        cin>>p;
        cout<<p;

      
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
