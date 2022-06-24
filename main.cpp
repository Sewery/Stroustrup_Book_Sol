
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <climits>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <memory.h>
#include <map>
using namespace std;
 

#define ll long long int
#define un unsigned
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << x << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(), x.end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define X first
#define Y second
#define PI (3.141592654)
ll moder= pow(10,9)+7;
const int MAXN = 1000 * 1 + 10, INF = 1e9 + 10;

void _fake(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
         
}




int main ()
{
    _fake();
    ll n,x;
    cin>>n>>x;
    map<ll,ll> v;
    for(ll i=0; i<n; i++)
    {
        ll a;
        
        cin>>a;

        v[a]++;

    }
   for(ll i=0; i<x; i++)
    {
        ll a;
        cin>>a;
        if(v.empty())
        {

            cout<<-1<<"s\n";
            continue;
        }
        auto it= v.lower_bound(a);

       
        if(it->first<=a)
        {

            cout<<it->first<<'\n';
            cout<<"ewe";
            v.erase(it);
        }else
            cout<<-1<<'\n';
           
         
    }
    
}    
    