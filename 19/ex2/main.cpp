#include <math.h>

#include "../../std_lib_facilities.h"
//****MOZNA TO ZROBIC LEPIEJ ALE BRAKUJE MI ODPOWIEDNICH NARZEDZI TERAZ BY TO ZROBIC
template<class T ,class U> 
int mul_two_vectors(vector<T>& v1, vector<U>& v2 ){
  try{
    int sum =0;
    for(int i =0; i< v1.size();i++){
      if(v2.size()-1<i) return sum;
      sum +=(int)v1[i]*(int)v2[i];
    }
  }catch(exception& ar ){
        cerr<<"Wystapil nieoczekiwany blad:"<<ar.what();
        return -1;
  }catch(...){
        cerr<<"Wystapil nieoczekiwany blad";
        return -2;
  }
  
  return sum;
}

int main(){
  vector<int> v1 {4,3,0};
  vector<int> v2 {1,2,3,4};
  mul_two_vectors(v1,v2);
  for(auto p: v1) cout<<p<<" ";  

//Nie dziala kod ponizej
  vector<string> v11 {"heuwhe","jejw","ewje"};
  vector<string> v22 {"ewe","ewe","ewew","jijfi"};
  mul_two_vectors(v11,v22);
  for(auto p: v11) cout<<p<<" ";  
}