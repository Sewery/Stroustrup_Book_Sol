
#include <iostream>
using namespace std;
//
// This is example code from Chapter 25.3.3 "Pool Example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------

struct Message
{
    int a, b, c;
};

//------------------------------------------------------------------------------

struct Node
{
    int a, b;
};

//------------------------------------------------------------------------------

Message *get_input()
{
    return new Message();
}
void frag()
{
    Message *p0 = get_input();
    Node *n = new Node();
    delete p0;
    Node *n02 = new Node();

    Message *p = get_input();
    Node *n1 = new Node();
    delete p;
    Node *n2 = new Node();

    int i = 0;
    while (i != 100)
    {
        p = get_input();
        n1 = new Node();
        delete p;
        n2 = new Node();
        i++;
    }
   
    cout << "diference-" << n2 - n1;
}
void non_frag()
{
    
    Node *n0 = new Node();
    Node *n02 = new Node();
    Message *p0= get_input();; 
    delete p0;

    Node *n1 = new Node();
    Node *n2 = new Node();
    Message *p = get_input();
    

    delete p;

    int i = 0;
    while (i != 100)
    {
        n1 = new Node();
        n2 = new Node();
        p = get_input();
        delete p;
        i++;
    }
    
    cout << "diference-" << n2 - n1;
}
//----------------------------------------------------


int main()
{

    try
    {
        cout<<sizeof(Message)<<" : : "<<sizeof(Node)<<'\n';
        frag();
        cout << '\n';
        non_frag();
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
