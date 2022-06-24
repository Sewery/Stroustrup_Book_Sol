#include "../../std_lib_facilities.h"
struct Reading{
    double cel;
    double fah;

};
istream& operator>>(istream& is, Reading& r){
    char a  ,b, c, d ;
    char C, F;
    double ce;
    double f;
    is>>a>>c>>C>>b>>c>>f>>F>>d;
   
    if( a!='(' || b!=')' || c!='[' || d!=']' || C!='C' || F!='F') error("Nie prawidlowy odczyt");
    r.cel = ce;
    r.fah= ce*9/5 + 32;
    return is;

}
ostream& operator<<(ostream& os, Reading& r){
    os<<'('<<r.cel<<')'<<'['<<r.fah<<']'<<'\n';
}
int main(){
    vector<Reading> numbers;
    try{
        cout<<"Insert name of new file\n";
        string name;
        cin>>name;
        ifstream ist{name};
        if(!ist) error("Nie mozna stworzyc takiego pliku");
        Reading r;
        while(ist>>r){
            numbers.push_back(r);
        }  
        ist.close(); 
        for(auto k : numbers){
            cout<<k;
        }
    }catch(exception& e)   {cerr << "exception: " << e.what() << endl;
    }catch (...) {cerr << "exception\n";}
}