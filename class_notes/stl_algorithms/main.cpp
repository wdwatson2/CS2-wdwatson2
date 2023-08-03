#include <iostream> // Exercise23_09
#include <list>
#include <iterator>
using namespace std;

template <typename ForwardIterator, typename function>
void generate(ForwardIterator beg, ForwardIterator end, function gen);

template <typename ForwardIterator, typename function>
void generate(ForwardIterator beg, ForwardIterator end, function gen)
{
  for (ForwardIterator p = beg; p != end; p++)
    *p = gen();
}

template <typename ForwardIterator, typename size, typename function>
void generate_n(ForwardIterator beg, size n, function gen);

template <typename ForwardIterator, typename size, typename function>
void generate_n(ForwardIterator beg, size n, function gen)
{
  ForwardIterator p = beg;
  for (int i = 0; i < n; i++)
  {
    *p = gen();
    p++;
  }
}

int nextNum()
{
  static int n = 20;
  return n++;
}

int main()
{
  int values[6] = {0};
  cout << "Enter six integers: ";
  for (unsigned i = 0; i < 6; i++) 
    cin >> values[i];
  
  list<int> intList(values, values + 6);

  ostream_iterator<int> output(cout, " ");
  cout << "Initial contents, values: ";
  copy(values, values + 6, output);
  cout << "\nInitial contents, intList: ";
  copy(intList.begin(), intList.end(), output);

  generate(values + 2, values + 4, nextNum);
  generate_n(intList.begin(), 2, nextNum);

  cout << "\nAfter the generate function, values: ";
  copy(values, values + 6, output);
  cout << "\nAfter the generate_n function, intList: ";
  copy(intList.begin(), intList.end(), output);

  return 0;
}
