#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/lambda/lambda.hpp>

using boost::lambda::_1;
namespace fusion = boost::fusion;

const std::string strs[2] = {"test", "test2"};

int main()
{
  int a = 11;
  boost::tuple<const std::string&, int&> tupl(strs[0], a);

  const boost::tuple<int, int, int> t(1, 1, 2);
    fusion::for_each(t, std::cout << _1 << '\n');
}

//
//#include <iostream>
//#include <string>
//#include <boost/fusion/include/adapt_struct.hpp>
//#include <boost/fusion/include/for_each.hpp>
//#include <boost/lambda/lambda.hpp>
//
//using boost::lambda::_1;
//
//namespace fusion = boost::fusion;
//
//struct Person {
//    int id;
//    std::string name;
//    int age;
//
//    Person(int id, const std::string& name, int age)
//        : id(id), name(name), age(age) {}
//};
//
//BOOST_FUSION_ADAPT_STRUCT(
//    Person,
//    (int, id)
//    (std::string, name)
//    (int, age)
//)
//
//struct disper {
//    template <class T>
//    void operator()(const T& x) const
//    {
//        std::cout << x << std::endl;
//    }
//};
//
//int main()
//{
//    const Person person(3, "Alice", 18);
//
//	//    fusion::for_each(person, disper());
//	//    fusion::for_each(person, _1 = 1);
//   fusion::for_each(v, std::cout << _1 << std::endl);
//}
//
//struct disp {
//    template <class T>
//    void operator()(const T& x) const
//    {
//        std::cout << x.first << std::endl;
//    }
//};
//
//template <class T>
//void callforeach (T vec)
//{
//    fusion::for_each(vec, disp());
//}
////   fusion::for_each(v, disp());
////  const fusion::vector<int, char, std::string> v(1, 'a', "Hello");
////	callforeach<const fusion::vector<int, char, std::string> > (v);
