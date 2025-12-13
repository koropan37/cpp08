#include "Span.hpp"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

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

int main()
{
	printColor("Subject", CYAN);
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	printColor("Int max-min", YELLOW);
	{
		Span sp(3);
		sp.addNumber(0);
		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::min());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	printColor("Over 10,000 elements", GREEN);
	{	try {
			std::vector<int> vec;
			vec.reserve(10000);
			std::srand(time(NULL));
			for(int i = 0; i < 10000; ++i)
				vec.push_back(std::rand());
			Span sp(10000);
			sp.addNumber(vec.begin(), vec.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	printColor("Error", RED);
	{
		try {
			Span sp(1);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Span sp(1);
			sp.addNumber(10);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
