#include "Name_pairs.h"

    const Name_pairs& default_pairs(){
        vector<string> s{ "Brak"};
        vector<int> i{0};
        static Name_pairs k(s,i);
        return k;
    }
    vector<string> Name_pairs::names() const {return name;}

    vector<int> Name_pairs::ages() const{return age;}

    Name_pairs::Name_pairs():name(default_pairs().name),age(default_pairs().age){};

    Name_pairs::Name_pairs(vector<string> s, vector<int> i):name(s),age(i){};
    //istream& operator>>(istream& is);
   
    void  Name_pairs::read_names(){
         cout<<"Teraz podaj imiona\n";
        vector<string> names; 
        string n{};
        cin>>n;
        while(n!="q"){
            
            names.push_back(n);
            cin>>n;
        }
        name=names;
    }
    void  Name_pairs::read_ages(){
        cout<<"Teraz podaj lata\n";
        vector<int> ages;  
        int n{};
        cin>>n;
        while(n!=9999){
            
            ages.push_back(n);
            cin>>n;
        }
        if(ages.size()!=name.size()){
            cerr<<"Prowadziles bledna ilosc argumentow\n";
            cout<<"Wywoluje funkcje jeszcze raz\n";
            read_ages();
            return;
        }
        age=ages;
        
    }
    void  Name_pairs::sorta(){
        cout<<"Sortuje... \n";
        vector<string> names1 =name;
        vector<int> a;
        sort(name.begin(),name.end());
        for(int i =0; i<name.size(); i++){
            for(int j = 0; j <names1.size();j++){
                if(name[i]==names1[j]){
                    a.push_back(age[j]);
                }
            
            }
        }
        age=a;
    }
