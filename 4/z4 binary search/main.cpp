#include "std_lib_facilities.h"
	
int main(){
	cout<<"Wymysl jakakolwiek liczbe z przedzialu od 1 do 100 a ja ja znajde w mniej niz siedem posuniec\n";
	cout<<"Mozesz odpowiadac na pytania tak , nie lub rowne\n";
	
	int max =100;
	int k =50;
	int low= 0;
	int count=0;
	string p;
	cout<<"Czy liczba jest mniejsza niz  albo rowna "<< k<<" ?\n";
	cin>>p;
	while(p!="rowne"  ){
		if(p=="tak"){
			 max = k-1;
			k =(max +low)/2;
			count++;
			
			cout<<"Czy liczba jest mniejsza niz "<< k<<" ?\n";
		}else if(p=="nie"){
			count++;
			low= k+1;
			 k =(max +low)/2;
			cout<<"Czy liczba jest mniejsza niz "<< k<<" ?\n";
		}
		cin>>p;	
		

	}
	cout<<"Zgadlem! Twoja liczba to "<<k<<".Zgadlem ja w "<<count<<" ruchach\n"; 
	return 0;
}