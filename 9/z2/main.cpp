#include "Name_pairs.h"
 ostream& operator<<(ostream& os,const Name_pairs&  k){
        cout<<"Drukuje wyniki \n";
        for(int i = 0; i<k.names().size();i++){
            cout<<k.names()[i]<<" "<<k.ages()[i]<<'\n';
        }
    }
    bool operator==(const Name_pairs& a,const Name_pairs& b ){
        return a.ages() == b.ages() && a.names() == b.names();
    }
     bool operator!=(const Name_pairs& a,const Name_pairs& b ){
         return !(a==b);
    }
 int main(){

     try{
        Name_pairs k;
        cout<<k;
        k.read_names();
        k.read_ages();
        k.sorta();
       cout<<k;
        Name_pairs e;
        if(k==e){
           cout<<"true";
        }
        if(k!=e){
           cout<<"false";
        }
     }catch(exception& ar ){
        cerr<<"Wystapil nieoczekiwany blad:"<<ar.what();
        return -1;
     }catch(...){
        cerr<<"Wystapil nieoczekiwany blad";
        return -2;
     }
       

     return 0;
 }