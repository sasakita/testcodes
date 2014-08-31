#include <boost/tuple/tuple.hpp> 
#include <boost/tuple/tuple_io.hpp> 
#include <string> 
#include <iostream> 

int main() 
{ 
  typedef boost::tuple<std::string, std::string> person; 
  person p("Boris", "Schaeling"); 
  for (int i = 0; i < boost::tuples::length<person>::value; i++) {
	std::cout << i << std::endl; 
  }
  std::cout << p << std::endl; 
}
