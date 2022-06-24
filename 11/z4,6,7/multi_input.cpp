#include "../../std_lib_facilities.h"
bool isPunctationMark(char k){
    return k=='.' ||  k==';' || k==',' || k=='?' ||  k=='-' || k=='\'';
}

void chnageText(string& text){
    for(char& a :text){
        if(isPunctationMark(a)){
            a=' ';
        }
    }
}
void toNotShortuct(string& text){
    int size=text.length();
    for(int i=0; i<size;i++){
        if(text[i]=='n' && i< text.length()-2){
            if(text[i+1]=='\''&& text[i+2]=='t'){
                text[i+1]='o';
                text.insert(i," ");
                size++;
                i++;
            }
        }
    }
}

int main(){
    int a,b,c;
    cout<<"Wpisz liczbe w formacie dzeiesetnym ,osemkowym i szesnastkowym \n";
    cin>>c>>oct>>b>>hex>>a;
    cout<<showbase<<dec;
    cout<<"szestnastkowa"<<'\t'<<hex<<a<<'\t'<<"zamienia sie w "<<dec<<a<<'\t'<<"w formacie dziesietnym \n"
    <<"osemkowa"<<'\t'<<oct<<b<<'\t'<<"zamienia sie w "<<dec<<b<<'\t'<<"w formacie dziesietnym \n"
    <<"dziesietna"<<'\t'<<dec<<c<<'\t'<<"zamienia sie w "<<dec<<c<<'\t'<<"w formacie dziesietnym \n";
    string k ="Jebac was'cujki;xd.O";
    chnageText(k);
    cout<<k<<'\n';
    string e = " i don't like you i don't";
    toNotShortuct(e);
    cout<<e<<'\n';
    return 0;
}