#include <math.h>

#include "../std_lib_facilities.h"

void print_array10(ostream& os, int*a){
    os<<"\nJedziemy: ";
    for(int i=0; i< 10;i++){
      os<<a[i]<<" ";
    }
}
void print_array(ostream& os, int*a,int n){
    os<<"\nJedziemy: ";
    for(int i=0; i< n;i++){
      os<<a[i]<<" ";
    }
}
void print_vector(ostream& os, vector<int> a){
    os<<"\nJedziemy: ";
    for(int i=0; i< a.size();i++){
      os<<a[i]<<" ";
    }
}
void drill1(){
   int* k = new int[10];
    for(int i=0; i< 10;i++){
      k[i]=100+i;
      cout<<k[i]<<" ";
    }
      delete[] k;
    cout<<'\n';
     int* k1 = new int[11];
    for(int i=0; i< 11;i++){
      k1[i]=100+i;
      cout<<k1[i]<<" ";
    }
      delete[] k1;
    cout<<'\n';
     int* k2 = new int[20];
    for(int i=0; i< 20;i++){
      k2[i]=100+i;
      cout<<k2[i]<<" ";
    }
      delete[] k2;
   print_array10(cout,k);
  cout<<"VECTORy \n";
   vector<int> k0 (10);
    for(int i=0; i< k0.size();i++){
      k0[i]=100+i;
      cout<<k0[i]<<" ";
    }
   
    cout<<'\n';
      vector<int> k11 (11);
    for(int i=0; i<k11.size();i++){
      k11[i]=100+i;
      cout<<k11[i]<<" ";
    }
    
    cout<<'\n';
      vector<int> k22 (20);
    for(int i=0; i<k22.size() ;i++){
      k22[i]=100+i;
      cout<<k22[i]<<" ";
    }
}
void drill2();
int main(){
   drill2();
}
void drill2(){
  int * p1 = new int(7);
  cout<<*p1<<'\n';
  int* p2 = new int[7] {2,4,6,8,10,12,14};
  cout<<*p2<<'\n';
  int* p3=new int(*p3);
  //*p3=*p2;
  p1=p2;
  p3=p2;
  cout<<*p1<<" "<<*p2<<" "<<p1<<" "<<p2<<'\n'; 
  cout<<"xd";
  delete[]p2;
  delete p1;
  delete p3;
  int* k =new int[10]{2,4,6,8,10,12,14,16,18,20};
  k=p1;
   int* k1 =new int[10];
  k1=p1;
  *p2=*p1;
  cout<<*p1<<'\n'<<*p2<<'\n'<<*k<<'\n'<<*k1;
  vector<int> k0{2,4,6,8,10,12,14,16,18,20};
  //*k0=p1;
 vector<int> k11(10);
  // *k11=p1;
  *p2=*p1;
  cout<<*p1<<'\n'<<*p2<<'\n'<<*k<<'\n'<<*k1;
}