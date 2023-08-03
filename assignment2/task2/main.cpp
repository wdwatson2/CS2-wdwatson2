#include "listType.h"
#include "orderedListType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    listType<int> a(5); 


    cout << "Creating an orderedListType object of size 5 ints" << endl;
    orderedListType<int> ordered(5);

    cout << "inserting 4 ints out of order and print automatically sorts them before printing to console" << endl;
    ordered.insert(1);
    ordered.insert(2);
    ordered.insert(3);
    ordered.insert(-9);

    ordered.print();

    cout << "removing item 1 and calling print and showLength" << endl;
    ordered.deleteItem(1);

    ordered.print();
    cout << "Length: " << ordered.showLength() << endl;


    return 0;
}