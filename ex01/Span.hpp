#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <set>
#include <iterator>
class Span {
 private:
	unsigned int size_;
	std::multiset<int> numbers_;

	Span();

 public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int n);

	template<typename TIt>
	void addNumber(TIt first, TIt last) {
		std::ptrdiff_t d = std::distance(first, last);
		 //(multiset<int> v; first = v.end(), last = v.begin()) のようなとき
       	if (d < 0)
			throw std::invalid_argument("addNumber: invalid range");
	    if(numbers_.size() + static_cast<unsigned int>(d) > size_)
			throw std::out_of_range("Span is full");
		numbers_.insert(first, last);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

};

#endif
