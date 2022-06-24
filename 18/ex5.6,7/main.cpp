#include <math.h>

#include "../../std_lib_facilities.h"

string cardot(const string& s, const string& x, const string& e){
  
  return s+e+x;
}
void print (char *k){
 
  while(*k)cout<<*k++;

}
char* findx(const char* s, const char* x,const char* e){
  const char * z=s;
  int sr=0;
  while(*z){sr++; z++;}
  z=x;
  while(*z){ sr++; z++;}
  z=e;
  while(*z){ sr++; z++;}
 
  char *xd =new char[sr+1];



  z=s;
  char * ret= xd;
  while(*z){*ret=*z;ret++;z++;}
  z=x;
  while(*z){*ret=*z;ret++;z++;}
  z=e;
  while(*z){*ret=*z;ret++;z++;}
  *ret=0;
   

  return xd;
}


int main(){
  char e1[]= "Jedziemy ";
  char e2[]= "w gory";
  char e3[]= "bawic sie ";

  print(findx(e1,e2,e3));
}
  


