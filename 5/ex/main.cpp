#include "../../std_lib_facilities.h"

int main(){
	try{
		
		
		bool cond= false;
		if(cond){

			cout<<"Braw!\n";
		}else cout<<"Zle!\n";
		
		keep_window_open();
		return 0;
	}catch(exception& e ){

		cerr<<"Blad : "<< e.what()<<"\n";
		keep_window_open();
		return 1;
	}catch(... ){

		cerr<<"Nieznany rodzaj wyjatku \n";
		keep_window_open();
		return 2;
	}



	
	
}