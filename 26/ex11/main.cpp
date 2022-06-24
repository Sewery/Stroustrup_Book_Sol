
#include <chrono>
#include <iostream>
#include <vector>
#include <exception>
#include <random>
#include <chrono>


#include "../../Matrix.h"
#include "../../MatrixIO.h"
using namespace std;
using namespace std::chrono;
using namespace Numeric_lib;
//
//Square Matrix 100 100 time to  add and go through every element is 125 milliseconds
//for 300 300 is 10sec. I didn't try it for 10 000 , 1 000 000 , 10 000 000 since
// it would be persist ages and also my computer even faster would  get out of memory
//

//------------------------------------------------------------------------------

inline int randint(int max) { return rand() % max; }

inline int randint(int min, int max) { return randint(max - min) + min; }
//------------------------------------------------------------------------------

double row_sum(Matrix<double, 2> m, int n) // sum of elements in m[n]
{
    double s = 0;
    for (int i = 0; i < n; ++i)
        s += m(n, i);
    return s;
}

//------------------------------------------------------------------------------

double row_accum(Matrix<double, 2> m, int n) // sum of elements in m[0:n)
{
    double s = 0;
    for (int i = 0; i < n; ++i)
        s += row_sum(m, i);
    return s;
}
//------------------------------------------------------------------------------
Matrix<double, 2> random_matrix(int n)
{
    Matrix<double, 2> m(n, n);
    for (int i = 0; i < m.dim1(); i++)
        for (int j = 0; j < m.dim2(); j++)
            m(i, j) = randint(-10, 10);
    return m;
}

//------------------------------------------------------------------------------

int main()
{
    //not efficient method
    cout<<"Long method results : \n";
    const vector<int> v_m_s = {125, 150, 175, 200};
    for (const auto val : v_m_s)
    {

        Matrix<double, 2> m = random_matrix(val);
        vector<double> v;//keeps rows

        auto t1 = steady_clock::now();//staring clock
        for (int i = 0; i < m.dim1(); ++i)
            v.push_back(row_accum(m, i + 1));
         auto t2 = steady_clock::now();    
       
        cout << "For size "<<val<<" , operation persist for: "
             << duration_cast<milliseconds>(t2 - t1).count()/1000.0 << " seconds\n";
    }
    //faster method
    cout<<"//////////////////////////////////////\n";
    cout<<"Short method results : \n";
      for (const auto val : v_m_s)
    {

        Matrix<double, 2> m = random_matrix(val);
        vector<double> v;//keeps rows

        auto t11 = steady_clock::now();//staring clock
        double sum=0;
        for (int i = 0; i < m.dim1(); ++i)
        {
            sum+=row_sum(m,i);
            v.push_back(sum);
        }  
         auto t22 = steady_clock::now();    
       
        cout << "For size "<<val<<" , operation persist for: "
             << duration_cast<milliseconds>(t22 - t11).count()/1000.0 << " seconds\n";
    }
}

//------------------------------------------------------------------------------
