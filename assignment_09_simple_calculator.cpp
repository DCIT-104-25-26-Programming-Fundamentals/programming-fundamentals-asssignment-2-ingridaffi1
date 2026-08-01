// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 9
// Topic: Functions, Control Flow, and Exception Handling
// ==============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void displayMenu() {
    cout << "\n==========================\n";
    cout << "    SIMPLE CALCULATOR    \n";
    cout << "==========================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

void divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        cout << "Result: " << fixed << setprecision(2) << (a / b) << endl;
    }
}

void modulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
    } else {
        cout << "Result: " << (a % b) << endl;
    }
}

double exponentiate(double base, double exp) {
    return pow(base, exp);
}

int main() {
    int choice = 0;

    while (choice != 7) {
        displayMenu();
        cout << "Select an operation (1-7): ";
        if (cin >> choice) {
            if (choice == 7) {
                cout << "Goodbye!" << endl;
                break;
            }

            if (choice >= 1 && choice <= 6) {
                double num1, num2;
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;

                if (choice == 1) {
                    cout << "Result: " << fixed << setprecision(2) << add(num1, num2) << endl;
                } else if (choice == 2) {
                    cout << "Result: " << fixed << setprecision(2) << subtract(num1, num2) << endl;
                } else if (choice == 3) {
                    cout << "Result: " << fixed << setprecision(2) << multiply(num1, num2) << endl;
                } else if (choice == 4) {
                    divide(num1, num2);
                } else if (choice == 5) {
                    modulus(static_cast<int>(num1), static_cast<int>(num2));
                } else if (choice == 6) {
                    cout << "Result: " << fixed << setprecision(2) << exponentiate(num1, num2) << endl;
                }
            } else {
                cout << "Invalid choice. Please select an operation between 1 and 7." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
        }
    }

    return 0;
}
