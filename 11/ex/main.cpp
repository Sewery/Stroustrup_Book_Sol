#include "../../std_lib_facilities.h"
int main(){
    int year_of_birth= 2005;
    //cout<<showbase<<year_of_birth<<"\t(dziesietny)\n"<<hex<<year_of_birth<<"\t(szestanstkowy)\n"<<oct<<year_of_birth<<"\t(dziestakowy)\n";
    //cout<<dec<<year_of_birth<<'\n';

    int a,b,c,d;
    //cin>>a>>oct>> b>>hex>>c>>d;
    //cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\n';

    double k = 1234567.89;
    cout<<k<<'\n'<<fixed<<k<<'\n'<<scientific<<k<<'\n';

    cout<<setw(10)<<"Seweryn"<<'|'<<setw(12)<<"Tasior"<<'|'<<setw(9)<<664834940<<'|'<<setw(24)<<"sewixes@gmail.com"<<'|'<<'\n';
    cout<<setw(10)<<"Marcin"<<'|'<<setw(12)<<"Kowalski"<<'|'<<setw(9)<<623494051<<'|'<<setw(24)<<"mar.kowalski@gmail.com"<<'|'<<'\n';
    cout<<setw(10)<<"Zuzanna"<<'|'<<setw(12)<<"Cierpinska"<<'|'<<setw(9)<<580123460<<'|'<<setw(24)<<"zuzka123@onet.pl"<<'|'<<'\n';
    cout<<setw(10)<<"Kamil"<<'|'<<setw(12)<<"Szczepanik"<<'|'<<setw(9)<<164834950<<'|'<<setw(24)<<"xdkamil.696@gmail.com"<<'|'<<'\n';
    cout<<setw(10)<<"Aleksandra"<<'|'<<setw(12)<<"Niedzielski"<<'|'<<setw(9)<<623694051<<'|'<<setw(24)<<"olaNiedzielska@gmail.com"<<'|'<<'\n';
    cout<<setw(10)<<"Kacper"<<'|'<<setw(12)<<"Osternik"<<'|'<<setw(9)<<523123460<<'|'<<setw(24)<<":)kacperek:(@onet.pl"<<'|'<<'\n';
}