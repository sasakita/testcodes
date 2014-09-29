#include <iostream>
#include <fstream>
#include <memory>

using namespace std;
struct noop
{
  void operator()(...) const {}
};

int main (int argc, char* argv[])
{
  string symbol;
  shared_ptr<istream> is;
  if (argc < 2)
  {
	cerr << "Usage: " << argv[0] << " [symbol] [filename]" << endl;
	return 1;
  }
  else if (argc < 3)
  {
	symbol = argv[1];
	is.reset(&cin, noop());
  }
  else if (argc >= 3)
  {
	symbol = argv[1];
	string filename(argv[2]);
	ifstream* ifs = new ifstream(filename);
	if (ifs->good())
	  is.reset(ifs);
	else
	{
	  cerr << "cannot open " << filename << endl;
	  return 1;
	}
	
  }

  string out;

  while(std::getline(*is, out))
  {
	cout << out << endl;
	
  }
  return 0;
}
