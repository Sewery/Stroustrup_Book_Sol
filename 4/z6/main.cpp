#include "std_lib_facilities.h"
	
int main(){	
	vector<string> p = {"poniedzialek","wtorek","sroda","czwartek","piatek","sobota","niedzila"};
	cout<<"Wpisz cyfre od 1 -7 mowiaca ktory dzien tygodnia chcesz wyswietlic\n";

	int e;
	while(cin>>e){
		cout<<p[e-1]<<"\n";
		cout<<"jesli chcesz przerwac wpisz / \n";
	}
	
	cout<<"Wpisz dzien tygodnia a ja wyswietla liczbe\n";
	string d;
	cin.clear();
	while(cin>>d){
		for(int i =0; i< p.size(); i++){
			if(p[i]==d){
				cout<<i<<"\n";
			}else{
				cout<"Zle dane wpisales\n";
			}
		}
	}
	
	
	return 0;

}