#include "../../std_lib_facilities.h"
void reverseTheFile(string& name){
    ifstream ifs{name};
    
    vector<string> p;
  for(string k; getline(ifs,k);){
      reverse(k.begin(),k.end());
        p.push_back(k);
        
    }
    reverse(p.begin(),p.end());
    ifs.close();
    ofstream ofs{name};
    for(auto ha :p ) ofs<<ha<<'\n';

}
int main(){
    string p = "plik.txt";
    reverseTheFile(p);
    return 0;

}