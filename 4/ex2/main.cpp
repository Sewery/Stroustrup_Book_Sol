
#include "std_lib_facilities.h"




void sortAndPrintVec(vector<double> p){
	sort(p.begin(),p.end());
	cout<<"Lista wartosci w metrach:\n";
	for(auto e: p){
		cout<<e<<"\n";
	}


}

int main(){
	cout<<"Podaj dlugosc i jednostke(m,c,s,l):\n";
	const double m_to_cm =100.0;
	const double cal_to_cm =2.54;
	const double st_to_cal = 12.0;
	char p;
	int count=0;
	double sum=0;
	vector<double> numbers;
	double k;
	double h=0.0,l=0.0;
	bool  valid= true;
	
	while(cin>>k>>p){
		cout<<"-----------------------\n";
		
		double var =k;
		switch(p){
			case 'm':
				cout<<k<<" m== "<< m_to_cm*k<<" cm";
				count++;
				sum+=var;
				break;
			case 'c':
				var= (k*cal_to_cm)/m_to_cm;
				cout<<k<<" cal== " <<cal_to_cm*k<<" cm and "<< k/st_to_cal<<" st";
				count++;
				sum+=var;
				break;
			case 's':
				var= (k*cal_to_cm*st_to_cal)/m_to_cm;
				cout<<k<<" st== " <<st_to_cal*k <<" cal";
				count++;
				sum+=var;
				break;
			case 'l':
				var= k/m_to_cm;
				cout<<k<<" cm== " <<k/cal_to_cm << "cal  and "<< k/m_to_cm<< " m";
				count++;
				sum+=var;
				break;
			default:
				valid= false;
				cout<<"Przykro mi wpisales nie wprawidlowa wartosc "<<p;
				break;
		}
		cout<<"\n";
		numbers.push_back(var);
		if(var>h && valid){
			h=var;	
			cout<<"Ta liczba jak do tej pory byla najwieksza " <<h<<" m \n";
		}if((var<l || l==0) && valid){
			l=var;
			cout<<"Ta liczba jak do tej pory byla najmniejsza " <<l<<" m\n";
		}
		cout<<"Liczba wszystkich wartosci "<<count<<" \n";
		cout<<"Suma wszystkich wartosci "<<sum<<" \n";
		sortAndPrintVec(numbers);
		cout<<"-----------------------\n";
		
	}

	return 59;
}

