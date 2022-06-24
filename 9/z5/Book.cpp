  #include "Book.h"
     Book::Book(string s1,string s2,string s3,Genre g ,Chronology::Date1 s4 ,bool b)
     : ISBN(s1), name(s2),gen(g), author(s3), date(s4),lend(b){}
  
    string Book::getISBN()const{return ISBN;}
    string Book::getName()const{return name;}
    string Book::getAuthor()const{return author;}
    Chronology::Date1 Book::getDate()const{return date;}
    bool Book::islend()const{return lend;}   
    void Book::setlend(bool t){lend=t;}   
    Genre Book::getGenre()const{return gen;}

    bool isISBNcorrect(string ISBN){
        int dashes =0;
        for(int i =0 ; i<ISBN.length();i++){

            char c= ISBN[i];
            if(c =='-'){
                dashes++;
            }else{
              
                if(!isdigit(c)&& dashes !=3){
                   
                    return false;
            
                }else if(!isdigit(c) && dashes==3 && !isalpha(c)){
              
                    return false;
                }
            }

        }

        return dashes==3;
    }
ostream& operator<<(ostream& os, Book book){
    os<<" Numer ISBN:"<<book.getISBN()<<"\n Nazwa ksiazki:"<<book.getName()<<"\n Imie autora:"<<
    book.getAuthor()<<"\n Data publikacji:"<<book.getDate()<<"\n--------------------\n";
}
bool operator==(const Book& a, const Book& b){
   return  a.getISBN()== b.getISBN() && a.getName()== b.getName() && a.getAuthor()== b.getAuthor();
       
}
Patron::Patron(string n, int k , int f):name(n),numberOfCard(k),fees(f){}
string Patron::getName() const{return name;}    
int Patron::getNumberOfCard() const{return numberOfCard;}
int Patron::getFees() const{return fees;}
void Patron::nextfee(int k){fees+=k;}

bool feePatron(Patron p){
    return p.getFees()==0;
}

Transaction::Transaction(Book b,Patron p, Chronology::Date1 d):
book(b),patron(p),date(d){}

void Library::addBook(Book book ){b.push_back(book);}
void Library::addPatron(Patron patron){p.push_back(patron);}
void Library::addTranscation(Transaction tra){t.push_back(tra);}
vector<Book> Library::getB() const{return b;}
vector<Patron> Library::getP() const{return p;}
vector<Transaction> Library::getT() const{return t;}




void lendBook(Patron pa, Library lib, Book book, Chronology::Date1 d){
    int h =lib.getP().size();
    for(int i=0; i<h;i++){
        if(lib.getP()[i].getNumberOfCard()==pa.getNumberOfCard()){
             for(int i=0; i<lib.getB().size();i++){
                    if(lib.getB()[i]==book){
                        Transaction k{book,pa,d};
                        lib.addTranscation(k);
                        return;
                    }
             }

        }
    }
    cerr<<"Brak uzytwkownika lub ksiazki w bibliotece \n";
}
vector<Patron> getAllDebtors(Library lib){
    cout<<"Imiona dluznikow \n";
    for(auto k : lib.getP()){
        if(feePatron(k)){
            cout<<k.getName()<<"\n";
        }
    }
}