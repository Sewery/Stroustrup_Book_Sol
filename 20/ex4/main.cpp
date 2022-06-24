#include "../../std_lib_facilities.h"
double* get_from_jack(int* count)
{
    string file = "jack.txt";
    ifstream is{file};
    if(!is)error("Can't open input file %s ",file);
    double* data = new double[*count];
    double d;
    int i=0;
    while(is>>d)
    {
        data[i]=d;
        i++;
    }
    return data;

}
vector<double>* get_from_jill()
{
    string file = "jill.txt";
    ifstream is{file};
    if(!is)error("Can't open input file %s ",file);
    vector<double>* d =new vector<double>;
    double p;
    while(is>>p)
    { 
        if(!is)error("Bad input %s ",file);
        d->push_back(p);

    }

    return d;
}
template<typename Iterator>
Iterator high(Iterator first , Iterator last)
{
    if(first==last)error("No highest value in empty sequence");
    Iterator high =first;
    for(Iterator p= first; p!=last;p++)
    {
        if(*high<*p)high= p;
    }
    return high;
}
int main()
{

    try
    {
        int jack_count = 7;
        double* jack_data = get_from_jack(&jack_count);
        vector<double>* jill_data = get_from_jill();
      
        cout<<"Max for Jack:"<<*high(jack_data,jack_data+jack_count)<<"\n";
        cout<<"Max for Jill:"<<*high(&(*jill_data)[0],&(*jill_data)[0]+jill_data->size())<<"\n";

        delete[] jack_data;
        delete jill_data;
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
