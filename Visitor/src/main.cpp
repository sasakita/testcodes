#include <iostream>
#include "Observer.hh"
#include "Visitor.hh"
using namespace std;

int main()
{
    NumberGenerator n;
    TestObserver t;
    n.addObserver(&t);
    ExecObserver e;
    n.addObserver(&e);
    n.execute();
    cout << "Hello world!" << endl;
    return 0;
}
