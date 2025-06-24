#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    double grade;
    double credit;
};

int main() {
    int numCourses;
    cout << "Enter number of courses this semester: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    double totalGradePoints = 0.0, totalCredits = 0.0;

    // Input for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " name: ";
        cin >> ws; // To consume any leading whitespace
        getline(cin, courses[i].name);

        cout << "Enter grade (on 4.0 scale): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].credit;

        totalGradePoints += courses[i].grade * courses[i].credit;
        totalCredits += courses[i].credit;
    }

    // Calculate GPA
    double semesterGPA = totalGradePoints / totalCredits;

    // Display course details
    cout << fixed << setprecision(2);
    cout << "\n--- Course Grades ---\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course: " << courses[i].name
             << " | Grade: " << courses[i].grade
             << " | Credit Hours: " << courses[i].credit << endl;
    }

    cout << "\nSemester GPA: " << semesterGPA << endl;

    // Optional: CGPA Calculation
    char more;
    cout << "\nDo you want to calculate overall CGPA? (y/n): ";
    cin >> more;

    if (tolower(more) == 'y') {
        double previousCGPA, previousCredits;
        cout << "Enter previous CGPA: ";
        cin >> previousCGPA;
        cout << "Enter total previous credit hours: ";
        cin >> previousCredits;

        double overallCGPA = (previousCGPA * previousCredits + totalGradePoints) /
                             (previousCredits + totalCredits);

        cout << "Overall CGPA: " << overallCGPA << endl;
    }

    return 0;
}
