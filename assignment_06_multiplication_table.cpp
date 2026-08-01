// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 6
// Topic: Loops and Functions
// ==============================================================================
//
// TASK: Multiplication Table Generator

#include <iostream>
using namespace std;

void generateSingleTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

void generateTablesUpToN(int n) {
    for (int i = 1; i <= n; i++) {
        generateSingleTable(i);
        if (i < n) {
            cout << "-------------------" << endl;
        }
    }
}

int main() {
    int num;
    cout << "Enter a number for a single multiplication table: ";
    if (cin >> num && num > 0) {
        generateSingleTable(num);
    } else {
        cout << "Error: Please enter a positive integer." << endl;
        return 0;
    }

    cout << "\n==============================\n" << endl;

    int n;
    cout << "Enter N to generate all tables from 1 to N: ";
    if (cin >> n && n > 0) {
        generateTablesUpToN(n);
    } else {
        cout << "Error: Please enter a positive integer." << endl;
    }

    return 0;
}
