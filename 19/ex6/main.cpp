#include <math.h>

#include "../../std_lib_facilities.h"

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
  Number<int> b = a;
  cout<<b;
  Number<int> k = a+b;
  Number<int> c= k*b;
  cout<<" "<<k<<" "<<c;
  c=300;
  a=180;
  cout<<"int%: "<<c%a<<'\n';
  Number<double> d = 43435.05;
   Number<double> e = 45.765;
 //doesn't work cout<<"double%: "<<d%e<<'\n';

  cout<<" "<<c;
}