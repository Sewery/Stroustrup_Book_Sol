#include "../../std_lib_facilities.h"
#include <map>
#include <utility>
#include <numeric>
#include <unordered_map>
template<class In, class T>
    // Requires Input_iterator<In>()
    //&& Equality_comparable<Value_type<T>>()
In findr(In first, In last, const T& val)
{
    for(In p= first; p!= last; ++p)
        if(*p == val)return p;
    return last;    
}    
struct Record
{
    double unit_price;
    int units;

    Record(double d ,int i):unit_price(d), units(i){}
};
double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;
}
//---------------------------------------------------------------

template<class In, class In2, class T, class BinOp, class BinOp2 >
T inner_producte(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
    while(first!=last) {
        init  = op(init, op2(*first, *first2));
        ++first;
        ++first2;
    }
    return init;
}

//------------------------------------------------------------------------------

double weighted_value(
    const pair<string,double>& a,
    const pair<string,double>& b
)    // extract values and multiply
{
    return a.second * b.second;
}


//------------------------------------------------------------------------------
void ex()
{
    //
    //
    vector<int> p{1,5,62,0,5,2334};
    if(findr(p.begin(),p.end(),0)!=p.end())cout<<"I found 0\n";
    if(findr(p.begin(),p.end(),83)!=p.end())cout<<"I found 83\n";
    //
    //
    vector<Record> vr{Record(83.765,90),Record(0.65,90), Record(1.125,6490), Record(3.75,980) };
    double total = accumulate(vr.begin(), vr.end(),0.0, price);
    cout<<"Total: "<<total<<'\n';
    //
    //
    map<string,double> dow_price;
    dow_price["MMM"] = 81.86; 
    dow_price ["AA"] = 34.69;
    dow_price ["MO"] = 54.45;
    dow_price["XD"]= 70.42;
    dow_price["OK"]= 40.52;
    map<string,double> dow_weight;     
    dow_weight.insert(make_pair("MMM", 5.8549));    
    dow_weight.insert(make_pair("AA",2.4808));
    dow_weight.insert(make_pair("MO",3.8940));
    dow_weight.insert(make_pair("XD",6.0234));
    dow_weight.insert(make_pair("OK",3.5634));
    map<string,string> dow_name;              
    dow_name["MMM"] = "3M Co."; 
    dow_name["AA"]  = "Alcoa Inc.";
    dow_name["MO"]  = "Altria Group Inc.";
    dow_name["XD"] = "Xerox Devices Company.";
    dow_name["OK"] = "Oriental Knowledge Distribution.";


    double alcoa_price  = dow_price ["AA"];  
    double altria_price = dow_price ["MO"];

    if (dow_price.find("INTC") != dow_price.end()) 
        cout << "Intel is in the Dow\n";

    typedef map<string,double>::const_iterator Dow_iterator;

    for (Dow_iterator p = dow_price.begin(); p!=dow_price.end(); ++p) {
        const string& symbol = p->first;      // the "ticker" symbol
        cout << symbol << '\t'
             << p->second << '\t'
             << dow_name[symbol] << '\n';
    }
    double dji_index =
        inner_producte(dow_price.begin(),     
                      dow_price.end(),
                      dow_weight.begin(),     
                      0.0,                    
                      plus<double>(),         
                      weighted_value);             
    cout << "DJI=" << dji_index << endl;
    //
    //
    unordered_map<string,int> um;
    um["ROCK'N' ROLL IS KING"]=5;
    um["Born to be wild"]=6;
    um["We will rock you"]=4;
    um["Bohemian Rapshody"]=1;
    um["I'm still standing"]=3;
    um["I want to break free"]=2;
    for(const auto& a : um)cout<<a.first<<'\t'<<a.second<<'\n';
    //
    //
          
}
void ex_p2()
{
    string from, to;
    cin >> from >> to;  

    ifstream is(from.c_str());            
    ofstream os(to.c_str());              

    istream_iterator<string> ii(is);      
    istream_iterator<string> eos;         
    ostream_iterator<string> oo(os,"\n");

    /* first version 
        ---
        vector<string> b(ii,eos);
        sort(b.begin() ,b.end());
        copy(b.begin(),b.end(),oo);
        ---
    */ 
    //second version 
    int max_size =100;
    vector<string> b(max_size);
    sort(b.begin() ,b.end());          
    copy(ii,eos ,b.begin());
    
}
int main()
{

    try
    {
       ex_p2();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "exception\n";
    }
}
