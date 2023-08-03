#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

void reverse(char* src);   //prints the contents of the src buffer in reverse

int main(){

    reverse("The cat");

    return 0;
}

void reverse(char* src){

    int length = strlen(src);
    for(int i = 0; i < length+1; i++){
        cout << *((src + length) - i);
    }
    cout << endl;

}