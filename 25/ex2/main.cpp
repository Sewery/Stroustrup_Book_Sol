
#include <iostream>
#include <bitset>
using namespace std;

void ex()
{
    unsigned int usi =0;
    bitset<32> s;
    s=usi;
    cout<<s<<'\n';
    s=~usi;
    cout<<s<<'\n';
    s=0xaaaaaaaa;
    cout<<s<<'\n';
    s=0x55555555;
    cout<<s<<'\n';
    s=0xcccccccc;
    cout<<s<<'\n';
    s=~s;
    cout<<s<<'\n';
    s=0xff00ff00ff00;
    cout<<s<<'\n';
    s=~s;
    cout<<s<<'\n';

    s=0xf0f0f0f0f0f0;
    cout<<s<<'\n';
    s=~s;
    cout<<s<<'\n';
}
//----------------------------------------------------


int main()
{

    try
    {
        ex();
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
