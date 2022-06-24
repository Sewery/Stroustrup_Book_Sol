
#include "Book.h"
vector<Book> s {};

void print(){
      cout<<" Liczba ksiazek :"<<s.size()<<'\n';
      cout<<" Ksiazki wypozyczone:\n";
      for(  Book h: s){
         cout<<h;
      }
}
void bookslend(Book book){
   if(isISBNcorrect(book.getISBN()) && book.islend()==false){
      book.setlend(true);
      s.push_back(book);
     
      print();
   }else{
      cerr<<" Nieprawidlowy numer ISBN lub ksiazka jest juz wypozyczona\n";
   }
}
void booksGiveBack(Book book){
       for(int i=0; i<s.size();i++){
          if(s[i]==book && s[i].islend()){
             s.erase(s.begin()+i);
             cout<<" Ksiazka zostala oddana. Pokazamy na teraz stan ksiazek wypozyczonych\n";
             break;
          }
      }
    print();
}


 int main(){
    
     try{
      Chronology::Date1 d1{2020,Chronology::Month::jan,10};
      Chronology::Date1 d2{2020,Chronology::Month::feb,20};
      Book b1{"saspierkf","gfygeyg","byewyg",Genre::cartoon,d1,false};
      Book b2{"1823-47123-7574-kjf9","Dziady","Mickiewicz",Genre::cartoon,d2,false};
      Book b3{"6371-7381-7654-khy1","Dziady 2","Slowacki",Genre::non_fiction,d1,false};
       bookslend(b1);
        bookslend(b2);
        bookslend(b3);
        booksGiveBack(b2);
     }catch(exception& ar ){
        cerr<<"Wystapil nieoczekiwany blad:"<<ar.what();
        return -1;
     }catch(...){
        cerr<<"Wystapil nieoczekiwany blad";
        return -2;
     }
       

     return 0;
 }