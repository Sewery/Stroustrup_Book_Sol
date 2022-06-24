#include <math.h>

#include "../../std_lib_facilities.h"

//1
void f(int k[], int n);
int ga[] = {1,2,4,8,16,32,64};
//2
void fv(vector<int>);
vector<int> gv{1,2,4,8,16,32,64,124,256,512};

void drill1();
void drill2();


int main(){
  drill2();
}
void f(int k[], int n)
{
  int la[10];
  copy(ga,ga+7,la);
  //while(la)
  for(int i=0; i< 10;i++) cout<<la[i]<<" ";
  int *p =new int[n];
  cout<<'\n';
  copy(k,k+n,p);
  for(int i=0; i< n;i++) cout<<p[i]<<" ";
  delete[] p;
  cout<<"koniec\n";
}
void drill1(){
  f(ga,7);
  int aa[] = {1,2*1, 3*2, 3*4*2 , 5* 4*3*2, 20*6*6, 120*6 *7,720* 7*8,720* 7*8*9,7200* 7*8*9};  
  f(aa,10);
}
void fv(vector<int> v){
  vector<int> lv(v.size());
  lv=gv;
  for(auto p: lv)cout<<p<<" ";
  vector<int> lv2{v};
  cout<<'\n';
  for(auto p: lv2)cout<<p<<" ";
  cout<<"koniec\n";
}
void drill2(){
  fv(gv);
  vector<int> vv{1,2*1, 3*2, 3*4*2 , 5* 4*3*2, 20*6*6, 120*6 *7,720* 7*8,720* 7*8*9,7200* 7*8*9};
  fv(vv);


}

