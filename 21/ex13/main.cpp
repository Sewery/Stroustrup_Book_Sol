#include<map>
#include <algorithm>
#include <numeric>
#include "../../std_lib_facilities.h"
//-------------------------------------------------------------------
void print_map( const map<string,int> map)
{
    for(const auto p: map)
    {
        cout<<p.first<<" with "<<p.second<<" occurences\n";
    }
}
//-------------------------------------------------------------------
//ex13
map<string,int> proccess_text(const string& file)
{
    ifstream ifs;
    ifs.open(file);
    ifs>>noskipws;
    if(!ifs)error("File is corrupted");
    char c;
    stringstream ss;
    while(ifs>>c)
    {
        if(ispunct(c))c=' ';
        if(isupper(c)) c+=32;

        ss<<c;

    }
    string s;
    map<string,int> words;
    while(ss>>s)
    {
        if(s=="t")++words["not"];
        else if(s=="ll")++words["will"];
        else if(s=="ve")++words["have"];
        else if(s=="d")++words["would"];
        else if(s=="re")++words["are"];
        else if(s=="s")++words["is"];
        else if(s=="m")++words["am"];
        else if(s=="gotta"){++words["got"];++words["to"];}
        else if(s=="gonna"){++words["going"];++words["to"];}
        else if(s=="wanna"){++words["want"];++words["to"];}
        else if(s=="girls")++words["girl"];
        else if(s=="books")++words["book"];
        else if(s=="cars")++words["car"];
        else if(s=="programmers")++words["programmer"];
        else ++words[s];
    }
    return words;
}
//ex14
//-------------------------------------------------------------------
int number_of_occurrences_of_words(map<string,int> map)
{
    int sum=0;
    for(const auto r: map)
    {
       sum+= r.second;
    }
    return sum;
}
//-------------------------------------------------------------------
map<string,int>::iterator most_frequent_word(map<string,int> ap)
{
    map<string,int>::iterator word = ap.begin();
    for(map<string,int>::iterator it=ap.begin(); it!=ap.end(); ++it)
    {
       if(it->second>word->second)word=it; 
    }
    return word;
}
//-------------------------------------------------------------------
map<string,int>::iterator longest_word(map<string,int> ap)
{
    map<string,int>::iterator word = ap.begin();
    for(map<string,int>::iterator it=ap.begin(); it!=ap.end(); ++it)
    {
       if(it->first.size()>word->first.size())word=it; 
    }
    return word;
}
//-------------------------------------------------------------------
map<string,int>::iterator shortest_word(map<string,int> ap)
{
    map<string,int>::iterator word = ap.begin();
    for(map<string,int>::iterator it=ap.begin(); it!=ap.end(); ++it)
    {
       if(it->first.size()<word->first.size())word=it; 
    }
    return word;
}
//-------------------------------------------------------------------
map<string,int> word_started_on_letter(map<string,int> ap, char letter)
{
    map<string,int> ret;
    for(map<string,int>::iterator it=ap.begin(); it!=ap.end(); ++it)
    {
       if(it->first[0]==letter)
       {
           ret[it->first]+=it->second;
       }
    }
    return ret;
}

//-------------------------------------------------------------------
map<string,int> word_at_specifed_length(map<string,int> ap, int len)
{
    map<string,int> ret;
    for(map<string,int>::iterator it=ap.begin(); it!=ap.end(); ++it)
    {
       if(it->first.size()==len)
       {
           ret[it->first]+=it->second;
       }
    }
    return ret;
}

//-------------------------------------------------------------------
void menu_bar()
{
    cout << "Choose option.\n"
        << "1 - Enter input file name\n"
        << "2 - Get number of occurrences of a words\n"
        << "3 - Get most frequent word\n"
        << "4 - Get longest word\n"
        << "5 - Get shortest word\n"
        << "6 - Get words starting with a specific letter\n"
        << "7 - Get words of a specific length\n"
        << "10 - Exit\n";
}
//-------------------------------------------------------------------
void action()
{
    map<string,int> m; 
    while(true){
        int p;
        cout<<"-------------------------------------------------------------------\n";
        menu_bar();
        cin>>p;
        if(p==10)break;
        switch(p){
            case 1:
            {
                cout<<"Enter file name: ";
                string file;
                cin>>file;
                m=proccess_text(file);
                cout<<"\nFounded\n";
                break;
            }
            case 2:
            {
                if(m.size()==0)error("I haven't text to analayze");
                cout<<"Number of occurences of words: "<<number_of_occurrences_of_words(m)<<'\n';
                break;
            }
            case 3:
            {
                if(m.size()==0)error("I haven't text to analayze");
                map<string,int>::iterator it =most_frequent_word(m);
                cout<<"Most freqent word is: '"<<it->first<<"' with "<<it->second<<" occurences\n";
                 break;
            }
            case 4:
            {
                if(m.size()==0)error("I haven't text to analayze");
                map<string,int>::iterator it =longest_word(m);
                cout<<"Longest word is: '"<<it->first<<"' with "<<it->second<<" occurences\n";
                break;
            }
            case 5:
            {
                if(m.size()==0)error("I haven't text to analayze");
                map<string,int>::iterator it =shortest_word(m);
                cout<<"Shortest freqent word is: '"<<it->first<<"' with "<<it->second<<" occurences\n";
                 break;
            }
            case 6:
            {
                if(m.size()==0)error("I haven't text to analayze");
                cout<<"Eneter a letter: ";
                char c;
                cin>>c;
                map<string,int> it =word_started_on_letter(m,c);
                cout<<"\nWords started on '"<<c<<"': \n";
                print_map(it);
                 break;
            }
            case 7:
            {
                if(m.size()==0)error("I haven't text to analayze");
                cout<<"Eneter a length: ";
                int a;
                cin>>a;
                map<string,int> it =word_at_specifed_length(m,a);
                cout<<"\nWords with length "<<a<<": \n";
                print_map(it);
                 break;
            }
            default:break;

            
        }
            
                

    }
   
}


//-------------------------------------------------------------------
int main(void)
{
    try
    {
     action();
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