#include "../../std_lib_facilities.h"
	
int fib(int k){
		
		return k<=2?1:fib(k-1)+fib(k-2);
	}
int main(){
	cout<<fib(9);
}