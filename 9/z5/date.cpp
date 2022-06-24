#include "date.h"

namespace Chronology{
 const int Year::min = 1800; 
 const int Year::max = 2200;
 Year::Year(int k): yr(k){
     if(k<min || max<=k) throw Invalid();
 }
int Year::year() const{return yr;}
void Year::yearincrease(){
    yr++;
}
const Date1& default_date(){
    static Date1 dd(2001,Month::jan,1);
    return dd;
}
Date1::Date1(Year ye, Month mo, int da): y(ye), m(mo) , d(da){
    if(!(int(m)>0 && int(m)<13 && d>0 && d<32)){
        cerr<<"Niepoprawne dane zostaly wprowadzone\n";
     }
     
}
Date1::Date1():y(default_date().year()),m(default_date().m),d(default_date().day()){}
void Date1::add_day( int n){
   do{
       
     if(n+d<32 && n>0){
         d +=n; 
     }else if(n+d>31){
         int k= 31 -d;
         d=(d+n)-31;
         n= n-(k+ d);
         m=Month(int(m)+1);
     }else{
         cerr<<"Niepoprawne dane zostaly wprowadzone\n";
     }
     if(int(m)>12){
         m=Month(int(m)-12);
         y.yearincrease();
     }
   }while(int(m)>12 || d>31);
 }
void Date1::add_month(int n){
    add_day(n*31);
}
void Date1::add_year(int n){
    add_day(n*365);
}
int Date1::month() const{return int(m);}
int Date1::day()const{return d;}
int Date1::year()const{return y.year();}

 ostream& operator<<(ostream& os , const Date1& d){
     return os << '('<<d.year()<<','<<d.month()<<','<<d.day()<<')'<<"\n";
 }
};