#include "../../std_lib_facilities.h"
	
double solve(int N, vector<double> p){
		int sum =0;
		for(int i=0; i<N;i++){
			
			sum+=p[i];
		}
		
		return sum;
	}
int main(){
	vector<double> next;
	vector<double> p;
	int N;
	double e;
	cout<<"Ile pierwszych liczb chcesz zsumowac? \n";
	cin>>N;
	cout<<"Wpisz kilka liczb calkowitych. Zakoncz wpisywaniem | \n";
	while(cin>>e){
		p.push_back(e);
	}
	if(N>p.size()){
		
		cout<<"Suma "<<p.size()<<" pierwszych liczb wynosi:"<<solve(p.size(),p);
	}else{
		cout<<"Suma "<<N<<" pierwszych liczb wynosi:"<<solve(N,p);
	}
	
	for(int i =0; i< N;i++){
		if(i<p.size()-1){
			next.push_back(p[i]-p[i+1]);
		}
	}
	for(auto o : next){
		cout<<o<<"\n";

	}

return 0;
	
}