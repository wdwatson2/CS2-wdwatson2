#include "listType.h"
#include "unorderedListType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    cout << "Testing ListType" << endl;

    listType<int> a(5); 

    cout << "adding three ints and printing" << endl;

    a.insert(1);
    a.insert(2);
    a.insert(3);

    a.print();

    cout << "deleting element 2 and printing" << endl;

    a.deleteItem(2);

    a.print();

    cout << "adding an element and printing" << endl;

    a.insert(5);

    a.print();

    cout << "adding 3 elements beyond and printing" << endl;

    a.insert(6);
    a.insert(3);
    a.insert(100);

    a.print();

    cout << "sorting elements and printing" << endl;

    a.sort();

    a.print();

    cout << "Reading in nums from file" << endl;
    
    ifstream ins("sampleNums.txt");

    listType<int> newguy(5);

    newguy.setLength(5);

    newguy.getList(ins);

    newguy.print();


    /*
    now test unorderedListType
    */

    unorderedListType<int> unordered(5);

    cout << endl << "Testing unorderedListType" << endl;

    unordered.insert(1);
    unordered.insert(4);
    unordered.insert(3);
    unordered.insert(2);

    cout << "Sort should no longer work" << endl;
    cout << "before: " << endl;
    unordered.print();
    cout << "after: " << endl;
    unordered.sort();
    unordered.print();

    cout << "Searching for item 2 in list" << endl;
    unordered.search(2);
    cout << "searching for item 5 not in list" << endl;
    unordered.search(5);

    return 0;
}