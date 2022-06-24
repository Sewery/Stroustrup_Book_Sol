#include "../../std_lib_facilities.h"


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
istream &operator>>(istream &is, Test<T> &t) 
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

template<class Iterator,class T, class Comp>
bool bin_search(Iterator begin ,Iterator end, const T& value, Comp comp)
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
    else if (comp(*t,value))
        return bin_search(begin, t, value, comp);
    else if (!comp(*t,value))
        return bin_search(t, end, value, comp);
    return false;
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
        bool r = bin_search(t.seq.begin(), t.seq.end(), t.val,greater<T>());
        if (r != t.res)
        {
            cout << "failure: test " << t.label<<"in file: "<<file
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
        const string test1 ="test_int.txt";
        const string test2 ="test_double.txt";
        const string test3 ="test_str.txt";

        cout<<"Number of errors in test1: "<<test_all_from_file<int>(test1)<<"\n";
        cout<<"Number of errors in test2: "<<test_all_from_file<double>(test2)<<"\n";
        cout<<"Number of errors in test3: "<<test_all_from_file<string>(test3)<<"\n";
  
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
