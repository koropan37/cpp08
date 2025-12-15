#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <list>
#include <vector>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

int main(void) {
	printColor("Vector (int)", CYAN);
	{
		std::vector<int> vec;
		for(int i = 1; i < 4; ++i)
			vec.push_back(i);
		std::cout << "vector: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << ", ";
		std::cout << std::endl;
		try {
			std::cout << "easyfind(vec, 2)  ";
			std::vector<int>::iterator it = easyfind(vec, 2);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
		try {
			std::cout << "easyfind(vec, 4)  ";
			std::vector<int>::iterator it = easyfind(vec, 4);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
		try {
			std::cout << "easyfind(vec, -1) ";
			std::vector<int>::iterator it = easyfind(vec, -1);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
	}
	printColor("List (long)", YELLOW);
	{
		std::list<long> lis;
		for(int i = 1; i < 4; ++i)
			lis.push_back(i);
		std::cout << "vector: ";
		for (std::list<long>::iterator it = lis.begin(); it != lis.end(); ++it)
			std::cout << *it << ", ";
		std::cout << std::endl;
		try {
			std::cout << "easyfind(vec, 3)  ";
			std::list<long>::const_iterator it = easyfind(lis, 3);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
		try {
			std::cout << "easyfind(vec, 4)  ";
			std::list<long>::const_iterator it = easyfind(lis, 5);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
		try {
			std::cout << "easyfind(vec, -1) ";
			std::list<long>::const_iterator it = easyfind(lis, -1);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE " << e.what() << std::endl;
		}
	}
    printColor("Iterator (vector) ", MAGENTA);
	// capacity
		{
			std::vector<int> v;
			std::cout << "initial size=" << v.size() << " cap=" << v.capacity() << '\n';
			for (int i = 0; i < 10; ++i) {
				v.push_back(i);
				std::cout << "after push " << i << " size=" << v.size() << " cap=" << v.capacity() << '\n';
			}
		}
	std::cout << std::endl;
    // ) reserve 
    {
        std::vector<int> v1;
		v1.reserve(10);
        for (int i = 0; i < 3; ++i) v1.push_back(i);
        std::vector<int>::iterator it = v1.begin();
        std::cout << "before reserve: &v1[0] = " << (void*)&v1[0] << ", *it = " << *it << std::endl;
        v1.push_back(3);
        std::cout << "after +push: &v1[0] = " << (void*)&v1[0] << ", *it = " << *it << std::endl;
    }
	std::cout << std::endl;
    // ) reallocation
    {
        std::vector<int> v2;
        v2.push_back(1);
        std::vector<int>::iterator it2 = v2.begin();
        void* addr_before = (void*)&v2[0];
        v2.push_back(2);
        void* addr_after = (void*)&v2[0];
        std::cout << "addr before = " << addr_before << ", after = " << addr_after << std::endl;
        if (addr_before != addr_after)
            std::cout << "=> reallocation : old iterator has been invalidated" << std::endl;
        else
            std::cout << "=> no reallocation: iterator still valid" << std::endl;
		(void)it2;
    }
	std::cout << std::endl;
    // )  erase 
    {
        std::vector<int> v3;
        for (int i = 0; i < 10; ++i) v3.push_back(i);
        std::cout << "original v3 size = " << v3.size() << std::endl;
        for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); ) {
            if (*it % 2 == 0)
                it = v3.erase(it); 
            else
                ++it;
        }
        std::cout << "after erase evens, v3: ";
        for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); ++it)
            std::cout << *it << ", ";
        std::cout << std::endl;
    }
}
