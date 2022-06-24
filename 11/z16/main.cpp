#include "../../std_lib_facilities.h"
void getNumbersFromFile(vector<int>& vec, string& name){
    ifstream ifs{name};
    if(!ifs)error("Sth is wrong");
    for(int i; ifs>>i;){
        if(ifs.fail()){
            ifs.clear();
            cerr<<"W pliku sa nie cyfry \n";
           
        }
        vec.push_back(i);
    }
    sort(vec.begin(),vec.end());
    ifs.close();
}
void insertIntoFile(vector<int>& vec, string& name){
    ofstream ofs{name};
    if(!ofs)error("Sth is wrong");
    int counter=0;
    for(int i =0; i< vec.size();i++){
        int k =i;
        while(k!=vec.size() && vec[k]==vec[i] ){
            counter++;
            k++;
        }
        i=k-1;
        if(counter!=1){

             ofs<<vec[i]<<'\t'<<counter<<'\n';
        }
        else{
            ofs<<vec[i]<<'\n';
        } 
        counter=0;   
        
    }
}
void process(){
    vector<int> k;
    string name = "plik.txt";
    getNumbersFromFile(k,name);
    insertIntoFile(k,name);
}

int main(){
    process();
    return 0;
}