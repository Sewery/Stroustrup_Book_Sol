#include <math.h>

#include "../../std_lib_facilities.h"

template<class T >class counted_pointer{
    
    T* obj;
    int* use;
    public:
    
    counted_pointer( const T& ob);
    counted_pointer( const counted_pointer&);
    counted_pointer& operator=(const counted_pointer&);
    ~counted_pointer();

    T operator*() const { return *obj; }
    T* operator->() const { return obj; }

    int count(){return *use;}

};
//---------------------------------------------
template<class T >
counted_pointer<T>::counted_pointer(const T& ob)
{
    obj= new T(ob);
    use= new int(1);
}
//---------------------------------------------

template<class T> counted_pointer<T>::counted_pointer(const counted_pointer& arg)
{
    this.obj = arg.obj;
    use = arg.count();
    ++*use;       
}
//---------------------------------------------
template<class T>
counted_pointer<T>& counted_pointer<T>::operator=(const counted_pointer& a)
{
if(this==&a)return *this;
--(*use);
if(*use==0){
    delete obj;
    delete use;

}
 
  obj = a.obj;
  use = a.use;

  (*use)++;
    
  
  return *this;

}
//----------------------------------------------------
template<class T> counted_pointer<T>::~counted_pointer(){
    (*use)--;


    if (*use == 0) {
        cout << "Destructing counted pointer\n";
        delete obj;
        delete use;
    }

}
//-----------------------------------
int* tester(){
    int cr =3293;
    counted_pointer<int> c(cr);


}
int main(){
    tester();
    int a =102;
    int b =9302;
  
    counted_pointer<int> p (a);
    cout<<*p<<" "<<p.count()<<" ";
    counted_pointer<int> p1 (b);
    p=p1;
    cout<<*p<<" "<<p.count()<<" ";


}