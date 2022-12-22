#include<iostream>
#include"Node.h" // Kinda self explainatory
#include"Course.h"

using namespace std;

int main()
{
    Node<int> MyNode = Node<int>(10);
    cout << MyNode.getData() << endl;

    Course* MATE3181 = new Course("MATE", 3181, "Introduction to discrete Mathematics", 3);
    cout << MATE3181->getDepartment() << MATE3181->getCourseID() << " " << MATE3181->getName() << endl;

    Course* MATE3171 = new Course("MATE", 3171, "Precalculus 1", 3);
    MATE3181->addPrerequisite(MATE3171);
    cout << (MATE3181->getPrerequisites().at(0))->getName() << endl;

    Course* MATE3172 = new Course("MATE", 3172, "Precalculus 2", 3);
    MATE3172->addPrerequisite(MATE3171); // Remember to make so a course cannot be its own prerequisite!!!
    
    Course* MATE3005 = new Course("MATE", 3005, "Precalculus 1 & 2", 5);
    MATE3171->addEquivalence(MATE3005);
    MATE3172->addEquivalence(MATE3005);
    cout << MATE3171->getEquivalences().at(0)->getName() << " " << MATE3172->getEquivalences().at(0)->getName() << endl;
    return 0;
}