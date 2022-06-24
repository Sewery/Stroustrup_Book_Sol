#include "std_lib_facilities.h"
	
vector<int> oddfinderErato(int range){
	vector<int> r;
	int limit = sqrt(range) +1;

	for(int i= 2; i<=limit;i++){
		for(int q =0; q<range;q++){
			if(q!=i && q!=0 && q%i==0){ 
				
		
			}else{
				r.push_back(q);
			}

		}
	}	

	return r;
}
vector<int> oddfinder(int range){
	vector<int> odds = {2};
	int hp;
	for(int i=3; i<=range;i++){		
		hp=0;
		for(int e = 2; e<=i;e++){
			if(i%e==0 && e!=i){
				hp++;
			}
		}
		if(hp==0){
			odds.push_back(i);
		}
	}
	return odds;
}

int main(){	
	cout<<"Wyswietla wszystkie liczby pierwsze"<<"\n";
	vector<int> odds = oddfinderErato(100);
	
	for(auto k: odds){
		
			cout<<k<<"\n";
		
		}
	return 0;
	
}