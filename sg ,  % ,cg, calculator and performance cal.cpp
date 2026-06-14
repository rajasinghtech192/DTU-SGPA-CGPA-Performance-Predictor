#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int getGradePoint(string grade)
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
    float totalGradePoints = 0;

    int highestGrade = 0;
    int lowestGrade = 10;

    cout << "===== DTU SGPA & CGPA Calculator =====\n";

    cout << "Enter Number of Subjects: ";
    cin >> subjects;

    for(int i = 1; i <= subjects; i++)
    {
        string grade;
        float credits;

        cout << "\nSubject " << i << endl;

        cout << "Enter Grade (O,A+,A,B+,B,C,P,F): ";
        cin >> grade;

        cout << "Enter Credits: ";
        cin >> credits;

        int gp = getGradePoint(grade);

        totalGradePoints += gp * credits;
        totalCredits += credits;

        if(gp > highestGrade)
            highestGrade = gp;

        if(gp < lowestGrade)
            lowestGrade = gp;
    }

    float sgpa = totalGradePoints / totalCredits;
    float percentage = sgpa * 10;

    cout << fixed << setprecision(2);

    cout << "\n\n===== Semester Result =====";
    cout << "\nSGPA = " << sgpa;
    cout << "\nPercentage = " << percentage << "%";
    cout << "\nHighest Grade Point = " << highestGrade;
    cout << "\nLowest Grade Point = " << lowestGrade;

    // Current CGPA Calculation
    float previousCGPA;
    int previousCredits;

    cout << "\n\nEnter Previous CGPA: ";
    cin >> previousCGPA;

    cout << "Enter Total Credits Completed Before This Semester: ";
    cin >> previousCredits;

    float currentCGPA =
    ((previousCGPA * previousCredits) +
     (sgpa * totalCredits))
     / (previousCredits + totalCredits);

    cout << "\nCurrent CGPA = " << currentCGPA;

    // CGPA Prediction
    float nextSemSGPA;
    int nextSemCredits;

    cout << "\n\nEnter Expected SGPA Next Semester: ";
    cin >> nextSemSGPA;

    cout << "Enter  Total Credits Earned in  Next Semester: ";
    cin >> nextSemCredits;

    float predictedCGPA =
    ((currentCGPA * (previousCredits + totalCredits)) +
     (nextSemSGPA * nextSemCredits))
     / (previousCredits + totalCredits + nextSemCredits);

    cout << "\nPredicted CGPA After Next Semester = "
         << predictedCGPA;

    return 0;
}