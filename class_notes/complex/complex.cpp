// Search for "WRITE YOUR CODE" to complete this program
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class Complex
{
public:
  Complex()
  {
    a = 0;
    b = 0;
  }
  Complex(double a, double b)
  {
    this->a = a;
    this->b = b;
  }
  Complex(double a)
  {
    this->a = a;
    b = 0;
  }
  double getRealPart() const;
  double getImaginaryPart() const;
  Complex add(const Complex& secondComplex) const;
  Complex subtract(const Complex& secondComplex) const;
  Complex multiply(const Complex& secondComplex) const;
  Complex divide(const Complex& secondComplex) const;
  double abs() const;
  string toString() const;

  Complex& operator+=(Complex& secondComplex);
  Complex& operator-=(Complex& secondComplex);
  Complex& operator*=(Complex& secondComplex);
  Complex& operator/=(Complex& secondComplex);

  double& operator[](const int&  index);

  Complex& operator++(); // Prefix ++
  Complex& operator--(); // Prefix --

  Complex operator++(int dummy); // Postfix ++
  Complex operator--(int dummy); // Postfix --

  Complex operator+(); // Unary +  
  Complex operator-(); // Unary - 

  friend ostream& operator<<(ostream& stream, const Complex& complex);
  friend istream& operator >> (istream& stream, Complex& complex);

private:
  double a;
  double b;
};

// Non-member operator functions
Complex operator+(const Complex& c1, const Complex& c2)
{
    return c1.add(c2);
}
Complex operator-(const Complex& c1, const Complex& c2)
{
    return c1.subtract(c2);
}
Complex operator*(const Complex& c1, const Complex& c2)
{
    return c1.multiply(c2);
}
Complex operator/(const Complex& c1, const Complex& c2)
{
    return c1.divide(c2);
}

bool operator<(const Complex& c1, const Complex& c2)
{
    if(c1.abs() < c2.abs())
        return true;
    else    
        return false;
}
bool operator<=(const Complex& c1, const Complex& c2)
{
    if(c1.abs() <= c2.abs())
        return true;
    else    
        return false;
}
bool operator==(const Complex& c1, const Complex& c2)
{
    if(c1.abs() == c2.abs())
        return true;
    else    
        return false;
}
bool operator!=(const Complex& c1, const Complex& c2)
{
    if(c1.abs() != c2.abs())
        return true;
    else    
        return false;
}
bool operator>(const Complex& c1, const Complex& c2)
{
    if(c1.abs() > c2.abs())
        return true;
    else    
        return false;
}
bool operator>=(const Complex& c1, const Complex& c2)
{
    if(c1.abs() >= c2.abs())
        return true;
    else    
        return false;
}


// WRITE YOUR CODE to implement the Complex class here
ostream& operator<<(ostream& stream, const Complex& complex)
{
    stream << complex.toString();
    return stream;
}
istream& operator >> (istream& stream, Complex& complex)
{
    stream >> complex.a >> complex.b;
    return stream;
}


double Complex::getRealPart() const
{
    return a;
}
double Complex::getImaginaryPart() const
{
    return b;
}

Complex Complex::add(const Complex& secondComplex) const
{
    Complex added((a+secondComplex.getRealPart()), (b+secondComplex.getImaginaryPart()));
    return added;
}
Complex Complex::subtract(const Complex& secondComplex) const
{
    Complex subtracted((a-secondComplex.getRealPart()), (b-secondComplex.getImaginaryPart()));
    return subtracted;
}
Complex Complex::multiply(const Complex& secondComplex) const
{
    double c;
    double d;
    c = secondComplex.getRealPart();
    d = secondComplex.getImaginaryPart();

    Complex multiplied((a*c - b*d), (b*c + a*d));
    return multiplied;
}
Complex Complex::divide(const Complex& secondComplex) const
{
    double c;
    double d;
    c = secondComplex.getRealPart();
    d = secondComplex.getImaginaryPart();
    Complex divided(((a*c + b*d)/(pow(c, 2) + pow(d, 2))), ((b*c - a*d)/(pow(c, 2) + pow(d, 2))));
    return divided;
}

double Complex::abs() const
{
    return (sqrt(pow(a, 2) + pow(b, 2)));
}
string Complex::toString() const
{
    if (b > 0)
      return (to_string(a) + " + " + to_string(b) + "i");
    else if (b < 0)
      return (to_string(a) + " - " + to_string(std::abs(b)) + "i");
    else    
        return (to_string(a));
}

Complex& Complex::operator+=(Complex& secondComplex)
{
    *this = add(secondComplex);
    return *this;
}
Complex& Complex::operator-=(Complex& secondComplex)
{
    *this = subtract(secondComplex);
    return *this;
}
Complex& Complex::operator*=(Complex& secondComplex)
{
    *this = multiply(secondComplex);
    return *this;
}
Complex& Complex::operator/=(Complex& secondComplex)
{
    *this = divide(secondComplex);
    return *this;
}

double& Complex::operator[](const int& index)
{
  if(index == 0)
    return this->a;
  else
    return this->b;
}

Complex& Complex::operator++() // Prefix ++
{
    a++;
    return *this;
}
Complex& Complex::operator--() // Prefix --
{
  a--;
  return *this;
}
Complex Complex::operator++(int dummy) // Postfix ++
{
    Complex temp(a, b);
    a++;
    return temp;
}
Complex Complex::operator--(int dummy) // Postfix --
{
    Complex temp(a, b);
    a--;
    return temp;
}

Complex Complex::operator+() // Unary +  
{
    return *this;
}
Complex Complex::operator-() // Unary - 
{
    return Complex(-a, -b);
}



int main()
{
  Complex number1;
  cout << "Enter the first complex number: ";
  cin >> number1;

  Complex number2;
  cout << "Enter the second complex number: ";
  cin >> number2;

  cout << "(" << number1 << ")" << " + " << "(" << number2
    << ") = " << (number1 + number2) << endl;
  cout << "(" << number1 << ")" << " - " << "(" << number2
    << ") = " << (number1 - number2) << endl;
  cout << "(" << number1 << ")" << " * " << "(" << number2
    << ") = " << (number1 * number2) << endl;
  cout << "(" << number1 << ")" << " / " << "(" << number2
    << ") = " << (number1 / number2) << endl;
  cout << "|" << number1 << "|" << " = " << number1.abs() << endl;
  cout << "|" << number2 << "|" << " = " << number2.abs() << endl;

  number1[0] = 3.4;
  cout << number1++ << endl;
  cout << ++number2 << endl;
  cout << (3 + number2) << endl;
  cout << (number2 += number1) << endl;
  cout << (number2 *= number1) << endl;

  number1 = number2;
  cout << number1 << endl;
  cout << number2 << endl;

  cout << (number1 < number2) << endl;
  cout << (number1 <= number2) << endl;
  cout << (number1 == number2) << endl;
  cout << (number1 != number2) << endl;
  cout << (number1 > number2) << endl;
  cout << (number1 >= number2) << endl;

  return 0;
}
