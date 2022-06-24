#include "../../std_lib_facilities.h"


void getLinesWithKeywords(string& keyword, string& name, vector<string>& data){
        ifstream ifs{name};
        if(!ifs)error("Mistake in making file");
        string p;
        int counter= 1;
        while(getline(ifs,p)){
           
            stringstream ss;
            ss<<counter<<" "<<p;
            bool check=false;
            for(string s; ss>>s;){
                if(s==keyword){
                    check=true;
                }
            }
            if(check){
                     data.push_back(ss.str());
            }
            counter++;
        }
}




int main(){
    vector<string> data;
    string name1 = "t13.txt";
    string key ="KLUCZ";
    getLinesWithKeywords(key,name1,data);
    for(auto k: data){
        cout<<k<<'\n';
    }
   
    return 0;
}