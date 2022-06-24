#include "../../std_lib_facilities.h"
#include <map>
#include <numeric>
struct Item{
    string name;
    int id;
    double value;
    Item(string n, int i, double v):name(n),id(i), value(v){}

};
ostream& operator<<(ostream& os,const Item& it)
{
    os<<"Item:"<<it.name<<", "<<it.id<<", "<<it.value<<"|";
}
template<typename C>
void print(const C &p) {  
    auto first = p.begin();
    while (first!=p.end()) {
        cout << *first << '\n';
        ++first;
    }
}
class Find_s{
    string s;
 public:

    Find_s(string k):s{k}{}   
    bool operator()(Item& it)const {return it.name==s;}
};
class Find_i{
    int s;
 public:
    Find_i(int k):s{k}{}   
    bool operator()(Item& it)const {return it.id==s;}
};
void drill1_vector(){
    vector<Item> p;
    p.push_back(Item("Hjhew",31,94.193));
    p.push_back(Item("H434ew",34121,94.3));
    p.push_back(Item("H4343jhew",13,94.93));
    p.push_back(Item("$234Hjhew",1,4.1943));
  
    sort(p.begin(),p.end(),[](Item& a,Item& b){return a.name < b.name;});
    sort(p.begin(),p.end(),[](Item& a,Item& b){return a.id < b.id;});
    sort(p.begin(),p.end(),[](Item& a,Item& b){return a.value >b.value;});
    print(p);

    p.push_back(Item("horse shoe ",99,12.34));
    p.push_back(Item("Canon S400 ",998,499.95));
    print(p);
    auto r=find_if(p.begin(),p.end(),Find_s("H434ew"));
    if(r!=p.end()){
        
        p.erase(r);
    }
    auto r1=find_if(p.begin(),p.end(),[](Item& k){return k.name=="H4343jhew";});
    if(r1!=p.end()){
        
        p.erase(r1);
    }
    /////////////////////////////////////////////////////
    auto r2=find_if(p.begin(),p.end(),Find_i(99));
    if(r2!=p.end()){
        
        p.erase(r2);
    }
     auto r3=find_if(p.begin(),p.end(),Find_i(1));
    if(r3!=p.end()){
        
        p.erase(r3);
    }
   print(p);
   
   
}
void drill1_list(){
    list<Item> p;
    p.push_back(Item("Hjhew",31,94.193));
    p.push_back(Item("H434ew",34121,94.3));
    p.push_back(Item("H4343jhew",13,94.93));
    p.push_back(Item("$234Hjhew",1,4.1943));
    print(p);
    //list hasn't got a opertaor- so doesn't work on common function sort
    p.sort([](Item& a,Item& b){return a.name < b.name;});
    p.sort([](Item& a,Item& b){return a.id < b.id;});
    p.sort([](Item& a,Item& b){return a.value >b.value;});
    print(p);

    p.push_back(Item("horse shoe ",99,12.34));
    p.push_back(Item("Canon S400 ",998,499.95));
    print(p);
    auto r=find_if(p.begin(),p.end(),Find_s("H434ew"));
    if(r!=p.end()){
        
        p.erase(r);
    }
    auto r1=find_if(p.begin(),p.end(),[](Item& k){return k.name=="H4343jhew";});
    if(r1!=p.end()){
        
        p.erase(r1);
    }
    /////////////////////////////////////////////////////
    auto r2=find_if(p.begin(),p.end(),Find_i(99));
    if(r2!=p.end()){
        
        p.erase(r2);
    }
     auto r3=find_if(p.begin(),p.end(),Find_i(1));
    if(r3!=p.end()){
        
        p.erase(r3);
    }
    print(p);
}
template<class K, class V>
ostream& operator<<(ostream& os, pair<K,V> mp)
{
    cout<<mp.first<<" "<<mp.second<<" ";
}
void read_map( map<string,int> & msi)
{
    string s;
    int i;
    cin>>s>>i;
    if(cin.fail())error("Something went wrong...");
    msi[s]=i;
}
void drill2()
{
    map<string,int> msi;
    msi["Pan"]=123;
    msi["Jacek"]=23;
    msi["Krowa"]=67;
    msi["piskle"]=63;
    msi["Pilka"]=165623;
    msi["Warszawa"]=1283;
    msi["wynosic"]=13;
    msi["Jaskolka"]=24543;
    msi["jesc"]=123;
    print(msi);

    auto it = msi.find("Pan");
    msi.erase(it);
    it = msi.find("Krowa");
    msi.erase(it);
    cout<<"\n";
    print(msi);

    int i=1;
    while(i!=10)read_map(msi);
    print(msi);
    int sum =accumulate(msi.begin(),msi.end(),0,[](int k ,pair<string,int> p){return k+ p.second;});
    cout<<sum;

    map<int,string> mis;
    auto itp = msi.begin();
    while(itp!=msi.end())
    {
        mis[itp->second]=itp->first;
        itp++;
    }
    cout<<'\n';
    print(mis);

}

template<class T>
class Less_than {
    T v;
public:
    Less_than(T val) :v(val) { }
    bool operator()(T x) const { return x < v; }
};
void drill3()
{
    ifstream ifs{"file.txt"};
    if(ifs.fail())error("File is corrupted\n");
    double d;
    vector<double> vd;
    while(ifs>>d)vd.push_back(d);
    ifs.close();
    print(vd);
    vector<int> vi(18);
    copy(vd.begin(),vd.end(),vi.begin());
    int cr =0;
    cout<<'\n';
    while(cr!=18)
    {
        cout<<vd[cr]<<'\t'<<vi[cr]<<'\n';
        cr++;
    }
    cout<<"Sum of vd: "<<accumulate(vd.begin(),vd.end(),0.0)<<"\n";

    cout<<"Diferrence of sums of vd and vi : "<<accumulate(vd.begin(),vd.end(),0.0)-accumulate(vi.begin(),vi.end(),0)<<"\n";

    reverse(vd.begin(),vd.end());
    print(vd);

    double avg =accumulate(vd.begin(),vd.end(),0.0)/vd.size();
    cout<<"Average value: "<<avg<<'\n';

    vector<double> vd2(vd.size());
    copy_if(vd.begin(),vd.end(),vd2.begin(),[&](double k ){return k>avg;});
    print(vd2);

    cout<<'\n';
    sort(vd.begin(),vd.end());
    print(vd);
}

int main()
{

    try
    {
       drill3();
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
