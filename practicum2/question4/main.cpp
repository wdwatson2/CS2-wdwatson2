#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char* strStr(const char*, const char*); //had to rename because strstr already exists
//function returns the address of where s1 begins in s2
//returns null if string is not found


int main(){

    cout << strStr("nothing","baby got back") << endl;
    return 0;
}

char* strStr(const char *s1, const char *s2){

    char* location = NULL;
    int counter = 0;

    while(*s2 != '\0'){      //while the current char is not the end char

        if(*s1 == *s2){ 

            if(counter == 0){   //beginning of a possible match
                location = (char*) s2;  //set location to the beginning
            }

            counter++; //increment counter to know what char s1Copy is pointing too.
            s1++;    //increment both char* to point to their next char
            s2++;

            if(*s1 == '\0')
                return location; //full match so return the location of where s1 starts

        }
        else{
            s2++;   //increment s2 to look at the next char
            s1-=counter;   //make s1Copy reset to pointing at the beginning
            counter = 0;   //reseting counter
            location = NULL;  //reseting location
        }
    }

    return location;  //Null at this point, string was not found
}
