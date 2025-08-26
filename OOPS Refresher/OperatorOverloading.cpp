#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r, double i){
        this->real = r;
        this->imag = i;
    }

      // Overloading the '+' operator
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
   
};

int main()
{

    Complex c1(2.5, 3.0);
    Complex c2(1.0, 4.5);
    Complex c3 = c1 + c2;

    c3.display();

    return 0;
}