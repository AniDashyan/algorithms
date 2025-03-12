#pragma once

#include  <utility>

namespace ani {
    template< class InputIt, class UnaryFunc >
    constexpr UnaryFunc for_each( InputIt first, InputIt last, UnaryFunc f ) {
        while (first != last) {
            f(*first);
            ++first;
        }
        return (f);
    }

    template< class InputIt, class Size, class UnaryFunc >
    constexpr std::pair<InputIt, UnaryFunc> for_each_n( InputIt first, Size n, UnaryFunc f ) {
        for (; n > 0; --n, ++first) {
            f(*first);
        }
        return {first, f};       
    }

    template< class InputIt, class T >
    constexpr std::pair<InputIt, bool> find( InputIt first, InputIt last, const T& value ) {
        while (first != last)
        {
            if (*first == value)
                return {first, true};

            ++first;
        }
        return {last, false};
    } 

    template< class InputIt, class UnaryPred >
    constexpr std::pair<InputIt, bool> find_if( InputIt first, InputIt last, UnaryPred p ) {
        while (first != last)
        {
            if (p(*first)) {
                return {first, true};
            }
            ++first;
        }
        return {last, false};
    }

    template< class InputIt, class UnaryPred >
    constexpr std::pair<InputIt, bool> find_if_not( InputIt first, InputIt last, UnaryPred q ) {
        while (first != last) {
            if (!q(*first)) {
                return {first, true};
            }
            ++first;
        }
        return {last, false};
    }
}