#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void print(const string& s)
{
    for (int i = 0; i<s.size(); ++i)
        cout << '\'' << s[i] << "\': " << (int)char(s[i]) << '\n';
}

bool comp_char(char a, char b)
{
    return  char(a) < char(b);
}

int main()
{
    string s = "`1234567890-=~!@#$%^&*()_+[];',./\{}|:<>?";
    s += "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    print(s);
    sort(s.begin(),s.end(),comp_char);
    cout << "\nAnd sorted:\n";
    print(s);
}