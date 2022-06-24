#include "../../std_lib_facilities.h"
	

int main(){
	cout<<"Podaj jakokolwiek liczbe\n";
	int q;
	cin>>q;
	vector<int> ran;
	srand(q);
	for(int i = 0; i < 4; i++){
		ran.push_back(randint(10));
	}
	vector<int> insert(4);
	int byk, krowa;
	while(byk!=4){
	byk=0; krowa=0;
	for(int i=0; i<insert.size();i++){
		int k;
		cin>>k;
		insert[i]=k;

	}
	
	for(int i=0; i<4; i++){
		if(ran[i]==insert[i]){
			byk++;
		}else{
			for(auto k : ran){
				if(k==insert[i] ){
					krowa++;
				}
			}

		}
	}
	cout<<byk<<" byk i "<<krowa<<" krowa\n";
	}
}