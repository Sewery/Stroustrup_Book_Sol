
#include "../../std_lib_facilities.h"

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
        if (!is)
            error("Sth went wrong 1");
        s.push_back(k);
    }
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
    if (!is){
        error("Sth went wrong 2");
    }   
    return t;
}
//------------------------------------------------------------------------------
template <class T>
struct Test
{
    string label;
    T val;
    bool res;
};
//------------------------------------------------------------------------------
template <class T>
struct Sequence
{
    vector<T> seq;
    vector<Test<T>> tests;
    string wastes;
};
//-----------------------------------------------------------------------------
template <class T>
istream &operator>>(istream &is, Sequence<T> &s)
{
    //Format
    //example:
    //sequence
    //{ { 1 2 3 4 5 6 7 8 29 } }
    // tests
    //{ 1.1 1 1 }
    //{ 1.2 10 0 }
    regex seq_reg{R"(^\{ \{ ([\S+ ]*)\} \}$)"};
    regex test_reg{R"(^\{ (\d\.\d|\d |\d) (-?\S+) (0|1) \}$)"};
    string line;
    getline(is, line);
    if (line == "")
       return is;
    smatch matches;
    
    if (regex_match(line, matches, seq_reg))
    {
        s.seq = from_string<vector<T>>(matches[1]);
        getline(is, line);
        smatch matches2;
        while (!is.eof() && regex_match(line, matches2, test_reg))
        {
    
            Test<T> te;
            te.label = to_string(matches2[1]);
            te.val = from_string<T>(matches2[2]);
            te.res = from_string<bool>(matches2[3]);
            s.tests.push_back(te);
            getline(is, line);
            if(line=="")
                break;
           
        }
      
    }
    else
    {
        error("Regex doesn't match");
    }

    return is;
}
//------------------------------------------------------------------------------
template <class T>
ostream &operator<<(ostream &os, const Test<T> &t)
{
    os << "{ " << t.label << ' ' << t.val;
    return os <<" "<< t.res << " }";
}

//------------------------------------------------------------------------------
template <class T>
ostream &operator<<(ostream &os, const Sequence<T> &s)
{
    os << "{ "
       << " { ";
    std::copy(s.seq.begin(), s.seq.end(), std::ostream_iterator<T>(os, " "));
    return os << "} " << " }" << '\n'
              << s.tests;
}
//------------------------------------------------------------------------------

template <class Iterator, class T, class Comp>
bool bin_search(Iterator begin, Iterator end, const T &value, Comp comp)
{
    int size = end - begin;
    if (size == 0)
        return false;
    int mid = size / 2;
    Iterator t = begin + mid;
    if (*t == value)
        return true;
    if (t == begin)
        return false;
    else if (comp(*t, value))
        return bin_search(begin, t, value, comp);
    else if (!comp(*t, value))
        return bin_search(t, end, value, comp);
    return false;
}
//------------------------------------------------------------------------------
template <class T>
int test_all_from_file(const string &file)
{
    ifstream ifs{file};
    if (!ifs)
        error("Sth went wrong 3");
    int error_count = 0;
    Sequence<T> t;
   
    while (ifs >> t )
    {
        
        for (const auto z : t.tests)
        {
            cout<<'\n'<<z;
            bool r = bin_search(t.seq.begin(), t.seq.end(), z.val, greater<T>());
            if (r != z.res)
            {
                cout << "failure: test " << z.label << "in file: " << file
                     << " binary_search: "
                     << t.seq.size() << " elements, v==" << z.val
                     << " -> " << z.res << '\n';
                ++error_count;
            }
        }  
        t.tests.clear();
    }
    cout<<'\n';
    ifs.close();
    return error_count;
}

//------------------------------------------------------------------------------

int main()
{
    try
    {
        const string test1 = "test_int.txt";
        const string test2 = "test_double.txt";
        const string test3 = "test_str.txt";

        cout << "Number of errors in test1: " << test_all_from_file<int>(test1) << "\n";
        cout << "Number of errors in test2: " << test_all_from_file<double>(test2) << "\n";
        cout << "Number of errors in test3: " << test_all_from_file<string>(test3) << "\n";
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
