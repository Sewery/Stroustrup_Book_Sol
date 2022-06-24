#include "../../std_lib_facilities.h"
int area(int l, int w){
	return l<=0 || w<=0?-1:l*w;
}

int framed_area(int x, int y){
	constexpr int f_w=2;
	if(x-f_w <= 0 || y- f_w <= 0){
		error("Argument dunkcji area nie jest doodatni");
	}
	return area(x-f_w,y-f_w);
}

int f(int x , int y, int z){
	int area1= area(x,y);
	cout<<"Area1="<<area1<<"\n";
	if(area<=0) {error("Pole pow nie jest dod");}
	int area2 = framed_area(1,z);
	cout<<"Area2="<<area2<<"\n";
	int area3 = framed_area(y,z);
	cout<<"Area3="<<area3<<"\n";
	double ratio = double(area1/area3);
	cout<<"Ratio="<<ratio<<"\n";
	return 0;
}
int main(){
	cout<<framed_area(-2,-3);
	cout<<f(10,6,5)<<endl;
	return 0;
}