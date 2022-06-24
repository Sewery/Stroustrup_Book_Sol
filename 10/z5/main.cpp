#include "../../std_lib_facilities.h"
class Roman_int{
    private:
        int sum ;
    public:
        string romannumber;
        void set_int(int );
        int as_int();


};
void Roman_int::set_int( int p){
    sum = p;
}
int Roman_int::as_int(){
    return sum;
}
bool isvalidC(char k){
    return k=='X' || k=='I'|| k=='V' || k=='L' || k=='C';
}
int converter(char k){
    switch(k){
        case 'X':
            return 10;
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'L':
            return 50;
        case 'C':
            return 100;
        default:
            return -1;
                   
    }
}
istream& operator>>(istream& is, Roman_int& r){
    char a;
    int sum =0;
    string rome = "";
    while(is>>a && isvalidC(a)){
         if(!isvalidC(a)){
            cerr<<"Zla cyfra rzynska\n";
            return is;
        }
         if( !is) error("Nie prawidlowy odczyt");
            rome+=a;
            char o= cin.get();
            int first = converter(a);
            int second = converter(o);
            if(isvalidC(o) && converter(o)>converter(a)){
                sum= sum + second -first;
                rome+=o;
            }else{
                cin.unget();
                sum+=first;
            }
   }
   cin.unget();
    r.set_int(sum);
    r.romannumber =rome;
    return is;

}
ostream& operator<<(ostream& os, Roman_int& r){
    os<<"Po rzymsku: " <<r.romannumber<<" Po arabsku:" <<r.as_int()<<'\n';
}
int operator+( Roman_int& r1 , Roman_int& r2){
        return r1.as_int()+ r2.as_int();
}
int operator-( Roman_int& r1 , Roman_int& r2){
    return r1.as_int()- r2.as_int();
}
int operator*( Roman_int& r1 , Roman_int& r2){
    return r1.as_int()* r2.as_int();
}
int operator/( Roman_int& r1 , Roman_int& r2){
    return r1.as_int()/ r2.as_int();
}
void proOperators(Roman_int&  a){
        Roman_int b;
        char c;
        cin>>c;
        switch(c){
            case '+': {
                cin>>b;
                char k;
                cin>>k;
                if(k!='=')error("Daj znak rownowsci");
                cout<<a+b;
                break;
            }
            case '-': {
                cin>>b;
                char k;
                cin>>k;
                if(k!='=')error("Daj znak rownowsci");
                cout<<a-b;
                break;
            }
            case '*': {
                cin>>b;
                char k;
                cin>>k;
                if(k!='=')error("Daj znak rownowsci");
                cout<<a*b;
                break;
            }case '/': {
                cin>>b;
                char k;
                cin>>k;
                if(k!='=')error("Daj znak rownowsci");
                cout<<a/b;
                break;
            }
            default :{
                cerr<<"Bad input\n";
                break;
            }

        }
}
void procces(){
    Roman_int i;

    while(cin>>i){
        if(cin.fail()) error("Nie prawidlowy odczyt\n");
        char k;
        cin>>k;
        if(k=='+' ||k=='-' ||k=='*' ||k=='/'){
           cin.unget();
           proOperators(i);

        }
        else if(k=='k'){
            cout<<"Koniec programu\n";
            break;
        }else {
           cerr<<"Niepoprawne dane \n";
        }
         cout<<'\n';
       
    }
    
}
int main(){
    
    try{
        
            cout<<"Wpisz\n";
            procces();
            /*
            Roman_int i;
            Roman_int a;
            cin>>i;
            cin>>a;
            cout<<"Wynik dodawania "<<i+a<<'\n';
            cout<<"Wynik odejmowania "<<i-a<<'\n';
            cout<<"Wynik mnozenia "<<i*a<<'\n';
            cout<<"Wynik dzielenia "<<i/a<<'\n'; 
            cout<<i;
            cout<<a;
                */
        
       
         
        
    }catch(exception& e)   {cerr << "exception: " << e.what() << endl;
    }catch (...) {cerr << "exception\n";}
}