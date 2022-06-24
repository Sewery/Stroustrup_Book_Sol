#include "../../std_lib_facilities.h"
void getData(vector<string>& s, string & name){
    ifstream ifs {name};
    if(!ifs ) error("Nie mozna odczytac plik");
    for(string k; ifs>>k;){
            s.push_back(k);
    }

}
void insertData(vector<string>& s, string & name){
     ofstream ofs {name};
    if(!ofs ) error("Nie mozna odczytac plik");
    for(auto k: s){
            ofs<<k<<' ';
    }
}
void mergingTwoFilesToAnotherfile( string & name, string & name2, string & final){
    vector<string> i1;
    getData(i1,name);
    getData(i1,name2);
    insertData(i1,final);
}

int main(){
    
    try{
        
        
        
         
        
       
         
        
    }catch(exception& e)   {cerr << "exception: " << e.what() << endl;
    }catch (...) {cerr << "exception\n";}
}