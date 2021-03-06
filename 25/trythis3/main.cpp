// This is example code from Chapter 25.5.2 "Bitset" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <bitset>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void test()
{
    bitset<4> flags = 0xb;
    bitset<128> dword_bits(string("1010101010101010"));
    bitset<12345> lots;

    string s;
    cin>>s;
    bitset<12345> my_bits(s);    // may throw std::invalid_argument 
    bitset<32> b1, b2, b3;

    b1 = b2&b3;                  // and
    b1 = b2|b3;                  // or
    b1 = b2^b3;                  // xor
    b1 = ~b2;                    // complement
    b1 = b2<<2;                  // shift left
    b1 = b2>>3;                  // shift right

    bitset<32> b;

    cin>>b;                      // read a bitset from input
    cout<<bitset<8>('c');        // output the bit pattern for the character 'c'
}
//------------------------------------------------------------------------------
template<class T> void print(T i){cout<<i<<'\t';}
void print(char i){cout<<int(i)<<'\t';}
void print(signed char i){cout<<int(i)<<'\t';}
void print(unsigned char i){cout<<int(i)<<'\t';}
//------------------------------------------------------------------------------
void try_this_4()
{
    int si=128;
    char c=si;
    unsigned char uc =si;
    signed char sc =si;
    print(si); print(c); print(uc); print(sc);
}
//------------------------------------------------------------------------------
void infinite()
{
    unsigned char max =160;
    for(signed char i=0; i<max;++i)cout<<int(i)<<'\n';
}
//------------------------------------------------------------------------------
void try_this_2(){
 const int max = 10;
    bitset<max> b;
    while (cin>>b) {
        cout << b << '\n';
        for (int i =0; i<max; ++i) cout << b[i];    // reverse order
        cout << '\n';
    }
}    
int main()
try
{
   try_this_4();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
