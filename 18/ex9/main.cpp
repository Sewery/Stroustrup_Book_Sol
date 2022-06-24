#include <math.h>

#include "../../std_lib_facilities.h"

int a =100;
int b =200;
int c =300;

int main(){

  try { 
    //stATIC memory is growing down

   cout<<&a<<'\t'<<&b<<'\t'<<&c<<'\n';
    
     //heap  memory is growing  up
    int* p = new int[2];
    p[0]=2;
    p[1]=2;
    int* k = new int[2];
    k[0]=2;
    k[1]=2;
     int* e = new int[2];
    e[0]=2;
    e[1]=2;
   
    cout<<p<<'\t'<<k<<'\t'<<e<<'\n';
    //stack memory is growing down
    
    int kr =100;
    int ha =200;
    int xr =100;
     
      
    cout<<&kr<<'\t'<<&ha<<'\t'<<&xr<<'\n';
    
    

    if(&a<&kr && &kr<p)cout<<"first static , second stack,third heap ";

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

 
}

