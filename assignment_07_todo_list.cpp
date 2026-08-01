// ==============================================================================
// PROGRAMMING FUNDAMENTALS - Assignment 7
// Topic: Console-Based To-Do List Application
// ==============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayMenu() {
    cout << "\n-------------------------\n";
    cout << "      TO-DO LIST MENU    \n";
    cout << "-------------------------\n";
    cout << "1. Add task\n";
    cout << "2. View tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Quit\n";
}

void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    cin.ignore();
    string task;
    getline(cin, task);
    if (!task.empty()) {
        tasks.push_back(task);
        cout << "Task added: \"" << task << "\"" << endl;
    } else {
        cout << "Task description cannot be empty." << endl;
    }
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
    } else {
        cout << "Your Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". " << tasks[i] << endl;
        }
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int taskNum;
    if (cin >> taskNum) {
        if (taskNum >= 1 && static_cast<size_t>(taskNum) <= tasks.size()) {
            string removed = tasks[taskNum - 1];
            tasks.erase(tasks.begin() + (taskNum - 1));
            cout << "Task \"" << removed << "\" has been removed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    } else {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a valid number." << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        if (cin >> choice) {
            if (choice == 1) {
                addTask(tasks);
            } else if (choice == 2) {
                viewTasks(tasks);
            } else if (choice == 3) {
                deleteTask(tasks);
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
