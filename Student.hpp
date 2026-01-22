#ifndef STUDENT_HPP
#define STUDENT_HPP
using namespace std;
#include <iostream>
#include <string>

class Student {
private:
    string id;
    int subject1_marks;
    int subject2_marks;

public:
    // Default Constructor
    Student();

    // Parametrized Constructor
    Student(string comp_id, int sub1_marks, int sub2_marks);
    
    // Destructor
    ~Student();
    
    // Accessor methods
    string getId() const;
    int getSubject1Marks() const;
    int getSubject2Marks() const;

    // Mutator methods
    void setId(string newId);
    void setSubject1Marks(int newMarks);
    void setSubject2Marks(int newMarks);
    
    // Utility methods
    void setDetails(string newId, int marks1, int marks2);
    void totalMarks() const;
};

#endif
