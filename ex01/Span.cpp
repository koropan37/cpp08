#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <limits> // for numeric_limits

Span::Span(unsigned int N) : size_(N){
    numbers_.reserve(N); // 容量の確保(sizeには影響ない)
}

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
    if(numbers_.size() > size_)
        throw std::out_of_range("Span is full");
    numbers_.push_back(n);
}

unsigned int Span::shortestSpan() const {
    if (numbers_.size() <= 1)
        throw std::logic_error("shortestSpan: not enough elements");

    std::vector<int> tmp(numbers_);
    std::sort(tmp.begin(), tmp.end());

    unsigned int minspan = tmp[1] - tmp[0];
    for (std::size_t i = 1; i < tmp.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
        if (span < minspan) minspan = span;
        if (minspan == 0) return 0;
    }
    return minspan;
}

unsigned int Span::longestSpan() const {
    if (numbers_.size() <= 1)
        throw std::logic_error("longestSpan: not enough elements");

    std::vector<int> tmp(numbers_);
    std::sort(tmp.begin(), tmp.end());
    return static_cast<unsigned int>(tmp.back() - tmp.front());
}
