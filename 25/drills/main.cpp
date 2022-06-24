#include "../../std_lib_facilities.h"
#include<bitset>

#include<iomanip>
void print(  short unsigned int su)
{
    cout<<dec<<su<<"=="<<hex<<"0x"<<su<<"=="<<bitset<16>(su)<<'\n';
}
void drill3()
{
    //1,2
    int v=1; for(int i=0;i<sizeof(v)*8;++i){ cout<<v<<' '; v<<=i; }
    cout<<'\n';
    unsigned int v2=1; for(int i=0;i<sizeof(v2)*8;++i){ cout<<v2<<' '; v2<<=i; }
    //3
    short unsigned int su = 0xffff;
    print(su);
    su=0x0001;
    print(su);
    su=0x8000;
    print(su);
    su=0x00ff;
    print(su);
    su=0x5555;
    print(su);
    su=0xaaaa;
    print(su);
   
}
void drill4()
{
   
   
    //4
    short unsigned int su = -1;
    print(su);
    su=1;
    print(su);
    su=-1;
    su<<=8;
    print(su);
    su=~su;
    print(su);
      
    su = 1;
    su |= su<<2;
    su|= su<<4;
    su |= su<<8;
    print(su);
    su = ~su;   
    print(su);
   
}

int main()
{

    try
    {
       drill4();
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
