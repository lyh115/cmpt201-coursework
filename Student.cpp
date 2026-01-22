#include "Student.hpp"
#include <iostream>
using namespace std;

// Default constructor
Student::Student() {
   	cout << "Default constructor is called" << endl;
    id = "000";
    subject1_marks = 0;
    subject2_marks = 0; 
}

// Parametrized Constructor
Student::Student(string comp_id, int sub1_marks, int sub2_marks) {
    cout << "Parametrized constructor is called" << endl;
    // Assigning parameters to attributes of class
    id = comp_id;
    subject1_marks = sub1_marks;
    subject2_marks = sub2_marks;       
}

// Destructor
Student::~Student() { 
    cout << "Destructor is called"<< endl;
}

// Accessor methods
string Student::getId() const {
    return id;
}

int Student::getSubject1Marks() const {
    return subject1_marks;
}

int Student::getSubject2Marks() const {
    return subject2_marks;
}

// Mutator methods
void Student::setId(std::string newId) {
    id = newId;
}

void Student::setSubject1Marks(int newMarks) {
    if (newMarks >= 0 || newMarks <= 100) {
        subject1_marks = newMarks;
    }
}

void Student::setSubject2Marks(int newMarks) {
    if (newMarks >= 0 || newMarks <= 100) {
        subject2_marks = newMarks;
    }
}

// Utility methods
void Student::setDetails(std::string newId, int marks1, int marks2) {

    // Uses the mutator function to get the user inputted values 
    setId(newId);
    setSubject1Marks(marks1);
    setSubject2Marks(marks2);
}

void Student::totalMarks() const {
    // Calculates the total marks out of 200
    int total_marks = subject1_marks + subject2_marks;
    cout << "Your Total Marks out of 200: " << total_marks << endl;
}
