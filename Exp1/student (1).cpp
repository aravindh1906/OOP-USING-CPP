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
        cout << "Student object created" << endl;
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
        cout << "Student object destroyed" << endl;
    }
};

// Test case declarations (defined below main)
void testCase1();
void testCase2();

int main()
{
    cout << "===== Original Program =====" << endl;
    {
        Student s1(101, "Arun");
        s1.display();
    } // s1 is destroyed here, before the test cases run

    testCase1();
    testCase2();
    return 0;
}

// Test Case 1: Object inside an inner scope is destroyed at the closing brace
void testCase1()
{
    cout << "\n===== Test Case 1: Inner scope =====" << endl;
    Student a(1, "Meera");
    {
        Student b(2, "Kiran");
        b.display();
    } // b is destroyed here
    a.display();
} // a is destroyed here

// Test Case 2: Three objects in the same scope are destroyed in reverse order
void testCase2()
{
    cout << "\n===== Test Case 2: Three objects, reverse destruction =====" << endl;
    Student a(10, "Divya");
    Student b(20, "Ravi");
    Student c(30, "Sana");

    c.display();
} // destroyed in reverse order: c, b, a
