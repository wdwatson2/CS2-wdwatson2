/*
overloaded function - member function that 




*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    string name;

    getline(cin, name, '\n');

    cout << name << endl;

    return 0;
}


/*
2/6
pointers and implementation of pointers in classes





*/

//debugging code. you can turn on or off without goin back and uncommenting everything

#define NDEBUG
int main(){

    int b = 0;
    a(b);
#ifdef DEBUG
    cout << "blah" ;
    cout << "blah" << b;
#endif
    //remaining code

}

//using assert to make sure memory is allocated

int main(){
    char *p = new char[5];
    assert(p != NULL); //p will point to NULL if memory was not created correctly
    //remaining code
}

//valgrind - sudo apt install valgrind - tells us where memory leak is