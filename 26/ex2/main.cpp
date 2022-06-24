

//
// This is example code from Chapter 26.3.2.2 "A simple test harness" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
#include "../../std_lib_facilities.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>
using namespace std;

//------------------------------------------------------------------------------
template <class T>
ostream& operator<<(ostream &os, const vector<T> &s)
{
    for (const auto p : s)
        os << p << " ";
    return os;
}
//------------------------------------------------------------------------------
template <class T>
istream& operator>>(istream &is, vector<T> &s)
{
    T k;
    while (is >> k)
    {
        if(!is)
            error("Sth went wrong");
        s.push_back(k);
    }
    is.unget();
    is.clear();
    is.setstate(ios_base::goodbit);
    return is;
}
//------------------------------------------------------------------------------
template <class T>
T from_string(const string &s)
{
    istringstream is{s};
    T t;
    is >> t;
    if(!is)
        error("Sth went wrong");
    return t;
}
//------------------------------------------------------------------------------
template <class Iterator, class T>
bool bin_search(Iterator begin, Iterator end, const T &value)
{
    int size = end - begin;
    if(size==0)
        return false;
    int mid = size / 2;
    Iterator t = begin + mid;
    if (*t == value)
        return true;
    if (t == begin)
        return false;
    else if (*t > value)
        return bin_search(begin, t, value);
    else if (*t < value)
        return bin_search(t, end, value);
    return false;
}
//------------------------------------------------------------------------------
template<class T>
struct Test
{
    string label;
    T val;
    vector<T> seq;
    bool res;
};
//------------------------------------------------------------------------------
template<class T>
istream &operator>>(istream &is, Test<T> &t) // use the described format
{
 
    regex reg{R"(^\{ (\d\.\d|\d |\d) (-?\S+) \{ ([\S+ ]*)\} (0|1) \}$)"};

    string line;
    getline(is, line);
    if (line == "")
        return is;
    smatch matches;

    if (regex_match(line, matches, reg))
    {
        t.label = to_string(matches[1]);
        t.val = from_string<T>(matches[2]);
        t.seq = from_string<vector<T>>(matches[3]);
        t.res = from_string<bool>(matches[4]);
    }
    else
    {
        error("Regex doesn't match");
    }

    return is;
}

//------------------------------------------------------------------------------
template<class T>
ostream &operator<<(ostream &os, const Test<T> &t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<T>(os, " "));
    return os << "} " << t.res << " }";
}
//------------------------------------------------------------------------------
template<class T>
void test_Test(const string& file)
{
    ifstream ifs{file};
    if (!ifs)
        error("Sth went wrong");
    vector<Test<T>> vt;
    Test<T> t;
    while (ifs >> t)
    {
        vt.push_back(t);
    }

    for (const Test<T> &p : vt)
        cout << p << '\n';
     ifs.close();   
}

//------------------------------------------------------------------------------
template<class T>
int test_all_from_file(const string& file)
{
    ifstream ifs{file};
    if (!ifs)
        error("Sth went wrong");
    int error_count = 0;
    Test<T> t;
    while (ifs >> t)
    {
        cout <<"Testing:"<< t << endl;
        bool r = bin_search(t.seq.begin(), t.seq.end(), t.val);
        if (r != t.res)
        {
            cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, v==" << t.val
                 << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    ifs.close();   
    return error_count;
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        test_Test<string>("str_test.txt");
        test_all_from_file<string>("str_test.txt");
        
        test_Test<double>("double_test.txt");
        test_all_from_file<double>("double_test.txt");
  
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
//------------------------------------------------------------------------------