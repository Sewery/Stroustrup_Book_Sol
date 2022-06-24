#include <math.h>

#include "../../std_lib_facilities.h"

char* strdup(const char* k){
  int n=0;
  while(*k){
    n++;*k++;
  }

  char* x = new char[n];
  k-=n;

  while(*k){
    *x=*k;
    cout<<*x;
    x++;
    k++;
  }
  *x=0;
  x-=n;
  return x;
}
void print (char *k){
  while(*k)cout<<*k++;

}
//////////////////////////////////////////////////////////////ASK
int* f(){
  int x=7;
  return &x;
}
int main(){
    char pe[] = "Jedziemy";
    char * k = strdup(pe);
    print(k);
    int *p = f();
    *p= 18;
    cout<<*p;
}


