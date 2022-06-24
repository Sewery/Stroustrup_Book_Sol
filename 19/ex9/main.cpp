#include <math.h>

#include "../../std_lib_facilities.h"

template<class T >class unique_pointer{
    private:
    T*obj;
    public:
    unique_pointer( T* obj):obj{obj}{}
    ~unique_pointer(){delete obj;}

    T operator*() const { return *obj; }
    T* operator->() const { return obj; }

    T* release(){
        T* temp = obj;
        obj = 0;
        return obj;
    }

};
 
int main(){

  int a = 10;
  int b = 32;
  int c = 32;

  int d = 43;
  int e = 65;
  int f = 435;
  unique_pointer<vector<int>> xd1{new  vector<int>};
  xd1->push_back(a);
  xd1->push_back(b);
  xd1->push_back(c);

  vector<int> xd2;
  xd2.push_back(d);
  xd2.push_back(e);
  xd2.push_back(f);
 vector<int> xd3 = *xd1;
for(int i=0; i< xd1->size();i++) cout<<xd3[i];
  

}