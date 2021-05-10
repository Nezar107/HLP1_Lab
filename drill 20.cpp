#include "../../std_lib_facilities.h"


//question 6: use copy() operation with template

template<typename Iter1, typename Iter2>
//f1 - begin copying from where
//e1 - end copying where
//f2 - where to put copy
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  while(f1!=e1)
  {
    *f2 = *f1;
    ++f1;
    ++f2;
  }
  return f2;
}


//template function
template<typename C> void printout(const C& c)
{
  for(const auto& x : c)
    cout << x << ' ';
  cout << endl;
}


int main()
{

//question 1 : define array of 10 elems


  const int size = 10;

  array<int,size> a;
  for(int i = 0; i < size; ++i)
    a[i] = i;
  cout << "Array:" << endl;
  printout(a);


//question 2: define vector<int> with those 10 elements

  vector<int> v;
  for(int i = 0; i < size; ++i)
    v.push_back(i);
  cout << "Vector:" << endl;
  printout(v);


//question 3: define list<int> with those 10 elements

  list<int> l;
  for(int i = 0; i < size; ++i)
    l.push_back(i);
  cout << "List:" << endl;
  printout(l);


//question 4: copy all 3 array vector and list and initialize


  cout << "\nQuestion - 4" << endl;

  array<int, size> a2 = a;
  cout << "Array copy:" << endl;
  printout(a2);

  vector<int> v2 = v;
  cout << "Vector copy:" << endl;
  printout(v2);

  list<int> l2 = l;
  cout << "List copy:" << endl;
  printout(l2);


//question 5: increase value of array by 2, vector 3 and list 5


  cout << "\nQuestion - 5" << endl;

  for(array<int, size>::iterator p = a.begin(); p!=a.end(); ++p)
    *p += 2;
  cout << "Array: (+2)" << endl;
  printout(a);

  for(vector<int>::iterator p = v.begin(); p!=v.end(); ++p)
    *p += 3;
  cout << "Vector (+3):" << endl;
  printout(v);

  for(list<int>::iterator p = l.begin(); p!=l.end(); ++p)
    *p += 5;
  cout << "List (+5):" << endl;
  printout(l);


//question 7: copy() array into vector and list into array
  cout << "\nQuestion - 7" << endl;

  vector<int>::iterator v_it = my_copy(a.begin(), a.end(), v.begin());
  cout << "Vector copied from array: " << endl;
  printout(v);

  array<int,size>::iterator a_it = copy(l.begin(),l.end(),a.begin());
  cout << "Array copied from list: " << endl;
  printout(a);


//question 8: use find() to see if list contains 27 and if vector contain 3

  cout << "\nQuestion - 8" << endl;

  v_it = find(v.begin(), v.end(), 3);
  if(v_it != v.end())
    cout << "Vector contains the value 3 and its index is " << v_it-v.begin() << endl;
  else
    cout << "3 was not found in the vector." << endl;

  list<int>::iterator l_it = find(l.begin(), l.end(), 27);
  if (l_it != l.end())
  {
    int index = 0;
    for(list<int>::iterator p = l.begin();  p!= l_it; ++p)
      ++index;
    cout << "List contains the value 27 and its position is " << index << endl;
  }
  else
    cout << "27 was not found in the list." << endl;


  return 0;
}
