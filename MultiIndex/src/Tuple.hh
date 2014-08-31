#ifndef TUPLE_HH
#define TUPLE_HH

#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using namespace boost::multi_index;

struct product {
    int id;
    std::string name;

    product(int id, const std::string& name)
        : id(id), name(name) {}
};

struct id {};
struct name {};

typedef multi_index_container<
    product,
    indexed_by<
        ordered_unique<tag<id>,   member<product, int,         &product::id> >,
        ordered_unique<tag<name>, member<product, std::string, &product::name> >
    >
> dictionary;

int main()
{
    dictionary dict;
    dict.insert(product(2852, "coffee"));
    dict.insert(product(7777, "cola"));

    // IDから名前を調べる
    {
        typedef dictionary::index<id>::type id_map;
        id_map& m = dict.get<id>();

        // IDをキーにして検索
        id_map::iterator it = m.find(2852);
        if (it != m.end()) {
            std::cout << it->name << std::endl;
        }
    }

    // 名前からIDを調べる
    {
        typedef dictionary::index<name>::type name_map;
        name_map& m = dict.get<name>();

        // 名前をキーにして検索
        name_map::iterator it = m.find("cola");
        if (it != m.end()) {
            std::cout << it->id << std::endl;
        }
    }
}

#endif
