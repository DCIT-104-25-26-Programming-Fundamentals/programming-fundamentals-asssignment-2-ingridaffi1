// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 1
// Topic: Conditional Logic, Loops, and Functions
// ==============================================================================
//
// TASK: Prime Number Checker

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a number: ";
    if (cin >> num) {
        if (isPrime(num)) {
            cout << num << " is a prime number." << endl;
        } else {
            cout << num << " is NOT a prime number." << endl;
        }
    } else {
        cout << "Please enter a valid integer." << endl;
    }
    return 0;
}
