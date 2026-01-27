#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Grandparent class
class Grandparent {
    public:
        Grandparent(const string &name);

        void addSibling(const string &newSibling);
        void getSiblings() const;

        string getName() const;
        void setName(const string &newName);

    protected:
        vector <string> siblings;

    private:
        string name;
};

Grandparent::Grandparent(const string &name)
    : name(name) {}

void Grandparent::addSibling(const string &newSibling){
    siblings.push_back(newSibling);
}

void Grandparent::getSiblings() const {
    for(const string &sibling : siblings){
        cout << sibling << endl;
    }
}

string Grandparent::getName() const {
    return name;
}

void Grandparent::setName(const string &newName){
    name = newName;
}

//Parent class
class Parent: public Grandparent {
    public:
        Parent(const string &name, int parentParm)
            : Grandparent(name), parentParm(parentParm) {}
            
        void addParent(const string &newParent);
        void getParents() const;

        void setParentParm(const int &newParentParm);
        int getParentParm() const;

    protected:
        vector <string> parents;

    private:
        int parentParm;
};

void Parent::addParent(const string &newParent){
    parents.push_back(newParent);
}

void Parent::getParents() const {
    for(const string &parent : parents){
        cout << parent << endl;
    }
}

void Parent::setParentParm(const int &newParentParm){
    parentParm = newParentParm;
}

int Parent::getParentParm() const {
    return parentParm;
}

class Children: public Parent {
    public:
        Children(const string &name, int parentParm, int childrenParm)
            : Parent(name, parentParm), 
            childrenParm(childrenParm) {}

        void addGrandParent(const string &newGrandParent);
        void getGrandParents() const;

        void setChildrenParm(const int newChildrenParm);
        int getChildrenParm() const;

    protected:
        vector <string> grandParents;

    private:
        int childrenParm;
};

void Children::addGrandParent(const string &newGrandParent){
    grandParents.push_back(newGrandParent);
}

void Children::getGrandParents() const {
    for(const string &grandParent : grandParents){
        cout << grandParent << endl;
    }
}

void Children::setChildrenParm(const int newChildrenParm){
    childrenParm = newChildrenParm;
}

int Children::getChildrenParm() const {
    return childrenParm;
}

//Main
void runInheritance(){
    //Grandparent
    Grandparent grandMother("Susana");
    
    grandMother.addSibling("Maria");
    grandMother.addSibling("Lulu");

    grandMother.getSiblings();

    //grandMother.setName("Lola");
    cout << grandMother.getName() << endl;

    //Parent
    Parent father("Juan Carlos", 34);
    
    father.addSibling("Jorge");
    father.addSibling("Manuel");
    father.addSibling("Susana");
    
    father.getSiblings();
    
    //father.setName("Luis");
    cout << father.getName() << endl;

    father.addParent("Susana");
    father.addParent("Juan");

    father.getParents();

    father.setParentParm(34);
    cout << father.getParentParm() << endl;

    //Children
    Children child("Rodrigo", 34, 23);
    
    child.addSibling("Mariana");
    child.addSibling("Lauris");
    
    child.getSiblings();
    
    //child.setName("Roberto");
    cout << child.getName() << endl;

    child.addParent("Juan Carlos");
    child.addParent("Laura");

    child.getParents();

    child.setParentParm(54);
    cout << child.getParentParm() << endl;

    child.addGrandParent("Susana");
    child.addGrandParent("Juan Carlos");

    child.getGrandParents();

    child.setChildrenParm(57);
    cout << child.getChildrenParm() << endl;
}