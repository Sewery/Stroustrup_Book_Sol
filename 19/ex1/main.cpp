#include <math.h>

#include "../../std_lib_facilities.h"

template<class T> void add_two_vectors(vector<T>& v1, vector<T>& v2 ){
  for(int i =0; i< v1.size();i++){
    if(v2.size()-1<i) return;
    
    v1[i]+=v2[i];
  }
}

int main(){
  vector<int> v1 {4,3,0};
  vector<int> v2 {1,2,3,4};
  add_two_vectors(v1,v2);
  for(auto p: v1) cout<<p<<" ";  

  vector<string> v11 {"heuwhe","jejw","ewje"};
  vector<string> v22 {"ewe","ewe","ewew","jijfi"};
  add_two_vectors(v11,v22);
  for(auto p: v11) cout<<p<<" ";  
}