#include "../../std_lib_facilities.h"
using Line = vector<char>;

class Text_iterator
{
    list<Line>::iterator ln;
    Line::iterator pos;

public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        : ln(ll), pos(pp) {}

    list<Line>::iterator get_line() { return ln; }
    Line::iterator get_pos() { return pos; }

    char &operator*() { return *pos; }
    Text_iterator &operator++();

    bool operator==(const Text_iterator &other) const
    {
        return ln == other.ln && pos == other.pos;
    }
    bool operator!=(const Text_iterator &other) const
    {
        return !(*this == other);
    }
};
Text_iterator &Text_iterator::operator++()
{
    ++pos;
    if (pos == (*ln).end())
    {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}
//-----------------------------------------------------
template <class Iter>
bool match(Iter first, Iter last, const string &s)
{
    string::const_iterator si = s.begin();
    while (first != last && si != s.end())
    {
        if (*first != *si)
            return false;
        ++first;
        ++si;
    }
    return true;
}

template <class Iter, class T>
Iter find(Iter first, Iter last, const T &val)
{
    Iter p = first;
    while (p != last)
    {
        if (*p == val)
            return p;
        ++p;
    }
    return p;
}
Text_iterator find_txt(Text_iterator first, Text_iterator last, const string &s)
{
    if (s.size() == 0)
        return last; // can't find an empty string
    char first_char = s[0];
    while (true)
    {
        auto p = ::find(first, last, first_char);
        if (p == last || match(p, last, s))
            return p;
        first = ++p; // look at the next character
    }
}

template <class Iter>
void advance(Iter &p, int n)
{
    if (n > 0)
    {
        while (n > 0)
        {
            ++p;
            --n;
        }
    }
    else if (n < 0)
    {
        while (n < 0)
        {
            --p;
            ++n;
        }
    }
}
//DOC---------------------------------------
struct Document
{
    list<Line> line;
    Document() { line.push_back(Line()); }
    Text_iterator begin()
    {
        return Text_iterator(line.begin(), (*line.begin()).begin());
    }
    Text_iterator end()
    {
        list<Line>::iterator last = line.end();
        --last;
        return Text_iterator(last, (*last).end());
    }

    void find_replace(Text_iterator first, Text_iterator last,
                      const string &find_str, const string &repl_str);
    Text_iterator erase(Text_iterator pos);
    Text_iterator insert(Text_iterator pos, const char &ch);
};
Text_iterator Document::erase(Text_iterator pos)
{
    list<Line>::iterator list_it = pos.get_line();
    Line::iterator line_it = pos.get_pos();
    line_it = (*list_it).erase(line_it);
    return Text_iterator(list_it, line_it);
}

Text_iterator Document::insert(Text_iterator pos, const char &ch)
{
    list<Line>::iterator list_it = pos.get_line();
    Line::iterator line_it = pos.get_pos();
    line_it = (*list_it).insert(line_it, ch);
    return Text_iterator(list_it, line_it);
}
//ex6 finds and replace string (UNFOURTNATELY DOESN'T PROCCESS WELL WITH '\n' in string)
void Document::find_replace(Text_iterator first, Text_iterator last,
                            const string &find_str, const string &repl_str)
{
    if (find_str == "")
        return;
    Text_iterator pos = find_txt(first, last, find_str);
    while (pos != last)
    {
        int sf_s = find_str.size();
        int c1 = 0;
        while (c1 != sf_s)
        {
            erase(pos);
            c1++;
        }

        int sr_s = repl_str.size();
        int c2 = 0;
        while (c2 != sr_s)
        {
            insert(pos, repl_str[sr_s - c2 - 1]);
            c2++;
        }

        pos = find_txt(first, last, find_str);
    }
}
ostream &operator<<(ostream &os, vector<char> v)
{
    for (auto p : v)
        cout << p;
    return os;
}
istream &operator>>(istream &is, Document &v)
{
    char c;
    is.unsetf(ios::skipws);
    while (is >> c)
    {
        
        v.line.back().push_back(c);
        if (c == '\n')
        {
            v.line.push_back(Line());
    
        }
    };
    if (v.line.back().size())v.line.push_back(Line());
    
    return is;
}

void print(Document &d, Text_iterator p)
{

    for (; p != d.end(); ++p)
        cout << *p;
    cout << "\n";
}
ostream &operator<<(ostream &os, Document &v)
{
  Text_iterator p= v.begin();
  for (; p != v.end(); ++p)
        os << *p;
    os << "\n";

    
}
void erase_line(Document &d, int n)
{
    if (n < 0 || d.line.size() - 1 <= n)
        return;
    auto p = d.line.begin();
    advance(p, n);
    d.line.erase(p);
}
//ex7 char counter
int c_count(Document &v )
{
    int c=0;
    Text_iterator it = v.begin();
    while(it!=v.end())
    {
        c++;
        ++it;
    }
    return c;
}
//ex9 with spaces (divided words)
int s_count1(Document &v )
{
    int c=0;
    Text_iterator it = v.begin();
    while(it!=v.end())
    {
         if(isspace(*it) || *it=='\n'){
            c++;
            
            while( isspace(*it)|| *it=='\n')
            {
                ++it;
                if(it==v.end()){break;}
            }
        } 
        if(it==v.end()){c--;break;}
        ++it;
    }
    c++;
    return c;
}
//with no letters(divide words)
int s_count2(Document &v )
{
    int c=0;
    Text_iterator it = v.begin();
    while(it!=v.end())
    {
        if(isalpha(*it) ){
            c++;
            
            while( isalpha(*it))
            {
                ++it;
                if(it==v.end())break;
            }
        } 
        if(it==v.end()){c--;break;}
        ++it;
    }
     c++;
    return c;
}
//ex10 
//with any chars
int s_count3(Document &v, vector<char> k)
{
    int c=0;
    Text_iterator it = v.begin();
    
    while(it!=v.end())
    {
        cout<<"P:"<<*it<<'\n';
        if(::find(k.begin(),k.end(),*it)!=k.end() ){
            c++;
           // cout<<"|Co tu mamy"<<*it;
            while( ::find(k.begin(),k.end(),*it)!=k.end())
            {
                //cout<<"in"<<*it;
                ++it;
                if(it==v.end()){c--;break;}
            }
        }
       
        if(it==v.end())break;
        ++it;
    }
    c++;
    return c;
}
//
//
//
//
void test()
{
    ifstream ifs{"text.txt"};
    if (!ifs)
        error("File is corrupted\n");
    Document doc;
    ifs >> doc;
    //doc.find_replace(doc.begin(),doc.end(),"Poland","WIELKA LECHIA");
    print(doc, doc.begin());
    ifs.close();
    cout<<s_count1(doc);
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
