// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 2
// Topic: Conditional Logic (if / else if / else) and Functions
// ==============================================================================
//
// TASK: Student Grade System

#include <iostream>
using namespace std;

char getGrade(double score) {
    if (score < 0 || score > 100) {
        return '\0'; // Return null character for out-of-range scores
    } else if (score >= 80) {
        return 'A';
    } else if (score >= 70) {
        return 'B';
    } else if (score >= 60) {
        return 'C';
    } else if (score >= 50) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    double score;
    cout << "Enter student score (0-100): ";
    
    if (cin >> score) {
        char grade = getGrade(score);
        if (grade == '\0') {
            cout << "Error: Score must be between 0 and 100." << endl;
        } else {
            cout << "Grade: " << grade << endl;
        }
    } else {
        cout << "Error: Score must be between 0 and 100." << endl;
    }

    return 0;
}
