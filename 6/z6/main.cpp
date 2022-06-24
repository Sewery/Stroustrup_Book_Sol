#include "../../std_lib_facilities.h"

bool sentence(vector<string> ha);

string init(){
	
	
	string ha;
	vector<string> xd;
	while(cin>>ha){
		if(ha=="="){
			break;
		}
		if(ha=="stop"){
			return "stop";
		}
		xd.push_back(ha);

	}
	return sentence(xd)?"Dobrze\n":"Zle\n";

}
bool verb(string con)
{
  
	
	return con=="rules"|| con=="fly" || con=="swim";
	
}

//------------------------------------------------------------------------------
bool  noun(string con)
{
	return con=="birds"|| con=="fish" || con=="C++";
	

}
bool  conjuction(string con)
{

	return con=="and" || con=="or" || con=="but";
}

//------------------------------------------------------------------------------
bool article(string con){
	return "the"==con;
}
// deal with + an
bool  sentence(vector<string> ha)
{		
	for(int i =0; i  <ha.size();i++){
		string p= ha[i];
		if(!noun(p) && !conjuction(p) && !article(p) && p!="."){
			return false;
		}
		else {
			if(noun(p)){
				if(!verb(ha[i+1])){
					return false;
				}
				i++;

			}
			if(article(p)){
				if(noun(ha[i+1])){		
					if(!verb(ha[i+2])){
						return false;
					}
					i+=2;	
				}else{
					return false;
				}
			}
		}
	}
	if(ha[ha.size()-1]!="."){
		return false;
	}	
	return true;
		

}


//------------------------------------------------------------------------------

int main(){
	cout<<"Witaj w naszym checkerze dan \nW Wyrazeniach stosuj poprawne zdania zakonczone spacja i kropka\n";
	try{
		while(cin){
			string ost = init();
			if(ost=="stop"){
				break;
			}
			cout<<ost;
		}
		unsigned int ha =5, p=8;
		int ro = ha | p;
		cout<<ro;	
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