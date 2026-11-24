#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Student
{
public:
    string name;
    int mark;
    char grade;
};
int main()
{
    // Own test cases (covers A, B, C, F boundaries)
    vector<Student> students = {
        {"Divya", 90, ' '},
        {"Karthik", 49, ' '},
        {"Sana", 75, ' '},
        {"Vikram", 50, ' '},
        {"Priya", 97, ' '}
    };
    // Sort students based on marks (descending)
    sort(students.begin(), students.end(),
        [](Student a, Student b) { return a.mark > b.mark; });
    // Assign grades using transform
    transform(students.begin(), students.end(), students.begin(),
        [](Student s)
        {
            if (s.mark >= 90) s.grade = 'A';
            else if (s.mark >= 75) s.grade = 'B';
            else if (s.mark >= 50) s.grade = 'C';
            else s.grade = 'F';
            return s;
        });
    // Find first student scoring above 80
    auto it = find_if(students.begin(), students.end(),
        [](Student s) { return s.mark > 80; });
    // Total marks using accumulate
    int total = accumulate(students.begin(), students.end(), 0,
        [](int sum, Student s) { return sum + s.mark; });
    float average = (float)total / students.size();

    cout << "Student Grade Analyzer\n";
    cout << "---------------------\n";
    cout << "Name\tMark\tGrade\n";
    for (Student s : students)
        cout << s.name << "\t" << s.mark << "\t" << s.grade << endl;
    if (it != students.end())
        cout << "\nFirst student scoring above 80: " << it->name << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Average Mark: " << average << endl;
    return 0;
}
