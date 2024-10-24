#include <iostream>
#include <fstream>
#include <string>

#define E endl;

using namespace std;

struct Student {
    string firstName;
    string lastName;
    int grade;
};

int main() {
    // Predefined students data
    Student students[15] = {
        {"John", "Doe", 85},
        {"Jane", "Smith", 92},
        {"Michael", "Johnson", 78},
        {"Emily", "Davis", 88},
        {"Chris", "Wilson", 60},
        {"Jessica", "Taylor", 95},
        {"David", "Brown", 72},
        {"Sophia", "Anderson", 84},
        {"Daniel", "Thomas", 91},
        {"Emma", "White", 76},
        {"James", "Harris", 89},
        {"Olivia", "Martin", 81},
        {"Liam", "Thompson", 65},
        {"Isabella", "Garcia", 70},
        {"Noah", "Martinez", 82}
    };

    ofstream file1("students.txt");
    if (!file1) {
        cout << "File students.txt could not be created." << E
        return 1;
    }

    int totalStudents = 15;
    int totalGrades = 0;
    int threshold;


    for (int i = 0; i < totalStudents; ++i) {
        file1 << students[i].lastName << " " << students[i].firstName << " " << students[i].grade << E
        totalGrades += students[i].grade;
    }

    file1.close();


    ifstream file1_in("students.txt");
    if (!file1_in) {
        cout << "File students.txt does not exist." << E
        return 1;
    }

    ofstream file2("filtered_students.txt");
    if (!file2) {
        cout << "File filtered_students.txt could not be created." << E
        return 1;
    }

    cout << "Enter threshold grade: ";
    cin >> threshold;

    file2 << "Students with grades less than " << threshold << ":\n";
    for (int i = 0; i < totalStudents; ++i) {
        if (students[i].grade < threshold) {
            file2 << students[i].lastName << " " << students[i].firstName << " - " << students[i].grade << E
        }
    }

    double averageGrade = static_cast<double>(totalGrades) / totalStudents;
    file2 << "Average grade for the group: " << averageGrade << E

    file1_in.close();
    file2.close();

    cout << "Processed data written to file filtered_students.txt." << E

    return 0;
}
