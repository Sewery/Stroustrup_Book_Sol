#include "../../std_lib_facilities.h"
bool checkerIsVowel(char k){
    return k=='a' || k=='e' ||k=='i' ||k=='o' ||k=='u' ||k=='y' ;
}
void insertTextToFile(string& name, vector<string>& data){
    ofstream ofs{name};
    if(!ofs)error("Mistake in making file");
    
    for(string& p: data){
        ofs<<p<<'\n';
    }
    
}

void throwUpVowels(string& name){
        vector<string> data;
        ifstream ifs{name};
        if(!ifs)error("Mistake in making file");
        string p;
      
        while(getline(ifs,p)){
            stringstream ss;
            for(char&ch : p){
                if(!checkerIsVowel(ch)){
                    ss<<ch;
                }
            }
            data.push_back(ss.str());
        }
        
        insertTextToFile(name, data);
}





int main(){
    vector<string> data;
    string name1 = "t13.txt";
 
    throwUpVowels(name1);
   
    return 0;
}