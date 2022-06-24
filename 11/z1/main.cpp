#include "../../std_lib_facilities.h"


void getTextFromFile(string& name, vector<string>& data){
        ifstream ifs{name};
        if(!ifs)error("Mistake in making file");
        string p;
        while(getline(ifs,p)){
          
            data.push_back(p);
        }
}

void convertToLowerCase(vector<string>& data){
    for(string& b : data){
        for(char&a : b){
            a=tolower(a);
        }
    }
}
void insertTextToFile(string& name, vector<string>& data){
    ofstream ofs{name};
    if(!ofs)error("Mistake in making file");
    
    for(string& p: data){
        ofs<<p<<'\n';
    }
    
}


int main(){
    vector<string> data;
    string name = "t12.txt";
    string name1 = "t13.txt";
    getTextFromFile(name,data);
    convertToLowerCase(data);
    insertTextToFile(name1,data);
    return 0;
}