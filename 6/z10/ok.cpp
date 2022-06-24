#include "../../std_lib_facilities.h"

int facto(int k){
	return k>1?k*facto(k-1):1;

}
int permutation(int a, int b){
	return facto(a)/facto(a-b);

}

int combination(int a, int b){
	return permutation(a,b)/facto(b);

}
int main(){
cout<<"Witaj w naszym programie ktory oblicza permutacje i kombinacje\nW Wyrazeniach stosuj liczby calkowite\n";
cout<<"Jesli chcesz zrobic permmutacje wpisz p a jesli kombinacje wpisz k\n";
cout<<"Jesli chcesz zakonczyc program wpisz x\n";
try
{	
	while(cin){
	cout<<"Podaj p lub k\n";
	char k;
	cin>>k;
	cout<<"Podaj dwie cyfry do obliczen: czyli ile mozliwosci i kombinacji\n";
	int a,b;
	cin>>a>>b;
	if(k=='p'){
		cout<<"\nWynik to: "<<permutation( a, b)<<"\n";

	}
	if(k=='c'){
		cout<<"\nWynik to: "<<combination( a, b)<<"\n";
	}
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
}