#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <limits> // for numeric_limits

Span::Span(unsigned int N) : size_(N), numbers_() {}

Span::Span(const Span& other) : size_(other.size_), numbers_(other.numbers_) {}

Span& Span::operator=(const Span& other) {
    if(this != &other) {
        size_     = other.size_;
        numbers_ = other.numbers_;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if(numbers_.size() >= size_)
        throw std::out_of_range("Span is full");
    numbers_.insert(n);
}

unsigned int Span::shortestSpan() const {
    if (numbers_.size() <= 1)
        throw std::logic_error("shortestSpan: not enough elements");

    std::multiset<int>::const_iterator it = numbers_.begin();
    std::multiset<int>::const_iterator prev = it++;

    unsigned int minspan = -1;
    for (; it != numbers_.end(); ++it, ++prev) {
        unsigned int span = static_cast<unsigned int>(*it - *prev);
        if (span < minspan) minspan = span;
        if (minspan == 0) return 0;
    }
    return minspan;
}

unsigned int Span::longestSpan() const {
    if (numbers_.size() <= 1)
        throw std::logic_error("longestSpan: not enough elements");

        int min = *numbers_.begin();         
        int max = *numbers_.rbegin();        
        return static_cast<unsigned int>(max - min);
}
