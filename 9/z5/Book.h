#include "../../std_lib_facilities.h"
#include "date.h"
enum class Genre{
    fiction=1 , non_fiction, magazine , biography, cartoon
};

class Book{
    private:
        string ISBN;
        string name;
        string author;
        Genre gen;
        Chronology::Date1 date;
        bool lend;
        
    public:
        void setlend(bool t);
        Book(string,string,string,Genre,Chronology::Date1,bool);
        bool islend() const;
        string getISBN() const;
        string getName()const;
        string getAuthor()const;
        Genre getGenre()const;
        Chronology::Date1 getDate()const;

};
ostream& operator<<(ostream& os, Book book);
bool operator==(const Book& a, const Book& b);
bool isISBNcorrect(string ISBN);
class Patron{
    private:
        string name;
        int numberOfCard;
        int fees;
    public:
        Patron(string, int , int);
        string getName() const;    
        int getNumberOfCard() const;
        int getFees() const; 
        void nextfee(int k);
};
bool feePatron(Patron p);
struct Transaction{

    Book book;
    Patron patron;
    Chronology::Date1 date;
    Transaction(Book,Patron, Chronology::Date1);
};
class Library{
    private:
        vector<Book> b;
        vector<Patron> p;
        vector<Transaction> t;
    public: 
        vector<Book> getB() const;
        vector<Patron> getP() const ;
        vector<Transaction> getT() const ;
        void addBook(Book);
        void addPatron(Patron);
        void addTranscation(Transaction);

};
void lendBook(Patron,Library,Book);
vector<Patron> getAllDebtors(Library lib);



