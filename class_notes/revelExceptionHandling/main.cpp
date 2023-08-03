#include<iostream>
#include<stdexcept>
#include<string>
#include<cctype>
using namespace std;

int hex2Dec(const string& hexString);
int convertHexToDec(char ch);

int hex2Dec(const string& hexString) 
{
  int value = 0; 
  for (unsigned int i = 0; i < hexString.size(); i++)
     value = value * 16 + convertHexToDec(toupper(hexString[i]));
  return value;
}

// The function returns an int for a hex digit. 
// Throws an invalid_argument("Not a hex number") if the hex character is invalid
int convertHexToDec(char ch)
{ 
  // Write your code here
  if(ch == '0')
    return 0;
  else if(ch == '1')
    return 1;
  else if(ch == '2')
    return 2;
  else if(ch == '3')
    return 3;
  else if(ch == '4')
    return 4;
  else if(ch == '5')
    return 5;
  else if(ch == '6')
    return 6;
  else if(ch == '7')
    return 7;
  else if(ch == '8')
    return 8;
  else if(ch == '9')
    return 9;
  else if(ch == 'A')
    return 10;
  else if(ch == 'B')
    return 11;
  else if(ch == 'C')
    return 12;
  else if(ch == 'D')
    return 13;
  else if(ch == 'E')
    return 14;
  else if(ch == 'F')
    return 15;
  else
    throw invalid_argument("Not a hex number");
}

int main()
{
    /*
    Write a test program that prompts the user to enter a hex number as a string and display the number 
    in decimal. If the function throws an exception, display "Not a hex number". You need to write the 
    code to catch the exception in the main function.
    */
  string hexString;
	
  try
  {
    cout << "Enter a hex number: ";
    getline(cin, hexString);

    cout << hex2Dec(hexString) << endl;
  }
  catch(invalid_argument& ex)
  {
    cout << "Not a hex number" << endl;
  }

  return 0;
}