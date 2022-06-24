#include <math.h>

#include "../../std_lib_facilities.h"

char* findx(const char* s, const char* x){
  
  
      int xx =0;
      while(*s){
        while(*x==*s){
        
            xx++;
            x++;
           
            if(!*x)return const_cast<char *>(s+1);
            s++;

             
        }
        if(s==0)return 0;
        s++;
       
        x-=xx;
        xx=0;
     
      
      }

    
    
    return 0;
}
int strcmp(const char* s1 , const char* s2){
    while(*s1){
      if(*s1>*s2 || s2==0) return 1;
      if(*s1<*s2 || s1==0) return -1;
      s1++;
      s2++;

    }
    return 0;
}
void print (char *k){
 
  while(*k)cout<<*k++;

}

int main(){
    // test exercise 2
    char s2[] = {'x','d','e','r','i','k'};
    char x[] = {'d','e'};
    cout << "s: " << s2 << "\n";
    cout << "x: " << x << "\n";
    print(findx(s2,x));
    cout << "\n";
    cout<< strcmp(s2,x);
}


