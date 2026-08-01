// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 5
// Topic: Loops, Sequences, and Functions
// ==============================================================================
//
// TASK: Fibonacci Sequence Generator

#include <iostream>
using namespace std;

void generateFibonacci(int n) {
    if (n <= 0) return;
    
    long long first = 0, second = 1;
    for (int i = 0; i < n; i++) {
        cout << first << (i == n - 1 ? "" : " ");
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

bool isFibonacciNumber(long long num) {
    if (num < 0) return false;
    
    long long a = 0, b = 1;
    while (a < num) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return a == num;
}

int main() {
    int n;
    cout << "How many terms? ";
    if (cin >> n && n > 0) {
        cout << "Fibonacci sequence: ";
        generateFibonacci(n);
    } else {
        cout << "Error: Please enter a positive integer." << endl;
        return 0;
    }

    cout << endl;

    long long checkNum;
    cout << "Enter a number to check: ";
    if (cin >> checkNum) {
        if (isFibonacciNumber(checkNum)) {
            cout << checkNum << " is a Fibonacci number." << endl;
        } else {
            cout << checkNum << " is NOT a Fibonacci number." << endl;
        }
    } else {
        cout << "Error: Please enter a valid integer." << endl;
    }

    return 0;
}
