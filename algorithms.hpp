#pragma once

template< class InputIt, class UnaryFunc >
UnaryFunc for_each( InputIt first, InputIt last, UnaryFunc f ) {
    while (first != last) {
        f(*first);
        first++;
    }
    return (f);
}