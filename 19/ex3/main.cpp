#include <math.h>

#include "../../std_lib_facilities.h"

template<class T ,class U> class Pair{
  public:
    Pair():t(T()), u(U()){}
    Pair(T tk ,U uk){}  
    T t;
    U u;
};
class var_table{
  private:
    vector<Pair<string,double>> table;
  public:
    double get_val(string s);
    void set_value(string s, double d);
    void print_table();

};
//-------------------------------------------------
double var_table::get_val(string s){
    int i=0;
    if(table.size()==0)return -1;
    while(table[i].t!=s)i++;
    return table[i].u;
}  
//-------------------------------------------------
void var_table::set_value(string s, double d){
    int i=0;
    if(table.size()==0)return;
    while(table[i].t!=s)i++;
    table[i].u =d;
} 
//------------------------------------------------- 
void  var_table::print_table(){
    if(table.size()==0){cout<<"Tabela jest pusta\n"; return;}
    cout<<"[ ";
    for(auto p: table)cout<<"|"<<p.t<<" "<<p.u<<"|";
    cout<<" ]\n";
}
int main(){
 
}