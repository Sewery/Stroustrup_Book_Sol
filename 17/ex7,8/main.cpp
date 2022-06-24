#include <math.h>

#include "../../std_lib_facilities.h"
char* increase_size(char* k){
    int i=0;
    while(k[i]!=0){
        i++;       
    }
    char* ke = new char[i+2];
    for(int e=0; e<i;e++){
       ke[e]=k[e];
    }
    ke[i]=0;
    ke[i+1]=0;
    delete[] k;
    return ke;
}
int main(){
try {
   int i=1;
    char *k =new char[1];
    k[0]=0;
    char kr;
   
    while(cin>>kr && kr!='!'){
        k = increase_size(k);
        k[i-1]=kr;
        k[i]=0;
        i++;
    }
    cout<<i<<'\n';
  
    for(int e=0; e< 5 ;e++){
        cout<<k[e];
    }
 
    //now by string
    char kp;
    string p="";
    while(cin>>kp && kp!='!'){
        p.push_back(kp);//p+=kp;
    }
    cout<<"\n"<<p;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

}