// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 8
// Topic: Structs, Vectors, Loops, and Functions
// ==============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

void displayMenu() {
    cout << "\n----------------------------------\n";
    cout << "   STUDENT RECORD SYSTEM MENU    \n";
    cout << "----------------------------------\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
}

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    if (!(cin >> s.id)) {
        cout << "Invalid ID entered." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    int numScores;
    cout << "How many scores? ";
    if (cin >> numScores && numScores > 0) {
        for (int i = 1; i <= numScores; ++i) {
            double score;
            cout << "Enter score " << i << ": ";
            cin >> score;
            s.scores.push_back(score);
        }
        students.push_back(s);
        cout << "Student \"" << s.name << "\" added successfully." << endl;
    } else {
        cout << "Invalid number of scores." << endl;
    }
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\n---------------------------------------------------------\n";
    cout << left << setw(15) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "---------------------------------------------------------\n";

    for (const auto& s : students) {
        string scoresStr = "";
        for (size_t i = 0; i < s.scores.size(); ++i) {
            scoresStr += to_string(static_cast<int>(s.scores[i]));
            if (i < s.scores.size() - 1) scoresStr += ", ";
        }

        cout << left << setw(15) << s.name 
             << setw(12) << s.id 
             << setw(20) << scoresStr 
             << fixed << setprecision(2) << calculateAverage(s.scores) << endl;
    }
}

void calculateSpecificAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    if (cin >> searchId) {
        for (const auto& s : students) {
            if (s.id == searchId) {
                cout << s.name << "'s average score: " 
                     << fixed << setprecision(2) << calculateAverage(s.scores) << endl;
                return;
            }
        }
        cout << "Error: Student ID not found." << endl;
    } else {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid student ID." << endl;
    }
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        if (cin >> choice) {
            if (choice == 1) {
                addStudent(students);
            } else if (choice == 2) {
                displayAllStudents(students);
            } else if (choice == 3) {
                calculateSpecificAverage(students);
            } else if (choice == 4) {
                cout << "Goodbye!" << endl;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}
