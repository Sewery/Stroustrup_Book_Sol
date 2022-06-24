#include <math.h>

#include "../../std_lib_facilities.h"

bool is_aplindrome(const string&s ){
  /*
  int first =0;
  int last = s.length()-1;
  while(first<last){
    if(s[first]!=s[last]) return false;
    ++first;
    --last;

   }
   return true;
   */
  string p;
  for(int i=s.length()-1; i>-1;i--)p.push_back(s[i]);



  return s == p;
}
bool is_aplindrome(const char s[], int n ){
  /*
  int first =0;
  int last = n-1;
  while(first<last){
    if(s[first]!=s[last]) return false;
    ++first;
    --last;

   }
   return true;
   */
  char* p = new char[n];
  int h=0;
   for(int i=n-1; i>-1;i--){p[h]=s[i]; h++;}



  return *s == *p;

}
istream& read_word(istream& is ,char* buffer , int max)
{
  is.width(max);
  is>> buffer;
  return is;
}
bool is_aplindrome(const char * first, const char * last){
  /*
  while(first<last){
    if(*first!=*last) return false;
    ++first;
    --last;

   }
   */
 
  string a;
  string b;
  while(*first){
    a+=*first; first++;
  }

  while(*last){
    b+=*last; last--;
  }
  return a== b;
   /*diff version
    if(first<last){
      if(*first!=*last) return false;
      return is_aplindrome(first+1,last-1)
    }
   */

}
int main(){
  const string a = "jebac pis";
  const string b = "anna"; 
  const char *k= "jebbea";
  const char *f = k;

  k+=5;
   const char *e = k;
 
  cout<<is_aplindrome(f,e);
}

