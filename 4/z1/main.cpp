#include "std_lib_facilities.h"

int squareWithoutMultiplying(int p){
		int k=0;
		for(int i=0; i<p;i++){
			k+=p;

		}
	return k;
	}



int main(){
	const double jens=102.1;
	const double zl=3.78;
	const double euro=0.92;
	double value;
	char currency;
	cout<<"Podaj liczbe i walute na jaka chcesz zaminic dolary(j,z,e):\n";
	cin>>value>>currency;
	switch(currency){
		case 'j':
			cout<<value<<" dolarow to "<<value*jens<<" jenow";
			break;
		case 'z':
			cout<<value<<" dolarow to "<<value*jens<<"  zl";
			break;
		case 'e':
			cout<<value<<" dolarow to "<<value*euro<<" euro";
			break;
		default:
			cout<<"Podales zly znak. Sprubuj ponownie";
			break;

	

	}
	cout<<"\nSquare"<<squareWithoutMultiplying(value);
	return 0;
}