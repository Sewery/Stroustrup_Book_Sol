#include "../../std_lib_facilities.h"

void to_bin(string& name, string& nameB){
    ofstream ofs{name};
    if(!ofs)error("Can't open it");
    ifstream ifs{nameB,ios_base::binary};
    if(!ifs)error("Can't open it");
    for(char i; ifs.read(as_bytes(i),sizeof(char));){
       ofs<<i;
      
   }
    
}

void  to_nor_file(string& name, string& nameB){
   ifstream ifs{name};
   if(!ifs)error("Can't open it");
   ofstream ofs{nameB,ios_base::binary};
   if(!ofs)error("Can't open it");
   for(char k;ifs>>k;){
       ofs.write(as_bytes(k),sizeof(char));
   }
   



}





int main(){

    return 0;
}