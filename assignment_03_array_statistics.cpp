// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 3
// Topic: Arrays, Loops, and Functions
// ==============================================================================
//
// TASK: Array Statistics Calculator

#include <iostream>
using namespace std;

double calculateSum(const double arr[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

double calculateAverage(const double arr[], int size) {
    if (size == 0) return 0;
    return calculateSum(arr, size) / size;
}

double findMaximum(const double arr[], int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double findMinimum(const double arr[], int size) {
    double minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int count;
    cout << "How many numbers? ";
    
    if (!(cin >> count) || count <= 0) {
        cout << "Please enter a number greater than 0." << endl;
        return 0;
    }

    double numbers[100]; // Array for input values

    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, count) << endl;
    cout << "Average: " << calculateAverage(numbers, count) << endl;
    cout << "Maximum: " << findMaximum(numbers, count) << endl;
    cout << "Minimum: " << findMinimum(numbers, count) << endl;

    return 0;
}
