#include <iostream>
#include <string>
#include <vector>

using namespace std;
class MyObject {
public:
  static int count;
  int index;
  MyObject() { index = ++count; cout << "MyObject Const " << index << " " << this << endl;}
  virtual ~MyObject() {cout << "MyObject Dest " << index << " " << this << endl;}
  MyObject(const MyObject& obj) {cout << "MyObject Copy " << index << " "  << this << " " << &obj << endl;}
};
int  MyObject::count = 0;

int main()
{
  vector<MyObject> vec;
  for (int i = 0; i < 2;i++)
  {
	MyObject o;
	vec.push_back(o);
	//	MyObject* o = new MyObject();
	//	vec.push_back(o);
  }
  cout << "end" << endl;
  return 0;

}
