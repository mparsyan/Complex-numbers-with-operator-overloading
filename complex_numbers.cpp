#include <iostream>

class Complex
{
private:
    float real;
    float imag;
public:
    
    // Ցանկալի է նաև ունենալ պարամետրերով կառուցիչ
    Complex()
    : real(0)
    , imag(0)
    {}

    void input()
    {
        std::cin >> real;
        std::cin >> imag;
    }

    void output()
    {
        // Էս ֆունկցիան լավ է մտածված
        if (imag < 0)
        {
            std::cout << "The complex number is: " << real << imag << "i\n";
        }
        else
        {
            std::cout << "The complex number is: " << real << "+" << imag << "i\n";
        }
    }
    
    Complex operator + (const Complex& op)
    {
        Complex temp;
        this->real = this->real + op.real;
        this->imag = this->imag + op.imag;
        
        // Կարելի էր 42,43 տողերի փոխարեն copy constructor կանչել
        // Ափսոս copy constructor-ը գրած չի
        temp.real = this->real;
        temp.imag = this->imag;
        return temp;
    }

    // Քանի որ ++ը main֊ում օգտագործել ես prefix-ով 
    // Այն պետք է վերադարձնի Complex&
    void operator ++ ()
    {
        this->real++;
        this->imag++;
    }

    // Պետք է վերադարձնի Complex&
    void operator = (const Complex& op)
    {
        this->real = op.real;
        this->imag = op.imag;
    }

    bool operator == (const Complex& op)
    {
        return (real == op.real && imag == op.imag);
    }

    // Պետք է վերադարձնի Complex&
    void operator += (const Complex& op)
    {
        this->real = this->real + op.real;
        this->imag = this->imag + op.imag;
    }
};



int main() 
{   
    std::cout << "\"Operator +\"\n";
    Complex c1, c2, res;
    std::cout << "Enter the first complex number with its real and imaginary parts: ";
    c1.input();
    std::cout << "Enter the second complex number with its real and imaginary parts: ";
    c2.input();
    res = c1 + c2;
    res.output();

    std::cout << "\n\"Operator ++\"\n";
    Complex c3;
    std::cout << "Enter the first complex number with its real and imaginary parts: ";
    c3.input();
    ++c3;
    c3.output();

    std::cout << "\n\"Operator =\"\n";
    Complex c5, c6;
    std::cout << "Enter the first complex number with its real and imaginary parts: ";
    c5.input();
    std::cout << "Enter the second complex number with its real and imaginary parts: ";
    c6.input();
    c6 = c5;
    c6.output();

    std::cout << "\n\"Operator ==\"\n";
    Complex c7, c8;
    std::cout << "Enter the first complex number with its real and imaginary parts: ";
    c7.input();
    std::cout << "Enter the second complex number with its real and imaginary parts: ";
    c8.input();
    if (c7 == c8)
    {
        std::cout << "first number = second number\n";
    }
    else
    {
        std::cout << "first number != second number\n";
    }

    std::cout << "\n\"Operator +=\"\n";
    Complex c9, c10;
    std::cout << "Enter the first complex number with its real and imaginary parts: ";
    c9.input();
    std::cout << "Enter the second complex number with its real and imaginary parts: ";
    c10.input();
    c9 += c10;
    c9.output();

    return 0;
}
