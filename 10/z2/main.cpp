#include "../../std_lib_facilities.h"

struct Reading{
    double cel;
    double far;

};
ostream& operator<<(ostream& os, Reading& r){
    os<<'('<<r.cel<<'C'<<')'<<'['<<r.far<<'F'<<']'<<'\n';
}
int main(){
    try{
        cout<<"Insert name of new file\n";
        string name;
        cin>>name;
        ofstream of{name};
        if(!of) error("Nie mozna stworzyc takiego pliku");
        for(int i =0; i< 50 ;i ++){
            Reading r{i/2,i+0.5};
            of<<r;
        }

        of.close();
    }catch(exception& e)   {cerr << "exception: " << e.what() << endl;
    }catch (...) {cerr << "exception\n";}
}