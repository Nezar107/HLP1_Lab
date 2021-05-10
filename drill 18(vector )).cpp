#include "../../std_lib_facilities.h"


// question 1: define global vector with 10 ints ( 1 , 2, 4, 8)

vector<int> gv; //global vector
//initialized:
void gv_init()
{
  for(int i = 0; i < 10; ++i)
    gv.push_back(pow(2,i));
}

void print_vector(vector<int> v)
{
  for(int i = 0; i<v.size(); ++i)
    cout << v[i] << ' ';
  cout << endl;
}

//question 2 : define function f() taking vector<int> argument

int f(vector<int> arg_vec)
{

//question 3.a define local vector<int> lv

vector<int> lv(arg_vec.size()); //local vector

//question 3.b copy gv to lv

lv = gv; //copy values

// question 3.c print lv

print_vector(lv);

//question 3.d define local vector lv2 (intialize it to be a copy vector

vector<int> lv2;
//initialize:
lv2 = arg_vec;

//question 3.e print lv2
print_vector(lv2);
}



int main()
{
gv_init(); //1

//question 4.a call f() with gv as its arguments

f(gv);

//question 4.b define vector<int>vv as factorial values

vector<int> vv;
//initialize
vv.push_back(1);
for(int i = 1; i < 10; ++i)
  vv.push_back(vv[i-1] * (i+1));

//questions 4.c call f() with vv as its argument

f(vv);


return 0;
}

