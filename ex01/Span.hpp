#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <vector>
#include <iterator>
class Span {
 private:
	unsigned int size_;
	std::vector<int> numbers_;

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
		 //(vector<int> v; first = v.end(), last = v.begin()) のようなとき
       	if (d < 0)
			throw std::invalid_argument("addNumber: invalid range");
	    if(numbers_.size() + static_cast<unsigned int>(d) > size_)
			throw std::out_of_range("Span is full");
		numbers_.insert(numbers_.end(), first, last);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

};

#endif
