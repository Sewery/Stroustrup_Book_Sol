#include <math.h>

#include "../../std_lib_facilities.h"
template<class T ,class U> 
int mul_two_vectors(vector<T>& v1, vector<U>& v2 ){
 
    int sum =0;
    for(int i =0; i< v1.size();i++){
      if(v2.size()-1<i) return sum;
      sum +=(int)v1[i]*(int)v2[i];
    }
 
  
  return sum;
}
template<class T >class Number{
private:
  T a;
public:
  Number(): a{0}{}
  Number(T s):a{s}{}

  Number(const  Number& va) : a{va.a} { }  
  Number& operator=(const  Number& r){ a= r.a;  }
  
  ~Number(){}
  T get() const{return a;}
  

};
template<class T >
ostream& operator<<(std::ostream& os, const Number<T>& obj)
{
    os<<obj.get();
    return os;
}
template<class T >
istream& operator>>(std::istream& is, Number<T>& obj)
{
  int a;
  is>>a;
  obj=a;
  if( !is )is.setstate(ios::failbit);
  return is;
}
template<class T >
Number<T> operator+(const Number<T>& rhs,const Number<T>& r) 
{                           
  return Number<T>(rhs.get()+r.get()); 
}
template<class T >
  Number<T> operator-(const Number<T>& rhs,const Number<T>& r) 
{                           
  return Number<T>(rhs.get()-r.get());
}
template<class T >
Number<T> operator*(const Number<T>& rhs,const Number<T>& r) 
{                           
  return Number<T>(rhs.get()*r.get());
}
template<class T >
Number<T> operator/(const Number<T>& rhs,const Number<T>& r) 
{                           
  return Number<T>(rhs.get()/r.get());
}  
template<class T >
Number<T> operator%(const Number<T>& rhs,const Number<T>& r) 
{                           
  return Number<T>(rhs.get()%r.get());
}  
 
 
int main(){

  Number<int> a = 10;
  Number<int> b = 32;
  Number<int> c = 32;

  Number<int> d = 43;
  Number<int> e = 65;
  Number<int> f = 435;
  vector<Number<int>> xd1;
  xd1.push_back(a);
  xd1.push_back(b);
  xd1.push_back(c);

 vector<Number<int>> xd2;
  xd2.push_back(d);
  xd2.push_back(e);
  xd2.push_back(f);

  mul_two_vectors(xd1,xd2);
  //Doesn't work
  //for(auto p: xd1) cout<<p<<" ";
}