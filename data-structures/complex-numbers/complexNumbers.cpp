#include <iostream>
#include <sstream>
using namespace std;

class Complex {
    friend ostream& operator<<(ostream& out, const Complex& theComplex);
    friend istream& operator>>(istream& in, Complex& theComplex);
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);
public:
    Complex(double re = 0.0, double im = 0.0);
    double getReal(void) const;            // return real part
    double getImaginary(void) const;        // return imaginary part
    void setReal(double re);            // sets the real part
    void setImaginary(double im);        // sets the imaginary part
    void convertStringToComplex(const string& complexString);
private:
    double real;
    double imag;
};

Complex::Complex(double re, double im) :real(re), imag(im) {

}
double Complex::getReal(void) const {
    return real;
} // return real part
double Complex::getImaginary(void) const {
    return imag;
} // return imaginary part
void Complex::setReal(double re) {
    real = re;
} // sets the real part
void Complex::setImaginary(double im) {
    imag = im;
} // sets the imaginary part
void Complex::convertStringToComplex(const string& complexString) {

    stringstream ss(complexString);
    ss >> real >> imag;
}

//
ostream& operator<<(ostream& out, const Complex& theComplex) {

    out << theComplex.getReal() << " + " << theComplex.getImaginary() << "i" << endl;
    return out;
}
istream& operator>>(istream& in, Complex& theComplex) {

    in >> theComplex.real >> theComplex.imag;
    cin.ignore(256, '\n');
    return in;
}
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);

}
Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real - rhs.real, lhs.imag - rhs.imag);

}
Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real * rhs.real - lhs.imag * rhs.imag, lhs.imag * rhs.real + rhs.imag * lhs.real);
}
Complex operator/(const Complex& lhs, const Complex& rhs) {

    double mod = rhs.real * rhs.real - rhs.imag * rhs.imag;

    double realPart = (lhs.real * rhs.real + lhs.imag * rhs.imag) / mod;
    double imagPart = (-lhs.real * rhs.imag + rhs.real * lhs.imag) / mod;

    return Complex(realPart, imagPart);
}

int main(int argc, char** argv) {

    Complex c1;
    Complex c2;
    cout << "Enter first complex number: \n";
    cin >> c1;
    cout << "Enter second complex number: \n";
    cin >> c2;

    Complex add = c1 + c2;
    cout << "c1 + c2: ";
    cout << add;

    Complex sub = c1 - c2;
    cout << "c1 - c2: ";
    cout << sub;

    Complex mul = c1 * c2;
    cout << "c1 * c2: ";
    cout << mul;

    Complex div = c1 / c2;
    cout << "c1 / c2: ";
    cout << div;
}
