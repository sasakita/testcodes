#ifndef VISITOR_HH_INCLUDED
#define VISITOR_HH_INCLUDED

#include <vector>
#include <iostream>
using namespace std;

class File;
class Directory;

class Visitor {
public:
    virtual void visit(File& f);
    virtual void visit(Directory& f);
};

class Element {
public:
    virtual void accept ();
};

class Entry : public Element {
public :
    string getName();
    int getSize();
    virtual void add(Entry &entry) = 0;
};

#endif // VISITOR_HH_INCLUDED
