#include "../../std_lib_facilities.h"
int main(){
    try{
    char p;
    int sum =0;
    string name = "plik.txt";
    ifstream ist{name};
    if(!ist) error("Nie mozna otworzyc pliku");

    while(ist>>p){
      
        if(ist.fail()){
            
            cerr<<"Wystapil blad \n";
            ist.clear();
            break;
        }
         if(isdigit(p)){
            ist.unget();
            int h;
            ist>>h;
            sum+=h;
        }

    }
    cout<<"Suma = "<<sum<<'\n';
    }catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
    return 0;
}