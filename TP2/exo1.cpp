#include <iostream>
#include <vector>
#include <list>
#include <string>


struct occ_char {
    char c;
    int occ;
};


std::list<occ_char> list_occ(std::string s){
    std::list<occ_char> l;

    return l;
}

int main()
{

    std::string s;

    getline(std::cin, s);

    std::cout << s << std::endl;
    return (0);
}