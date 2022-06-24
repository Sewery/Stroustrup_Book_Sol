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
double* high_vec(vector<double>& v)
{
    double* z =&v[0];
    for( double &i: v)if(i>*z)z=&i;
    return z;
}
double* high_arr(double arg[], int n)
{
    int first =0;
    double* high =arg;
    while(first<n)
    {
        if(*arg>*high){high=arg;}
        arg++;
        first++;
    }
    return high;
}
double* high_fl(double* first, double* last)
{
    double h = -1;
    double* high;
    for(double* p = first; p!=last; ++p)
        if (h<*p) { high = p; h = *p; }
    return high;
}
int main()
{

    try
    {
        int jack_count = 7;
        double* jack_data = get_from_jack(&jack_count);
        vector<double>* jill_data = get_from_jill();
        for(int i=0; i<jack_count;i++)cout<<jack_data[i]<<" ";
        cout<<'\n';
        for(auto i : *jill_data)cout<<i<<" ";
        cout<<'\n';
        cout<<"Max for jack:"<<*high_fl(jack_data,jack_data+jack_count)<<"\n";
         cout<<"Max for jack(ARR):"<<*high_arr(jack_data,jack_count)<<"\n";
        cout<<"Max for Jill:"<<*high_fl(&(*jill_data)[0],&(*jill_data)[0]+jill_data->size())<<"\n";
        cout<<"Max for Jill(VEC):"<<*high_vec(*jill_data)<<"\n";
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
