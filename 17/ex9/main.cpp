#include <math.h>

#include "../../std_lib_facilities.h"
char* increase_size(char* k){
}
int main(){
try { 
    
    //stack memory is growing down
    
    int kr =100;
    int ha =200;
    int xr =100;
     
      
    cout<<&kr<<'\t'<<&ha<<'\t'<<&xr;
    
   
    cout<<'\n';
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
   
    cout<<p<<'\t'<<k<<'\t'<<e;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

}