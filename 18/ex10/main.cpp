#include <math.h>

#include "../../std_lib_facilities.h"

void print (char *k){
 
  while(*k!=0)cout<<*k++;

}
bool is_palindrome(const char s[], int n ){
  
  int first =0;
  int last = n-1;
  while(first<last){
    if(s[first]!=s[last]) return false;
    ++first;
    --last;

   }
   return true;
 
 
}
istream& read_word(istream& is ,char* buffer , int max)
{
  is.width(max);
  is>> buffer;
  if(strlen(buffer)>max-1){
    cout<<"Too big string. A part of the strign is moved to next line \n";
  }
  return is;
}
istream& read_long_word(istream& is ,char* buffer)
{
  const int max =128;
  char * kp = new char[max];
  char * out =kp;
  *out =0;
  char k;
  int counter =0;
  
  while(cin.get(k)){
    if(k=='\n')break;
    counter++;
    
    if(counter>max-2){
    
      char *w= new char[counter];
      copy(out,out+max-1,w); 
      const int wr= max*2; 
      
      out= new char[wr]; 
      copy(w,w+max-1,out); 
      
      delete[] w;
    
     
    }
    out[counter-1] = k;
   
   
  }
  out[counter]=0;
 
  buffer=out;
  cout<<"Mamy buffera: ";
  print(buffer);
  return is;
}


int main(){
 /*
  constexpr int max =128;
  for(char s[max]; read_word(cin,s,max);){
    cout<<s;
    if(!is_palindrome(s,strlen(s))) cout<<" nie";
    cout<<" jest palindromem. \n";
  }
  */

try{
  //****Nie wiadom dlaczego nie chce przyjac buffera******
   char* s2 = 0;
    while (read_long_word(cin,s2) && strcmp(s2,"quit")) {
            cout << s2 <<  " is";
            if (!is_palindrome(s2,strlen(s2))) cout << " not";
            cout << " a palindrome\n";
            delete[] s2;
    }
    delete[] s2;
      
    }

 catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
   
}
 
