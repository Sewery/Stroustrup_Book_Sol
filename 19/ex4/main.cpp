template<class T >class Link{
    public: 
        T value;
        Link(const T& v, Link<T>*p =nullptr,Link<T>*s =nullptr):
        value{v},prev{p},succ{s}{}

        Link<T>* insert(Link<T>* n);
        Link<T>* add(Link<T>* n);
        Link<T>* erase();
        Link<T>* find(const T& s);

        Link<T>* advance(int n)const;
        Link<T> * next(){return succ;}
        Link<T>* previous(){return prev;}
    private:
        Link<T>* prev;
        Link<T>* succ ; 
};
template<class T >
Link<T>* Link<T>::insert(Link<T>* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;

    n->succ =this;
    if(prev) prev->succ=n;
    n->prev=prev;
    prev= n;
    return n;
}
// insert n after this object
template<class T >
Link<T>* Link<T>::add(Link<T>* n) {
    if (n==0) return this;
    if (this==0) return n;
    n->prev = this;
    if (succ) succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

// erase this object, return successor
template<class T >
Link<T>* Link<T>::erase() {
    if (this==0) return 0;
    if (succ) succ->prev = prev;
    if (prev) prev->succ = succ;
    return succ;
}

// find s in list; return 0 for "not found"
template<class T >
Link<T>* Link<T>::find(const T& s) {
    Link* p = this;
    while (p) {
        if (p->value==s) return p;
        p = p->succ;
    }
    return 0;
}

// move n positions in list, return 0 for "not found"
// positive n moves forward, negative backward
template<class T >
Link<T>* Link<T>::advance(int n) const {
    if (this==0) return 0;
    Link<T>* p = const_cast<Link*>(this);  // UGLY
    if (0 < n) {
        while (n--) {
            if (p->succ==0) return 0;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev==0) return 0;
            p = p->prev;
        }
    }
    return p;
}
template<class T >
void print_all(Link<T> *p){
    cout<<"{ ";
    while(p){
        cout<<p->value;
        if(p=p->next())cout<<", ";
    }
      cout<<" }";
}
int main() {

}