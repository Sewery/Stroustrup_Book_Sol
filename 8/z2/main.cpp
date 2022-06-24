#include "../../std_lib_facilities.h"


void printVector(const vector<int>& v, const string& name){
    cout<<name<<"{";
    for(const int&  l: v){
        cout<<l<<", ";
    }
     cout<<"}\n";
}
void FiboVecto(int x, int y,vector<int>& v, int n){ 
        int w=x;
        v.push_back(x);
        v.push_back(y);
        int h =y;
        for(int i=2; i<n; i++){
            int h =w;
            if(i==2){
                h++;
            }
            w+=y;
            v.push_back(w);
            y=h;
        }
}
vector<int> reversedVector(vector<int> ha){
        vector<int> k;
        for(int i = ha.size()-1;i>-1;i--){
            k.push_back(ha[i]);
        }
    return k;
}
void swapvector(vector<int>& ha){
        int l =0;
        vector<int> be = ha;
        for(int i = ha.size()-1;i>-1;i--){
            ha[i]=be[l];
            l++;
        }
}
vector<string> reversedVector(vector<string> ha){
        vector<string> k;
        for(int i = ha.size()-1;i>-1;i--){
            k.push_back(ha[i]);
        }
    return k;
}
void swapvector(vector<string>& ha){
        int l =0;
        vector<string> be = ha;
        for(int i = ha.size()-1;i>-1;i--){
            ha[i]=be[l];
            l++;
        }
}
vector<int> getLengthoOfElement(vector<string> ha){
        vector<int> k;
        for(int i = 0;i<ha.size();i++){
            k.push_back(ha[i].length());
        }
    return k;
}
double getSumOfMultiply(vector<double> price, vector<double> weight){
    if(price.size()!=weight.size()){
        error("Not equal sizes od vectors");

    }
    double sum =0;
    for(int i=0; i<price.size();i++){
        sum+=price[i]*weight[i];
    }
    return sum;
}

int main (){
    vector<string> names;
    vector<int> ages;
    cout<<"Podaj piec imion:\n";
    for(int i =0; i<5;i++){
        string n;
        cin>>n;
        names.push_back(n);
    }
    cout<<"Podaj piec wiekow:\n";
    for(int i =0; i<5;i++){
        int n;
        cin>>n;
        
        ages.push_back(n);
    }
    for(int i=0; i<5; i++){
        cout<<names[i]<<" "<<ages[i]<<"\n";
    }
    vector<string> names1 = names;
    sort(names.begin(),names.end());
    for(int i =0; i<names.size(); i++){

        for(int j = 0; j <names1.size();j++){
            if(names[i]==names1[j]){
                cout<<names[i]<<" "<<ages[j]<<"\n";
            }
        }
    }
 


}