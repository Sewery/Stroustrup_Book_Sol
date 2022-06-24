#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//------------------------------------------------------------------------------

int main()
{
    map<string,int> words;    

    string s;
    while (cin>>s) ++words[s];    
     
    vector<pair<int,string>> words_freq;
    typedef map<string,int>::const_iterator Iter;
    Iter b = words.begin();
    while(b!=words.end())
    {
        words_freq.push_back(pair<int,string>(b->second,b->first));
        b++;
    }
    typedef vector<pair<int,string>>::const_iterator It;
     
  
    sort(words_freq.begin(),words_freq.end(),[](pair<int,string>& a, pair<int,string>&b){return a.first<b.first;});
    
    for (It  p = words_freq.begin(); p!=words_freq.end(); ++p)
        cout << p->first << ": " << p->second << '\n';
}

//------------------------------------------------------------------------------