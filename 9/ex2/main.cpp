#include "date.h"
#include "../../../std_lib_facilities.h"
 int main(){
    
        Chronology::Date1 tommorow{2004,Chronology::Month::mar,54};
        Chronology::Date1 tom{2004,Chronology::Month::feb,15};
        tom.add_day(1000);
        tom.add_year(24);
        Chronology::Date1 xd;
         using namespace Chronology;
                 cout<< tom;
                 cout<<xd;
        
       

     return 0;
 }