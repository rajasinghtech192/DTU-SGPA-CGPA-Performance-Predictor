#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int gradePoint(string grade)
{
    if (grade == "O") return 10;
    if (grade == "A+") return 9;
    if (grade == "A") return 8;
    if (grade == "B+") return 7;
    if (grade == "B") return 6;
    if (grade == "C") return 5;
    if (grade == "P") return 4;
    return 0; // F
}

int main()
{
    int subjects;
    float totalCredits = 0;
    float weightedPoints = 0;

    cout << "===== SGPA & Percentage Calculator =====\n";
    cout << "Enter Number of Subjects: ";
    cin >> subjects;

    for (int i = 1; i <= subjects; i++)
    {
        string grade;
        float credits;

        cout << "\nSubject " << i << endl;

        cout << "Enter Grade (O, A+, A, B+, B, C, P, F): ";
        cin >> grade;

        cout << "Enter Credits: ";
        cin >> credits;

        weightedPoints += gradePoint(grade) * credits;
        totalCredits += credits;
    }

    float sgpa = weightedPoints / totalCredits;

    // Percentage Formula
    float percentage = (sgpa - 0.75) * 10;

    cout << fixed << setprecision(2);

    cout << "\n============================";
    cout << "\nSGPA       : " << sgpa;
    cout << "\nPercentage : " << percentage << "%";
    cout << "\n============================";

    return 0;
}