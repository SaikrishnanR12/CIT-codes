#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int rollNo;
    string name;
public:
    // Constructor
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
        cout << "Student object created: " << name << endl;
    }
    // Member function
    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
    // Destructor
    ~Student()
    {
        cout << "Student object destroyed: " << name << endl;
    }
};
int main()
{
    // Test case 1: object in main scope
    Student s1(101, "Arun");
    s1.display();
    // Test case 2: object in inner scope (destroyed at end of block)
    {
        Student s2(202, "Meena");
        s2.display();
        cout << "Leaving inner scope..." << endl;
    }
    cout << "Back in main" << endl;
    return 0;
}
