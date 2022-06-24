#include "../../std_lib_facilities.h"




int main(){
    try{
    char c =' ';
    int p;
    int sum =0;
    string name = "plik.txt";
    ifstream ist{name};
    if(!ist) error("Nie mozna otworzyc pliku");

    while(ist>>p ){

        sum+=p;

    }
    cout<<"Suma ="<<sum<<'\n';
    }catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
    return 0;
}