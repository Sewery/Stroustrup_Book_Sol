#include "../../std_lib_facilities.h"

class Name_pairs{
private:
    vector<string> name;
    vector<int> age;
public: 

    Name_pairs(vector<string>, vector<int>);
    Name_pairs();
    //istream& operator>>(istream& is);

    vector<string> names ()const;
    vector<int> ages ()const;
    void read_names();
    void read_ages();
    void sorta();
 
   

};
