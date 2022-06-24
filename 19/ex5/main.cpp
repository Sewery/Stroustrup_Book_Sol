#include <math.h>

#include "../../std_lib_facilities.h"

class Int{
private:
  int a;
public:
  Int(): a{0}{}
  Int(int s):a{s}{}

  Int(const Int& va) : a{va.a} { }  
  Int& operator=(const Int& r){ a= r.a;  }
  
  ~Int(){}
  int get() const{return a;}
  Int& operator+=(const Int& rhs) 
  {                           
    
    return *this; 
  }
   Int& operator-=(const Int& rhs) 
  {                           
    Int* i=this;
    i->a= this->a -rhs.a; 
    return *this; 
  }

};
ostream& operator<<(std::ostream& os, const Int& obj)
{
    os<<obj.get();
    return os;
}
istream& operator>>(std::istream& is, Int& obj)
{
  int a;
  is>>a;
  obj=a;
  if( !is )is.setstate(std::ios::failbit);
  return is;
}

  Int operator+(const Int& rhs,const Int& r) 
  {                           
    return Int(rhs.get()+r.get()); 
  }
   Int operator-(const Int& rhs,const Int& r) 
  {                           
   return Int(rhs.get()-r.get());
  }
   Int operator*(const Int& rhs,const Int& r) 
  {                           
   return Int(rhs.get()*r.get());
  }
   Int operator/(const Int& rhs,const Int& r) 
  {                           
   return Int(rhs.get()/r.get());
  }
 
int main(){
  Int a = 10;
  Int b = a;
  cout<<b;
  Int k = a+b;
  Int c= k*b;
  cout<<" "<<k<<" "<<c;
  c=300;
  cout<<" "<<c;
}