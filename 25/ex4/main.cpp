// This is example code from Chapter 25.5.2 "Bitset" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <bitset>
#include <iostream>

using namespace std;


//------------------------------------------------------------------------------
void ex4()
{
    for(;;){}
}
//------------------------------------------------------------------------------
void ex5()
{
    unsigned char k = 177;
    for(char i =0;i!=k;i++)
        cout<<int(i)<<'\t';
}
//------------------------------------------------------------------------------
void ex6()
{
    for(int i =0;i!=400;i++)
        cout<<hex<<i<<'\n';
     for(int i =-200;i!=200;i++)
        cout<<hex<<i<<'\n';
}
//------------------------------------------------------------------------------
void ex7()
{
     for(char i =97;i!=123;i++)
        cout<<i<<' ';
}
//------------------------------------------------------------------------------
void ex8()
{
    int i;
    for(i =1; i>0;i++)
    {
    }
    //cout<<i;
    //i is the highest negative value of number
    int count=1;//we start from one since we also need to take into account positive numbers
    while(i!=-1)
    {
        i/=2;//number of divisions of this number is equal to number of bits
        count++;
    }
    cout<<"Bits: "<<count;
}
//------------------------------------------------------------------------------


int main()
try
{
   ex8();
}catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
