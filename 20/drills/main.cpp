#include "../../std_lib_facilities.h"



template<typename Iter1, typename Iter2>
Iter2 copy1(Iter1 f1, Iter1 e1 , Iter2 f2){
    if(e1==f1)return f2;
    Iter2 rr= f2;
    for(Iter1 p = f1; p!=e1;p++)
    {
        *rr=*p;
        rr++;
    }
    return  f2;
}


int main()
{

    try
    {
        int t1[]={0,1,2,3,4,5,6,7,8,9};
        vector<int> t2{0,1,2,3,4,5,6,7,8,9};
        list<int> t3{0,1,2,3,4,5,6,7,8,9};

        //copy array +2
        int t11[10];
        for(int e=0;e<10;e++)
        {
            t11[e]=t1[e]+2;
            cout<<t11[e]<<" ";
        }
        cout<<'\n';

        //copy vector (in comment)
        vector<int> t22(10);
        //t22=t2;
        //for(auto e: t22){e+=3;cout<<e;}
        //!copy vector with copy1 function 
        vector<int>::iterator r = copy1(t2.begin(), t2.end(), t22.begin());
        for(int i =0; i< 10; i++) 
        {
            cout<<*r<<" ";
            r++;
        }
        cout<<'\n';

        //copy list
        list<int> t33;
        t33=t3;
        for(auto e: t33){e+=5;cout<<e<<" ";}
        cout<<'\n';


        //copy list to vector
        list<int> l{1,43,4,632,533,54};
        vector<int> v{0,1,4,3};
        vector<int>::iterator xd =copy1(l.begin(), l.end(), v.begin());
        for(int i =0; i< 7; i++) 
        {
            cout<<*xd<<" ";
            xd++;
        }
        cout<<"\n";
        //using find
        vector<int> j{0,1,4,3,3,928};
        vector<int>::iterator it =j.begin();
        int counter =0;
        if(find(j.begin(),j.end(),3)!=j.end())
        {
            int k= find(j.begin(),j.end(),3)-j.begin();
            cout<<"3 jest na pozycji "<< k<<'\n';
          
            
        }
         if(find(j.begin(),j.end(),27)!=j.end())
        {
           int k= find(j.begin(),j.end(),27)-j.begin();
            cout<<"27 jest na pozycji"<< counter<<'\n';
            
        }

    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "exception\n";
    }
}
