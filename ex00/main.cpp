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
			std::cerr << " is FAILURE" << std::endl;
		}
		try {
			std::cout << "easyfind(vec, 4)  ";
			std::vector<int>::iterator it = easyfind(vec, 4);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE" << std::endl;
		}
		try {
			std::cout << "easyfind(vec, -1) ";
			std::vector<int>::iterator it = easyfind(vec, -1);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE" << std::endl;
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
			std::list<long>::iterator it = easyfind(lis, 3);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE" << std::endl;
		}
		try {
			std::cout << "easyfind(vec, 4)  ";
			std::list<long>::iterator it = easyfind(lis, 5);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE" << std::endl;
		}
		try {
			std::cout << "easyfind(vec, -1) ";
			std::list<long>::iterator it = easyfind(lis, -1);
			std::cout << *it << " is SUCCESS" << std::endl;
		} catch(std::exception& e) {
			std::cerr << " is FAILURE" << std::endl;
		}
	}
}
