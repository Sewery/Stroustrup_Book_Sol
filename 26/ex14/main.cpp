
#include <chrono>
#include <iostream>
#include <vector>
#include <exception>
#include <random>
#include <chrono>
#include <algorithm>
#include <set>

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

    auto t1 = steady_clock::now();//staring clock
    set<string> s1;
    while (s1.size()!=size1){
        s1.insert(randstr(randint(100)));
    }
    
    auto t2 = steady_clock::now();    
       
     cout << "For set size "<<s1.size()<<" , operation adding randdom string persist for: "
        << duration_cast<milliseconds>(t2 - t1).count()/1000.0 << " seconds\n";
    ///////////////////////////////////////////////////////////////////////////

    auto t11 = steady_clock::now();//staring clock   
    set<string> s2;
    while (s2.size()!=size2){
        s2.insert(randstr(randint(100)));
    }
 
    auto t22 = steady_clock::now();    
       
     cout << "For set size "<<s2.size()<<", operation adding random string persist for: "
        << duration_cast<milliseconds>(t22 - t11).count()/1000.0 << " seconds\n";   

}

//------------------------------------------------------------------------------
