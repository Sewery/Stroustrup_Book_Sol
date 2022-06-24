#include <math.h>

#include "../../std_lib_facilities.h"


template<typename T> struct S {
  private:
  T val;
  public:
  S(T t):val{t}{}
  T& get();
  T& operator=(const T&);
};
template<typename T>
T& S<T>::get(){return val;}
template<typename T>
T& S<T>::operator=(const T& t){
  this->val=t.val;
  return *this;
}
void read_val(){
  string a;
  cin>>a;
  S<string> a1{a};
  cout<<a1.get()<<'\n';
  
  int b;
  cin>>b;
  S<int> a11{b};
  cout<<a11.get()<<'\n';
  
  char c;
  cin>>c;
  S<char> c1{c};
  cout<<c1.get()<<'\n';

  double d;
  cin>>d;
  S<double> d1{d};
  cout<<d1.get()<<'\n';

}
template<class T> istream& operator>>(istream& k, vector<T>& a){
    T p;
    int counter =0;
    char e;
    vector<T> tem
    while(is>>tem>>e && e==',' ){
      if(!is)error("Sth went wrong");
      tem.push_back(p);
      if(e!=',')break;
    }
    a=tem;

}
template<class T> ostream& operator<<(ostream& k, const vector<T>& a){
 for(auto k : a){
   cout<<k<<',';
 }

 cout<<'\n';

}

int main(){
  read_val();
}