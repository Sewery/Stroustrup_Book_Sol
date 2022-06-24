#include <math.h>

#include "../../std_lib_facilities.h"
void print_array(char* s) {
    cout<<"Lecimy: ";
    for (int i = 0; s[i]; ++i) {
      
        cout << s[i];
    }
}
void to_lower(char*s){
  int i=0;
  while(s[i]!=0){
    if(s[i]>64 && s[i]<91){
      s[i]+=32;
    }
    i++;
  }
}
char* stroup(const char* s){
  int i=0;
  while(s[i]!=0){
    i++;
  }
    char *k = new char[i+1];
  for(int e=0; e<i;e++){
    k[e]=s[e];
  }
  k[i]=0;
  delete[] s;
  return k;
}
const char* findx(const char* s, const char *x){
     int sk=0;
    while(true){
      int xi=0;
      while(s[xi+sk]==x[xi]){
        if(x[xi+1]==0) return &s[sk];
        xi++;
        
      }
      sk+=xi+1;
    }
    return 0;
}

int main(){
  
  int a=1;
  int *aa = &a;
  cout<<"Integer: "<<sizeof(int)<<","<<sizeof(a)<<","<<sizeof(aa)<<'\n';
  double b=1;
  double *bb= &b;
  cout<<"Double: "<<sizeof(double)<<","<<sizeof(b)<<","<<sizeof(bb)<<'\n';
  bool c=true;
  bool* cc=&c;
  cout<<"Bool: "<<sizeof(bool)<<","<<sizeof(c)<<","<<sizeof(cc)<<'\n';
  string p ="WItamy Ludzie";
  char *s = &p[0];//new char[10]{'W','t','a','n',' ','L','u','d','Z',0};
  string u1 ="tamy lud";
  const char *u =&u1[0];
  to_lower(s);
  for(int i=0;i<p.size();i++){
    cout<<s[i];
  }
 cout<<'\n';
 
 try {
   char* ss = "Does this work with whitespace, too?";
    char* xx = "work with";
    char* sr = new char[strlen(ss)+1];
    strcpy(sr,ss);
    char* x = new char[strlen(xx)+1];
    strcpy(x,xx);
  
    const char* sub = findx(sr,x);

    if (!sub) cout << "Not found!\n";
    else cout << sub << "\n";
    delete[] sr;
    delete[] x;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
   
}