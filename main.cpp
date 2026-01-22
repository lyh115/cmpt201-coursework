#include "Student.hpp"
#include <iostream>
using namespace std;

int main() {

    // Initializing the object which calls a default constructor
    Student student1;

    //Initializing the object which calls a parametrized constructor
    Student student2("301522323", 58, 81);

    // Initialize the object which calls a default constructor
    // This will be updated using setter functions
    Student student3;
    
    // Use accessor methods to get the attribute values and print them

    // output of default constructor in action
    cout << "ID: " << student1.getId() << endl;
    cout << "Subject 1 Marks: " << student1.getSubject1Marks() << endl;
    cout << "Subject 2 Marks: " << student1.getSubject2Marks() << endl;
    student1.totalMarks();
    cout << endl;

    // output of parametrized constructor in action
    cout << "ID: " << student2.getId() << endl;
    cout << "Subject 1 Marks: " << student2.getSubject1Marks() << endl;
    cout << "Subject 2 Marks: " << student2.getSubject2Marks() << endl;
    student2.totalMarks();
    cout << endl;

    // Modify class attributes set to default using a utility method
    student3.setDetails("30142232", 12, 35);
    cout << "ID: " << student3.getId() << endl;
    cout << "Subject 1 Marks: " << student3.getSubject1Marks() << endl;
    cout << "Subject 2 Marks: " << student3.getSubject2Marks() << endl;
    student3.totalMarks();
    cout << endl;

    return 0;
}
