#include "../../std_lib_facilities.h"

template<class Elem>
struct Link{
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0)
        :prev(p), succ(s), val(v) { }
    Link* prev;
    Link*succ;
    Elem val;
};
template<class Elem>
class liste{
    Link<Elem>* first;
    Link<Elem>* last;
public:
    liste() :first(new Link<Elem>()), last(first) { }
    class iterator;

    iterator begin(){return  iterator(first);}
    iterator end(){return  iterator(last);}

    iterator insert( iterator p, const Elem& v );
    iterator erase( iterator p );
    //ex11
    void push_back(const Elem &v)
    {
        if (last == first)
        {
            first = new Link<Elem>(v, 0, last);
            last->prev = first;
        }
        else
        {
            Link<Elem> *curr = new Link<Elem>(v);

            last->prev->succ = curr;
            curr->prev = last->prev;
            curr->succ = last;
            last->prev = curr;
        }
    }
    void push_front(const Elem& v);
    void pop_front();
    void pop_back();
    
    Elem& front();
    Elem& back();
    

};
template<class Elem>
class liste<Elem>::iterator{
    Link<Elem>* curr;
public:
    iterator(Link<Elem> * p): curr{p} {}

    iterator& operator++(){ curr= curr->succ; return *this;}
    iterator& operator--(){ curr= curr->prev; return *this;}
    Elem& operator*() { return curr->val;}

    bool operator==(const iterator&b)const {return curr == b.curr;}
    bool operator!=(const iterator&b)const {return curr != b.curr;}
};
template<class Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high =first;
    for(Iterator p = first; p!= last ; ++p)
    {
        if(*high<*p) high =p;
    }
    return high;
}
void test()
{
    liste<int> p;
    p.push_back(930);
    p.push_back(943);
    p.push_back(143);
    p.push_back(1);
  
    liste<int>::iterator pr = high(p.begin(),p.end());
    cout<<*pr;
 
}
int main()
{

    try
    {
        test();
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
