#include"Course.h"

    // Getters
    std::string Course::getDepartment() const {
        return department;
    }
    int Course::getCourseID() const {
        return courseID;
    }
    std::string Course::getName() const {
        return name;
    }
    int Course::getCredits() const {
        return credits;
    }
    std::vector<Course*> Course::getPrerequisites() const {
        return preReq;
    }
    std::vector<Course*> Course::getEquivalences() const {
        return equivalences;
    }

    // Setters
    void Course::setDepartment(std::string newDepartment) {
        department = newDepartment;
    }
    void Course::setCourseID(int newCourseID) {
        courseID = newCourseID;
    }
    void Course::setName(std::string newName) {
        name = newName;
    }
    void Course::setCredits(int newCredits) {
        credits = newCredits;
    }
    void Course::setPreRequisites(std::vector<Course*> newPrequsites) {
        preReq = newPrequsites;
    }
    void Course::setEquivalences(std::vector<Course*> newEquivalences) {
        equivalences = newEquivalences;
    }

    // Constructors
    // Default constructor, sets everything as empty
    Course::Course() { 
        department = "";
        courseID = 0;
        name = "";
        credits = 1;
        // vector is empty by default
    }
    // Takes a string and sets it as the name of the course to be created. Everything else is empty
    Course::Course(std::string newName) {
        department = "";
        courseID = 0;
        name = newName;
        credits = 1;
    }
    // Takes a string and an int, and sets them as the department string and the CourseID int respectively. Everything else is empty
    Course::Course(std::string newDepartment, int newCourseID) {
        if (newDepartment.length() == 4) { // Making sure they placed the department and not the course name
            department = newDepartment;
            courseID = newCourseID;
            name = "";
            credits = 1;
        }
    }

    // Takes a string and two int, and sets them as the department string, the CourseID int, and the credits respectively. Everything else is empty
    Course::Course(std::string newDepartment, int newCourseID, int newCredits) {
        if (newDepartment.length() == 4) { // Making sure they placed the department and not the course name
            department = newDepartment;
            courseID = newCourseID;
            name = "";
            credits = newCredits;
        }
    }

    // Takes a string, int, and another string and sets them as the department name, CourseID, and course name respectively.
    Course::Course(std::string newDepartment, int newCourseID, std::string newName) {
        if (newDepartment.length() == 4) { // Making sure they placed the department and not the course name
            department = newDepartment;
            courseID = newCourseID;
            name = newName;
        }
    }
    
    // Takes two strings and two ints, and sets them as the department, name, ID and credits respectively
    Course::Course(std::string newDepartment, int newCourseID, std::string newName, int newCredits) {
        if (newDepartment.length() == 4) { // Making sure they placed the department in the first field and not the course name
            department = newDepartment;
            courseID = newCourseID;
            name = newName;
            credits = newCredits;
        }
    }

    // Methods

    // Returns true if the course has prerequistes, false if it does not
    bool Course::hasPrerequisite() { 
        if (preReq.empty()) {
            return false; 
        }
        else 
            return true;
    }

    // Takes a pointer to a "Course" object and adds it as a prerequiste to the course.
    void Course::addPrerequisite(Course* newPrereq) {
        preReq.push_back(newPrereq);
    }

    // Takes the department and courseID of a course and eliminates it form the prequisites if it was one. Does nothing if it was not.
    void Course::removePrerequisite(std::string oldDepartment, int oldCourseID) {
        for (int i = 0; i < preReq.size(); i ++) { // Search every index of the vector.
            if (preReq.at(i)->department == oldDepartment && preReq.at(i)->courseID == oldCourseID) { // and see if the given course is in the vector.
                preReq.erase(preReq.begin() + i); // delete the course located at that index.
            }
            // if the course is not found, do nothing. Maybe inform the user?? Maybe make it return a boolean?
        }
    }

    // Takes the name of a course and checks if that course if that course is a prerequiste. If it is, it removes it. Does nothing if it is not.
    void Course::removePrerequisite(std::string oldPrereq) {
        for (int i = 0; i < preReq.size(); i ++) { // Search every index of the vector.
            if (preReq.at(i)->name == oldPrereq) { // and see if the given course is in the vector.
                preReq.erase(preReq.begin() + i); // delete the course located at that index.
            }
            // if the course is not found, do nothing. Maybe inform the user??
        }
    }

    // Retuns true if the course has any equivalences, flase if it does not.
    bool Course::hasEquivalence() {
        if (equivalences.empty()) {
            return false;
        }
        else   
            return true;
    }

    // Takes a pointer to a "Course" object and adds it as an equivalence to the course.
    void Course::addEquivalence(Course* newEquivalence) {
        equivalences.push_back(newEquivalence);
    }

    // Takes the department and courseID of a course and eliminates it form the equivalences if it was one. Does nothing if it was not.
    void Course::removeEquivalence(std::string oldDepartment, int oldCourseID) {
        for (int i = 0; i < equivalences.size(); i ++) { // Search every index of the vector.
            if (equivalences.at(i)->department == oldDepartment && equivalences.at(i)->courseID == oldCourseID) { // and see if the given course is in the vector.
                equivalences.erase(equivalences.begin() + i); // delete the course located at that index.
            }
            // if the course is not found, do nothing. Maybe inform the user?? Maybe make it return a boolean?
        }
    }
    
    // Takes the name of a course and checks if that course if that course is a equivalence. If it is, it removes it. Does nothing if it is not.
    void Course::removeEquivalence(std::string oldEquivalence) {
        for (int i = 0; i < equivalences.size(); i ++) { // Search every index of the vector.
            if (equivalences.at(i)->name == oldEquivalence) { // and see if the given course is in the vector.
                equivalences.erase(equivalences.begin() + i); // delete the course located at that index.
            }
            // if the course is not found, do nothing. Maybe inform the user?? Maybe make it return a boolean?
        }
    }