#include "std_lib_facilities.h"
	
int chess(int k){
	int v=1;
	int number =0;
	cout<<1<<"\n";
	while(k>v){
		v*=2;
		number++;
		cout<<v<<"\n";
	}
	
	return number;
}
int chess1(int k){
	int w =1;
	for(int i=1; i<=k; i++){
		w*=2;
	}
	return w;
}
double chessd(double k){
	double w =1;
	for(double i=1; i<=k; i++){
		w*=2;
	}
	return w;
}
int main(){	
	cout<<"Wyswietla liczbe szachownic dla 1000 ziarenek"<<"\n";
	int a=chess(1000);
	cout<<"To jest "<<a<<"\n";
	
	cout<<"Wyswietla liczbe szachownic dla 1000000 ziarenek"<<"\n";
	int b =chess(1000000);
	cout<<"To jest "<<b<<"\n";
	cout<<"Wyswietla liczbe szachownic dla 1000000000 ziarenek"<<"\n";
	int c =chess(1000000000);
	cout<<"To jest "<<c<<"\n";
	cout<<"Teraz proba dla int \n";
	int o = chess1(31);
	cout<<"To jest max dla inta "<<o<<"czyli 30\n";
	cout<<"Teraz proba dla double \n";
	double ef= chessd (1023);
	cout<<"To jest max dla double "<<ef<<" czyli 1023\n";
	return 0;

}