#ifndef OBSERVER_HH_INCLUDED
#define OBSERVER_HH_INCLUDED

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Observer {
private:
public:
    virtual void update(){cout << "base" << endl;}
};

class TestObserver : public Observer {
public:
    virtual void update() {cout << "Update TestObserver" << endl; return;}
};

class ExecObserver : public Observer {
public:
    virtual void update() {cout << "Update ExecObserver" << endl; return;}
};


class Generator { // Subject
public:
    void addObserver(Observer* o) {observers.push_back(o);}

    void removeObserver(Observer* o) {
        for ( vector<Observer*>::iterator it = observers.begin();
            it != observers.end(); it++) {
            if ( *it == o ) {
                observers.erase(it);
                return;
            }
        }
        return;
    }

    void notifyObservers() {
        for ( vector<Observer*>::iterator it = observers.begin(); it != observers.end(); it++) {
            (*it)->update();
        }
    }
private:
    vector <Observer*> observers;
};

class NumberGenerator : public Generator {
public:
    void execute () {
        cout << "12345" << endl;
        notifyObservers();
    }
};

#endif // OBSERVER_HH_INCLUDED
