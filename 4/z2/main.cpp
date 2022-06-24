#include "std_lib_facilities.h"

int main(){
	vector<double> temps;
	double temp;
	while (cin>>temp){
		temps.push_back(temp);

	}
	double sum =0;
	for(int i=0; i< temps.size();i++){
		sum+=temps[i];
	}
	cout<<" Srednia tempartura wynosi: " << sum/temps.size()<<"\n";
	sort(temps.begin(),temps.end());
	if(temps.size()%2==0){
		double k=(temps[temps.size()/2-1] + temps[temps.size()/2])/2;
		cout<<"Mediana: "<< k<<"\n";
	}else{
	cout<<"Mediana: "<< temps[temps.size()/2]<<"\n";
	}


	

}