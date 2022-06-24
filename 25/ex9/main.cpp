#include "../../std_lib_facilities.h"
#include<bitset>

struct PPN {
    unsigned int PFN : 22;
    int : 3;
    unsigned int CCA :3 ;
    bool nonreacheable :1;
    bool dirty :1 ;
    bool valid :  1;
    bool global : 1;

};


int main()
try
{
   PPN p;
   p.PFN =0;
   p.CCA =0;
   p.nonreacheable =0;
   p.dirty =0;
   p.valid =0;
   p.global =0;
   cout<< p.PFN<<" "<< p.CCA<<" "<< p.nonreacheable<<" "<< p.dirty<<" "<< p.valid<<" "<< p.global<<'\n';

    p.PFN =361;
   p.CCA =3;
   p.nonreacheable =0;
   p.dirty =1;
   p.valid =0;
   p.global =1;
   cout<< p.PFN<<" "<< p.CCA<<" "<< p.nonreacheable<<" "<< p.dirty<<" "<< p.valid<<" "<< p.global<<'\n';

    unsigned int ppn=0;
    ppn=  p.PFN;
    ppn= ppn<<3;
    ppn= (ppn<<3)|p.CCA;
    ppn= (ppn<<1)|p.nonreacheable;
    ppn= (ppn<<1)|p.dirty;
    ppn= (ppn<<1)|p.valid;
    ppn= (ppn<<1)|p.global;

    unsigned int x0 =ppn>>10;
    unsigned int x1 =(ppn>>4)&0x7;
    unsigned int x2 =(ppn>>3)&0x1;
    unsigned int x3 =(ppn>>2)&0x1;
    unsigned int x4 =(ppn>>1)&0x1;
    unsigned int x5 =ppn&0x1;
    cout<<"PFN: "<<x0<<" |CCA: "<<x1<<" |nonreachable: "<<x2<<" |dirty: "<<x3<<" |valid: "<<x4<<" |global: "<<x5<<'\n';
    //
    //ex10
    bitset<32> gh(p.PFN);
    gh =gh.to_ulong()<<3;
    gh= (gh.to_ulong()<<3)|p.CCA;
    gh= (gh.to_ulong()<<1)|p.nonreacheable;
    gh= (gh.to_ulong()<<1)|p.dirty;
    gh= (gh.to_ulong()<<1)|p.valid;
    gh= (gh.to_ulong()<<1)|p.global;

    
    unsigned int y0 =gh.to_ulong()>>10;
    unsigned int y1 =(gh.to_ulong()>>4)&0x7;
    unsigned int y2 =(gh.to_ulong()>>3)&0x1;
    unsigned int y3 =(gh.to_ulong()>>2)&0x1;
    unsigned int y4 =(gh.to_ulong()>>1)&0x1;
    unsigned int y5 =ppn&0x1;
    cout<<"PFN: "<<y0<<" |CCA: "<<y1<<" |nonreachable: "<<y2<<" |dirty: "<<y3<<" |valid: "<<y4<<" |global: "<<y5<<'\n';


}catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
