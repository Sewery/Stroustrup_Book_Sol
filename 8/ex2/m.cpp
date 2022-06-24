#include "../../std_lib_facilities.h"

void swap_v(int a, int b){
    int temp;
    temp =a;
    a=b;
    b=temp;
      cout<<"Temp="<<temp<<" ,a="<<a<<" , b="<<b<<'\n';
}
void swap_r(int& a, int& b){
    int temp;
    temp =a;
    a=b;
    b=temp;
      cout<<"Temp="<<temp<<" ,a="<<a<<" , b="<<b<<'\n';
}
/*void swap_cr(const int& a, const int& b)
{
    int temp;
    temp =a;
    a=b;
    b=temp;

    cout<<"Temp="<<temp<<" ,a="<<a<<" , b="<<b<<'\n';
}
*/

int main(){
    int x =7;
    int y=9;
    swap_r(x,y);
    swap_r(7,9);
    const int cx =7;
    const int cy =9;
    swap_r(cx,cy);
    swap_r(7.7,9.9);

    double dx =7.7;
    double dy = 9.9;
    swap_r(dx,dy);
    swap_r(dx,dy);

 return 2;
}