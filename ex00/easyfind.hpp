#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <algorithm>
#include <stdexcept>

// find は失敗するとend() を返す
template<typename T>
typename T::iterator easyfind(T& container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::out_of_range("easyfind: value not found");
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int n) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::out_of_range("easyfind: value not found");
    return it;
}

#endif
