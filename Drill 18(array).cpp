#include "../../std_lib_facilities.h"


//question 1 : define global array of 10 int like 1,2,4,8,16

const int sz_ga = 10;
//global int array ga of 10 ints
int ga[sz_ga];
//initialized:
void g()
{
  for(int i = 0; i<10; ++i)
  ga[i] = pow(2,i);
}


void print_array(int a[], int sz)
{
  for(int i = 0; i<sz; ++i)
    cout << a[i] << ' ';
  cout << endl;
}

//Question 2 : define function f to indication no. of elements

int f(int arg_arr[], int size)
{

//question 3.a local int array

int la[10];
//question 3.b copy values from ga to la

for(int i = 0; i<10; ++i)
  la[i] = ga[i];

//question 3.c  : print la

print_array(la, 10);

//question 3.d free-store array define p to int

int* p = new int[size];

//question 3.e copy values from argument array to free store array

for(int i = 0; i<10; ++i)
  p[i] = arg_arr[i];
//question 3.f print free store array

print_array(p,10);

//question 3.g deallocate free store

delete[] p;
}


//Question 4: call f with ga as its argument


int main()
{
g(); //1

//Question 4a: call f with ga as its argument

f(ga,sz_ga);

//question 4.b: define array if 10 elem (factorial values )

int aa[10];
aa[0] = 1;
for (int i = 1; i<10; ++i) {
  aa[i] = aa[i-1] * (i+1);
}

//question 4.c call f() with aa as its argument

f(aa,10);

return 0;
}
