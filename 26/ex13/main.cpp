
#include <chrono>
#include <iostream>
#include <vector>
#include <exception>
#include <random>
#include <chrono>
#include <algorithm>


using namespace std;
using namespace chrono;


//------------------------------------------------------------------------------

inline int randint(int max) { 
    return rand()%max; }
//------------------------------------------------------------------------------

string randstr( int l) 
{
    string s;
    for(int i=0; i<l;i++)
    {
        s+= (char) randint(numeric_limits<char>::max());
    }
    return s;
}
//------------------------------------------------------------------------------

int main()
{
    srand(time(nullptr));
    constexpr int size1 = 500000;
    constexpr int size2= 5000000;
    vector<string> v1;
        for (int i = 0; i < size1; ++i){
            v1.push_back(randstr(randint(100)));
        }
    auto t1 = steady_clock::now();//staring clock   
    sort(v1.begin(),v1.end());   
    auto t2 = steady_clock::now();    
       
     cout << "For size "<<v1.size()<<" , operation sorting string vector persist for: "
        << duration_cast<milliseconds>(t2 - t1).count()/1000.0 << " seconds\n";
    ///////////////////////////////////////////////////////////////////////////
     vector<string> v2;
        for (int i = 0; i < size2; ++i){
            v2.push_back(randstr(randint(100)));
        }
    auto t11 = steady_clock::now();//staring clock   
    sort(v2.begin(),v2.end());   
    auto t22 = steady_clock::now();    
       
     cout << "For size "<<v2.size()<<" operation sorting string vector persist for: "
        << duration_cast<milliseconds>(t22 - t11).count()/1000.0 << " seconds\n";   

}

//------------------------------------------------------------------------------
