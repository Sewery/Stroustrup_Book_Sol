#include "std_lib_facilities.h"
	
void solve(double a, double b, double c){
	double delta = (b*b) - (4*a*c);
	double sq = sqrt(delta);
	double x1= ((b*-1)-sq)/(2*a);
	cout<<"x1 = "<<x1<<"\n";
	double x2 = ((b*-1)+sq)/(2*a);
	cout<<"x2 ="<<x2<<"\n";
}
int main(){
	double a,b,c;	
	cout<<"Rozwiaze ci funkcje kwadratowa. Podaj wspolczynniki"<<"\n";
	cin>>a>>b>>c;
	cout<<"Rozwiazanie: \n";
	solve(a,b,c);
	return 0;
	
}