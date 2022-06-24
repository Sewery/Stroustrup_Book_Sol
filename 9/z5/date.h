#include "../../std_lib_facilities.h"
namespace Chronology{
enum class Month{
    jan=1 , feb , mar , apr, jun, jul , aug , sep , oct , nov , dec
};
class Year{
    static const int min ;
    static const int max ;
    public:
        Year(int);
        class Invalid{};
        int year() const;
        void yearincrease();
    private:
        int yr;    

};
class Date1{
    private:
    Year y ;
    Month m ;
    int d ;
    public:
    Date1();
    Date1(Year, Month, int);
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    int month() const;
    int day() const;
    int year() const;
};
ostream& operator<<(ostream& os , const Date1& d);
};