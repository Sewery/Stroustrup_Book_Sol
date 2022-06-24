#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../std_lib_facilities.h"

struct Purchase{
    Purchase(): name{""},unit_price{0.0}, count{0}{}
    Purchase(string n, double u , int c): name{n},unit_price{u}, count{c}{}
    string name;
    double unit_price;
    int count;
};

struct Order{
    Order(): name{""},addres{""}, data{""}, vp{vector<Purchase>()}{}
    Order(string n, string u , string  c,  vector<Purchase> v): name{n},addres{u}, data{c}, vp{v}{}
    string name;
    string addres;
    string data;
    vector<Purchase> vp;
};
void get_Orders_form_File(vector<Order> &vo, const string& file)
{
    ifstream ifs{file.c_str()};
    if(!ifs)error("File is corrupted");
    string l;
    getline(ifs,l);//takes first empty line
    ifs>>l;
    if(l!="Order:")error("Error");//checks if starts with string "Order:"
    while(ifs)
    {
        Order order;
        string b,c,d,e;
        ifs>>b>>order.name>>c>>order.addres>>d>>order.data>>e;
        
        if(b!="name:"|| c!="address:" || d!="data:"|| e!="purchases:" )
        {
           cout<<" "<<b<<c<<d<<e; error("1Bad format of data");
        }
        while(ifs)
        {
            Purchase pur;
            string q,w,r;
            ifs>>q;
            if(q=="Order:")break;
            ifs>>pur.name>>w>>pur.unit_price>>w>>pur.count>>r;
            if(ifs.eof())break;
            if(q!="{" || w!=","|| r!="}")error("Error in data vector");
            order.vp.push_back(pur);

        }
        if(ifs.eof())break;
        if(!ifs)error("Something went wrong");
        vo.push_back(order);
    }
}
void add_Order_to_File(Order& ord, const string& file, bool override)
{
    ofstream ofs;
    if(override){ofs.open(file.c_str());}
    else {ofs.open(file.c_str(),fstream::app);}

    if(!ofs)error("File is corrupted");
    ofs<<"\nOrder:\n  name:\n   "<<ord.name<<"\n  address:\n   "<<ord.addres<<"\n  data:\n   "<<ord.data;
    ofs<<"\n  purchases:\n";
    for(const auto k : ord.vp)ofs<<"      { "<<k.name<<" , "<<k.unit_price<<" , "<<k.count<<" } \n";
    
}
void print_purchases(vector<Purchase> pur)
{
     cout<<"\n  purchases:\n";
    for(const auto k : pur)cout<<"      { "<<k.name<<" , "<<k.unit_price<<" , "<<k.count<<" } \n";
}
void print_orders(vector<Order> o)
{
    for(auto& ord : o) {
       cout<<"\nOrder:\n  name:\n   "<<ord.name<<"\n  address:\n   "<<ord.addres<<"\n  data:\n   "<<ord.data;
       print_purchases(ord.vp);
    }
   
}
void test()
{  
    Purchase pur1{"Zakup1",43.12,10};
    Purchase pur2{"Zakup2",12.12,50};
    Purchase pur3{"Zakup3",10.99,100};
    Purchase pur4{"Zakup4",28.62,15};
    Purchase pur5{"Zakup5",13.90,8};
    Purchase pur6{"Zakup6",13.92,3};
    vector<Purchase> v;
    v.push_back(pur1);v.push_back(pur2);v.push_back(pur3);v.push_back(pur4);v.push_back(pur5);v.push_back(pur6);
    Order or1{"Zamownie1","ObroncowPocztyRzeszow","28.01.2020",v };
    Order or2{"Zamownie2","BrydakaRzeszow","29.01.2020",v };
    Order or3{"Zamownie3","OsmeckiegoRzeszow","19.01.2020",v}; 

    add_Order_to_File(or1,"orders.txt",false);
    add_Order_to_File(or2,"orders.txt",false);
    add_Order_to_File(or3,"orders.txt",false);

}
void test2()
{
    vector<Order> vo;
    get_Orders_form_File(vo,"orders.txt");
    print_orders(vo);
}
void task()
{
    vector<Order> vo11;
    get_Orders_form_File(vo11,"order_ex.txt");
    sort(vo11.begin(),vo11.end(),[](const Order& o1, const Order& o2){return o1.name>o2.name;});
    ofstream ofs;
    ofs.open("order_ex.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    for( auto& p: vo11) add_Order_to_File(p,"order_ex.txt",false);

    vector<Order> vo22;
    get_Orders_form_File(vo22,"order_ex2.txt");
    sort(vo22.begin(),vo22.end(),[](const Order& o1, const Order& o2){return o1.addres>o2.addres;});
    ofstream ofs2;
    ofs2.open("order_ex2.txt", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();
    for( auto& p: vo22) add_Order_to_File(p,"order_ex2.txt",false);

    vector<Order> vo3;
    merge(vo11.begin(),vo11.end(),vo22.begin(),vo22.end(),back_inserter(vo3),[](const Order& o1, const Order& o2){return o1.name>o2.name;});
    for( auto& p: vo3)add_Order_to_File(p,"orders_merged.txt",false);

   //ex10
   double sum=0;
    for(const auto& p :vo3)
    {
        for(const auto& r :p.vp)
        {
            sum+=r.unit_price*r.count;
        }
    }
    cout<<sum;
}
//------------------------------------------------------------------------------

int main()
{
    try
    {
        //test();
        //test2();
        task();
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
//------------------------------------------------------------------------------