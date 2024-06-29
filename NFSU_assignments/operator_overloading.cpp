#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<string>

using namespace std;

// Class Fraction represents a fraction with a numerator and denominator
class Fraction {
    int num, den;
public:
    // Constructor to initialize the fraction with default values of 1/1
    Fraction(int n = 1, int d = 1) : num(n), den(d) {}

    // Input function to get the numerator and denominator from the user
    void input() {
        cout << "Enter the numerator and denominator of the fraction ";
        cin >> num >> den;
        if (den == 0) {
            cout << "The denominator entered is zero..." << endl;
            exit(0);
        }
    }

    // Overload the + operator to add two fractions
    Fraction operator+(Fraction f0) {
        int new_num = num * f0.den + den * f0.num;
        int new_den = den * f0.den;
        int gcd0 = __gcd(new_num, new_den);
        new_num /= gcd0;
        new_den /= gcd0;
        return Fraction(new_num, new_den);
    }

    // Overload the - operator to subtract two fractions
    Fraction operator-(Fraction f0) {
        int new_num = num * f0.den - den * f0.num;
        int new_den = den * f0.den;
        int gcd0 = __gcd(new_num, new_den);
        new_num /= gcd0;
        new_den /= gcd0;
        return Fraction(new_num, new_den);
    }

    // Overload the * operator to multiply two fractions
    Fraction operator*(Fraction f0) {
        int new_num = num * f0.num;
        int new_den = den * f0.den;
        int gcd0 = __gcd(new_num, new_den);
        new_num /= gcd0;
        new_den /= gcd0;
        return Fraction(new_num, new_den);
    }

    // Overload the / operator to divide two fractions
    Fraction operator/(Fraction f0) {
        int new_num = num * f0.den;
        int new_den = den * f0.num;
        if (new_den == 0) {
            cout << "The denominator is encountered 0...." << endl;
            exit(0);
        }
        int gcd0 = __gcd(new_num, new_den);
        new_num /= gcd0;
        new_den /= gcd0;
        return Fraction(new_num, new_den);
    }

    // Overload the << operator to print the fraction
    friend ostream& operator<<(ostream& os, const Fraction& ob) {
        os << ob.num << "/" << ob.den << endl;
        return os;
    }
};

int main() {
    Fraction f1, f2, opt;
    int choice;
    cout << "--------------------------------------------------" << endl;
    cout << "| INATOR IS ZERO THEN THE PROGRAM WILL TERMINATE |" << endl;
    cout << "--------------------------------------------------" << endl;
    do {
        cout << "------------------------------" << endl;
        cout << "| Time to enter the fraction |" << endl;
        cout << "------------------------------" << endl;
        f1.input();
        f2.input();
        cout << "Enter your choice: " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                // Add two fractions
                opt = f1 + f2;
                cout << "The sum of the two fractions is ";
                cout << opt << endl;
                break;
            case 2:
                // Subtract two fractions
                opt = f1 - f2;
                cout << "The difference of the two fractions is ";
                cout << opt << endl;
                break;
            case 3:
                // Multiply two fractions
                opt = f1 * f2;
                cout << "The product of the two fractions is ";
                cout << opt << endl;
                break;
            case 4:
                // Divide two fractions
                opt = f1 / f2;
                cout << "The quotient of the two fractions is ";
                cout << opt << endl;
                break;
            case 0:
                cout << "Thanks for using...TERMINATING" << endl;
        }
    } while (choice!= 0);
    return 0;
}