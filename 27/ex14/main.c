#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#define LEN 128
#define ALLOC(T, n) ((T *)malloc(sizeof(T) * n))

struct data{
    int min, max,med;
    double avg;
};
void print_data(struct data *d)
{
    printf("min:%d max:%d med:%d avg:%.2f \n", d->min, d->max, d->med, d->avg);
}
struct data* get_data(int * a, size_t size)
{
    assert(a);
    int* ar =a; 
    int min = INT_MAX;
    int max = INT_MIN;
    int count =0;
    int sum =0;
    while(count!=size)
    {
        count ++;
        sum+=*a;
        if(*a<min)
            min=*a;
        if(*a>max)
            max=*a;
        a++;
    }
    struct data *d=ALLOC(struct data, 1);
    d->min=min;
    d->max=max;
    int mid =count/2;
    d->med=ar[mid];
    d->avg=sum/(double)count;
    return d;
}
int main()
{
    int  a[]= {1,4,2,14,1,1234,2123,434};
    int  b[]= {9,-6,9,0,3423,216,-8,1,7676,12};
    int  c[]= {1,2,0,1,-1234,23,4,0};
    int  d[]= {14,1,1234,-2123,434,94,312};

    print_data(get_data(a,8));
    print_data(get_data(b,10));
    print_data(get_data(c,8));
    print_data(get_data(d,7));

}