#include <math.h>

#include "../../std_lib_facilities.h"

class file_handle{
    fstream fs;
    string file;
    public:
    
    file_handle( const string& ob);
    void write(const string&);
    ~file_handle();

};
file_handle::file_handle( const string& ob)
{
    cout<<"Opening file\n"; 
    file=ob;
    fs.open(ob);
    if(!fs)error("Blad z plikiem\n");
}
file_handle::~file_handle()
{
    cout<<"Closing file\n";
    fs.close();
    if(!fs)error("Blad z plikiem\n");
}
void file_handle::write(const string& k) 
{
    fs<<k;
    if(!fs)error("Nie mozna wpisac do pliku\n");
}
 
void tester(){
    
    file_handle a{"test.txt"};
    a.write("I am new \n");
    a.write("The best ");
  
    


}
int main(){
try { 
    tester();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

    tester();

}