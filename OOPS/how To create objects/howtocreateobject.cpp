#include <iostream>
using namespace std;

/*
How to Create an Object in C++

Topics Covered:
---------------
1. Class (Blueprint)
2. Object (Instance of Class)
3. Constructor (Default)
4. Parameterized Constructor
5. Destructor
6. Object Life Cycle
7. Member Functions
8. Access Specifiers
9. Dynamic Object Creation
10. Copy Constructor
11. Static Members
12. Explanation and Test Cases
*/

// 1. Define a blueprint: Class
class Student {
public: // 8. Access Specifier: public members accessible outside class
    string name; // Data member to store student's name
    int age;     // Data member to store student's age
    static int count; // 11. Static member to count number of objects

    // 3. Constructor (Default)
    Student() {
        cout << "Default Constructor called!" << endl;
        name = "Unknown";
        age = 0;
        count++; // Increment static count
    }

    // 4. Parameterized Constructor
    Student(string n, int a) {
        cout << "Parameterized Constructor called!" << endl;
        name = n;
        age = a;
        count++; // Increment static count
    }

    // 10. Copy Constructor
    Student(const Student &other) {
        cout << "Copy Constructor called!" << endl;
        name = other.name;
        age = other.age;
        count++; // Increment static count
    }

    // 7. Member function to display student info
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Static member function
    static void showCount() {
        cout << "Total Students created: " << count << endl;
    }

    // 5. Destructor
    ~Student() {
        cout << "Destructor called for " << name << endl;
        count--; // Decrement static count
    }
};

// Initialize static member
int Student::count = 0;

int main() {
    // 2. Object is an instance of Class

    // Creating object using default constructor
    Student s1; // Object s1 is created, default constructor is called
    s1.display(); // Display info

    // Creating object using parameterized constructor
    Student s2("Alice", 21); // Object s2 is created, parameterized constructor is called
    s2.display(); // Display info

    // 10. Copy Constructor
    Student s3 = s2; // s3 is a copy of s2
    s3.display();

    // 9. Dynamic Object Creation
    Student* s4 = new Student("Bob", 25); // Object created on heap
    s4->display();

    // 11. Static Members
    Student::showCount(); // Show total students created

    // Deleting dynamic object
    delete s4; // Destructor called for Bob

    // 6. Object Life Cycle
    // Objects s1, s2, s3 are created inside main()
    // When main() ends, destructors for s1, s2, s3 are called automatically

    Student::showCount(); // Show count after deletion

    return 0;
}

/*
Explanation:
------------
1. Class 'Student' is a blueprint for creating student objects.
2. Objects 's1', 's2', 's3', and 's4' are instances of the class.
3. Default constructor initializes members with default values.
4. Parameterized constructor initializes members with given values.
5. Destructor is called automatically when object goes out of scope (end of main) or when deleted (for dynamic objects).
6. Object life cycle: creation (constructor), usage, destruction (destructor).
7. Member functions allow objects to perform actions (display info).
8. Access specifiers control visibility of members (public here).
9. Dynamic object creation uses 'new' and requires manual deletion with 'delete'.
10. Copy constructor creates a new object as a copy of an existing object.
11. Static members belong to the class, not to any object, and track total objects.
12. Test cases show all features in action.

Test Cases:
-----------
- s1 created with default constructor, displays "Unknown", 0.
- s2 created with parameterized constructor, displays "Alice", 21.
- s3 created with copy constructor, displays "Alice", 21.
- s4 created dynamically, displays "Bob", 25.
- Static count shows total students created.
- Destructor called for Bob when deleted.
- Destructor called for s1, s2, s3 at end of main.
- Static count updated after deletion.
*/