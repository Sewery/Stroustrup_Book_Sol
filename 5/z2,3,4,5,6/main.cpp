#include "std_lib_facilities.h"
double ctok(double c){
	double k= c +273.15;
	if(k<0){
		error("Podano nieprawidlowa temperture");
		
	}
	return k;
}
double ktoc(double k){
	double c= k -273.15;

	if(c<-273.15){
		error("Podano nieprawidlowa temperture");
		
	}
	return k;
	}
double ctof(double c){
	double f= 9.0/5*c+32;
	if(f< -459.67){
		error("Podano nieprawidlowa temperture");
		
	}
	return f;

}
double ftoc(double f){
	double c= (f-32)*5.0/9.0;
	if(c< -273.15){
		error("Podano nieprawidlowa temperture");
		
	}
	return c;

}
int main(){
	try{
	double c;
	cin>>c;
	double k =ctok(c);
	cout<<k<<endl;

	double e =ktoc(c);
	cout<<e<<endl;

	double b=ctof(c);
	cout<<b<<endl;
		
	double g =ftoc(c);
	cout<<g<<endl;
	}catch(exception& e ){
		cerr<<"Blad"<< e.what()<<"\n";
		keep_window_open();
		return 2;
	}
	return 1;
}