#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<vector>

class Course
{
    std::string department; // What goes before the numerical identifier of the course. Eg: COMP, MATE, INSO, CIIC, etc.
    int courseID; // The numerical identifier of the specific course. Eg: 3005, 3010, 4016, 6789, etc.
    std::string name; // The name of the course. Eg: Introduction to coputer porgramming, Calculus 1, etc...
    int credits; // How many credits it is worth. Eg: 1, 2, 3, 4, 5.
    std::vector<Course*> preReq; // Prerequisites needed to take said course
    std::vector<Course*> equivalences; // Equivalences of said course

    public:

    // Getters
    std::string getDepartment() const;
    int getCourseID() const;
    std::string getName() const;
    int getCredits() const;
    std::vector<Course*> getPrerequisites() const;
    std::vector<Course*> getEquivalences() const;

    // Setters
    void setDepartment(std::string newDepartment);
    void setCourseID(int newCourseID);
    void setName(std::string newName);
    void setCredits(int newCredits);
    void setPreRequisites(std::vector<Course*> newPrequsites);
    void setEquivalences(std::vector<Course*> newEquivalences);

    // Constructors

    // Default constructor, sets everything as empty
    Course();
    // Takes a string and sets it as the name of the course to be created. Everything else is empty
    Course(std::string newName);
    // Takes a string and an int, and sets them as the department string and the CourseID int respectively. Everything else is empty
    Course(std::string newDepartment, int newCourseID);
    // Takes a string and two int, and sets them as the department string, the CourseID int, and the credits respectively. Everything else is empty
    Course(std::string newDepartment, int newCourseID, int newCredits);
    // Takes a string, int, and another string and sets them as the department name, CourseID, and course name respectively.
    Course(std::string newDepartment, int newCourseID, std::string newName);
    // Takes two strings and two ints, and sets them as the department, name, ID and credits respectively
    Course(std::string newDepartment, int newCourseID, std::string newName, int newCredits);

    // Methods

    // Returns true if the course has prerequistes, false if it does not
    bool hasPrerequisite();
    // Takes a pointer to a "Course" object and adds it as a prerequiste to the course.
    void addPrerequisite(Course* newPrereq);
    // Takes the department and courseID of a course and eliminates it form the prequisites if it was one. Does nothing if it was not.
    void removePrerequisite(std::string oldDepartment, int oldCourseID);
    // Takes the name of a course and checks if that course if that course is a prerequiste. If it is, it removes it. Does nothing if it is not.
    void removePrerequisite(std::string oldPrereq);
    // Retuns true if the course has any equivalences, flase if it does not.
    bool hasEquivalence();
    // Takes a pointer to a "Course" object and adds it as an equivalence to the course.
    void addEquivalence(Course* newEquivalence);
    // Takes the department and courseID of a course and eliminates it form the equivalences if it was one. Does nothing if it was not.
    void removeEquivalence(std::string oldDepartment, int oldCourseID);
    // Takes the name of a course and checks if that course if that course is a equivalence. If it is, it removes it. Does nothing if it is not.
    void removeEquivalence(std::string oldEquivalence);
};

#endif