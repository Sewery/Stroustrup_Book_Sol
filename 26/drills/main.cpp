#include "../../std_lib_facilities.h"

//
// This is example code from Chapter 26.3.2.2 "A simple test harness" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>
using namespace std;

//------------------------------------------------------------------------------
template <class T>
ostream &operator<<(ostream &os, const vector<T> &s)
{
    for (const auto p : s)
        os << p << " ";
    return os;
}
//------------------------------------------------------------------------------
template <class T>
istream &operator>>(istream &is, vector<T> &s)
{
    T k;
    while (is >> k)
    {
        s.push_back(k);
    }

    return is;
}
//------------------------------------------------------------------------------
template <class T>
T from_string(const string &s)
{
    istringstream is{s};
    T t;
    is >> t;
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

void test1()
{
    int a1[] = {1, 2, 3, 5, 8, 13, 21};
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 1) == false)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 5) == false)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 8) == false)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 21) == false)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), -7) == true)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 4) == true)
        cout << "failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 22) == true)
        cout << "failed";
}

//------------------------------------------------------------------------------

void test2()
{
    int a1[] = {1, 2, 3, 5, 8, 13, 21};
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 1) == false)
        cout << "1 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 5) == false)
        cout << "2 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 8) == false)
        cout << "3 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 21) == false)
        cout << "4 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), -7) == true)
        cout << "5 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 4) == true)
        cout << "6 failed";
    if (bin_search(a1, a1 + sizeof(a1) / sizeof(*a1), 22) == true)
        cout << "7 failed";
}

//------------------------------------------------------------------------------

struct Test
{
    string label;
    int val;
    vector<int> seq;
    bool res;
};
//------------------------------------------------------------------------------

struct Test_str
{
    string label;
    string val;
    vector<string> seq;
    bool res;
};
//------------------------------------------------------------------------------

istream &operator>>(istream &is, Test &t) // use the described format
{
    regex reg{R"(^\{ (\d\.\d|\d |\d) (-?\d+) \{ ([\d+ ]*)\} (0|1) \}$)"};

    string line;
    getline(is, line);
    if (line == "")
        return is;
    smatch matches;

    if (regex_match(line, matches, reg))
    {
        t.label = to_string(matches[1]);
        t.val = from_string<int>(matches[2]);
        t.seq = from_string<vector<int>>(matches[3]);
        t.res = from_string<bool>(matches[4]);
    }
    else
    {
        error("Regex doesn't match");
    }

    return is;
}

//------------------------------------------------------------------------------

istream &operator>>(istream &is, Test_str &t) // use the described format
{
    regex reg{R"(^\{ (\d\.\d|\d |\d) (\w+) \{ ([\w+ ]*)\} (0|1) \}$)"};

    string line;
    getline(is, line);
    if (line == "")
        return is;
    smatch matches;
    if (regex_match(line, matches, reg))
    {
        t.label = to_string(matches[1]);
        t.val = from_string<string>(matches[2]);
        t.seq = from_string<vector<string>>(matches[3]);
        t.res = from_string<bool>(matches[4]);
    }
    else
    {
        error("Regex doesn't match");
    }

    return is;
}

//------------------------------------------------------------------------------

ostream &operator<<(ostream &os, const Test &t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(os, " "));
    return os << "} " << t.res << " }";
}
//------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Test_str &t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<string>(os, " "));
    return os << "} " << t.res << " }";
}
//------------------------------------------------------------------------------
void test_Test()
{
    ifstream ifs{"test.txt"};
    if (!ifs)
        error("Sth went wrong");
    vector<Test> vt;
    Test t;
    while (ifs >> t)
    {
        vt.push_back(t);
    }

    for (const Test &p : vt)
        cout << p << '\n';
     ifs.close();   
}

//------------------------------------------------------------------------------

int test_all_from_file()
{
    ifstream ifs{"test.txt"};
    if (!ifs)
        error("Sth went wrong");
    int error_count = 0;
    Test t;
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

int test_all_from_file_str()
{
    ifstream ifs{"str_test.txt"};
    if (!ifs)
        error("Sth went wrong");
    int error_count = 0;
    Test_str t;
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

int rand_int(int max) { return rand()%max; }

//------------------------------------------------------------------------------

int rand_int(int min, int max) { return rand_int(max-min)+min; }

//------------------------------------------------------------------------------

void make_test(const string& lab, int n, int base, int spread)
// write a test description with the label lab to cout
// generate a sequence of n elements starting at base
// the average distance between elements is spread
{
    cout << "{ " << lab << " " << n << " { ";
    vector<int> v;
    int elem = base;
    for (int i = 0; i<n; ++i) {           // make elements
        elem+= rand_int(spread);
        v.push_back(elem);
    }

    int val = base+ rand_int(elem-base);  // make search value
    bool found = false;
    for (int i = 0; i<n; ++i) {           // print elements and see if val is found
        if (v[i]==val) found = true;
        cout << v[i] << " ";
    }
    cout << "} " << found << " }\n";
}
//------------------------------------------------------------------------------
void ten_random_seq()
{
    int no_of_tests = 10;       // make about 5 tests
    for (int i = 0; i<no_of_tests; ++i) {
        string lab = "rand_test_";
        make_test(lab+to_string(i),       // to_string from �23.2
            rand_int(1000),                // number of elements
            0,                            // base
            rand_int(50));                // spread
    }
    
}
//------------------------------------------------------------------------------
void big_seq()
{
    int no_of_tests = rand_int(10);       // make about 5 tests
   
    string lab = "rand_test_";
     make_test(lab+to_string(0),       // to_string from �23.2
        rand_int(100),                // number of elements
        0,                            // base
        10);                // spread
    
}

//------------------------------------------------------------------------------
void ten_random_to_ten()
{
    int no_of_tests = 10;       // make about 5 tests
    for (int i = 0; i<no_of_tests; ++i) {
        string lab = "rand_test_";
        make_test(lab+to_string(i),       // to_string from �23.2
            i+1,                // number of elements
            0,                            // base
            10);                // spread
    }
    
}

//------------------------------------------------------------

int main()
{
    try
    {
        //test_Test();
        test1();
        test2();
        cout<<test_all_from_file();
       // big_seq();
       // ten_random_seq();
        //ten_random_to_ten();
        test_all_from_file_str();
  
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