#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
using namespace std;

class HexFormatException : public runtime_error
{
public:
  HexFormatException(char ch) : runtime_error("Hex number format error")
  {
    this->ch = ch;
  }

  char getCh()
  {
    return ch;
  }

private:
  char ch;
};

// The function returns an int for a hex digit. 
// Throws HexFormatException(ch) if the hex character is invalid
int convertHexToDec(char ch)
{
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
    throw HexFormatException(ch);
}

int hex2Dec(const string& hexString)
{
  int value = convertHexToDec(hexString[0]);
  for (int i = 1; i < hexString.size(); i++)
  {
    value = value * 16 + convertHexToDec(toupper(hexString[i]));
  }

  return value;
}

int main()
{
  string hexString;

  try
  {
    getline(cin, hexString);

    cout << hex2Dec(hexString) << endl;
  }
  catch (runtime_error& ex)
  {
    cout << "Not a hex number" << endl;
  }

  return 0;
}