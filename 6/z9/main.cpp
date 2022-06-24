#include "../../std_lib_facilities.h"

bool sentence(vector<string> ha);

vector<char> init(){
	
	
	char ha;
	vector<char> xd;
	while(cin>>ha){
		if(ha=='x'){
		vector<char> x ={'x'};
		return x;
		}
		if(ha=='='){
			break;
		}
		if(ha-'0'>9){
			error("Mozesz tylko wprowadzac liczby i niektore znaki");
		}
		xd.push_back(ha);

	}
	return xd;

}
// deal with + an
string sentence(vector<char> ha)
{		
	string wp= "";
	int p=ha.size()-1;
	for(int i =ha.size()-1; i>=0;i--){
		
		if(i==p){
		string s ="; Liczba jednostek: ";
		s+= ha[i];
		wp=s+ wp;

		}
		if(i==(p-1)){
			string s = "; Liczba dziesiatek: ";
			s+=ha[i];
			wp = s+ wp;
			
		}
		if(i==(p-2)){
			string s = "; Liczba setek: ";
			s+=ha[i];
			wp = s+ wp;
		}if(i==(p-3)){
			string s = "; Liczba tysiecy: ";
			s+=ha[i];
			wp = s+ wp;
		}
		
	}
	wp.erase(0, 1);
	return wp;
}


//------------------------------------------------------------------------------

int main(){
	cout<<"Witaj w naszym checkerze dan \nW Wyrazeniach stosuj poprawne zdania zakonczone spacja i kropka\n";
	try{	
		while(cin){
			vector<char> o = init();
			if(o[0]=='x'){break;}
			string ost = sentence(o);
			cout<<"Dekompozycja liczby:" <<ost<<".\n";
		}
    		keep_window_open();
	}catch (exception& e) {
    		cerr << "error: " << e.what() << '\n';
    		keep_window_open();
    		return 1;
	}
	catch (...) {
    		cerr << "Oops: unknown exception!\n";
    		keep_window_open();
    		return 2;
	}
	return 0;
}