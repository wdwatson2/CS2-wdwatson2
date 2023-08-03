//
//  main.cpp
//  cerr_redirect
//
//  Created by Antoun, Sherine on 10/12/22.
//

#include <fstream>
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    fstream file, file1;
    file.open("cout.txt", ios::out);
    file1.open("cerr.txt", ios::out);
    string line;
 
    //streambuffers of  cout
    streambuf* stream_buffer_cout = cout.rdbuf();
    streambuf* stream_buffer_cerr = cerr.rdbuf();
    streambuf* stream_buffer_cin = cin.rdbuf();
 
    // Get the streambuffer of the file
    streambuf* stream_buffer_file = file.rdbuf();
    streambuf* stream_buffer_file1 = file1.rdbuf();
    cerr.rdbuf(stream_buffer_file1);
 
    cerr << "This 1st line written to file. cerr" << endl;
    cerr << "This 2nd line written to file" << endl;
    cerr << "This 3rd line written to file" << endl;
    
    // Redirect cout to file
    cout.rdbuf(stream_buffer_file);
 
    cout << "This 1st line written to file" << endl;
    cout << "This 2nd line written to file" << endl;
    cout << "This 3rd line written to file" << endl;
 
    // Redirect cout back to screen
    cout.rdbuf(stream_buffer_cout);
    cerr.rdbuf(stream_buffer_cerr);
    cout << "This line is written to screen" << endl;
 
    file.close();
    return 0;
}
