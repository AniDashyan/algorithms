#include "algorithms.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

void add_and_print(int x) {
    std::cout << "x: " << x + 7 << "\n";
}

// A functor 
class Add {
    private:
        int m_sum;
    public:
        Add() : m_sum(0) {}
        void operator()(int x) {
            m_sum += x;
        }

        int get_sum() const {
            return (this->m_sum);
        } 
};


class OddCount {
    private:
        int m_count;
    public:
        OddCount() : m_count(0) {}
        bool operator()(int x) {
            if (x % 2 == 1)
                ++m_count;

            return (true);
        }
    int get_count() const {
        return (this->m_count);
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<std::string> text = {"Hello", "darkness", "my", "old", "friend"};
    std::vector<char> chars{'H', 'd', 'm', 'o', 'f'};

    std::cout << "Testing for_each\n";
    // Calling with a regular function
    std::cout << "Test 1: for_each with regular function\n";
    ani::for_each(vec.begin(), vec.end(), add_and_print);
    for_each(vec.begin(), vec.end(), add_and_print);
    
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    // Calling with lambda function
    std::cout << "Test 2: for_each with lambda functions\n";
    ani::for_each(vec.begin() + 1, vec.end() - 1, [](int& x) {
        std::cout << x + 7 << "\n";
    });

    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Test 2.1: for_each with lambda functions on string\n";
    ani::for_each(text.begin(), text.end(), [](const std::string& i) {
        std::cout << "length of " << i << " is " << i.length() << "\n"; 
    });

    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";
    
    // for_each returns the function object state
    std::cout << "Test 3: Calling for_each with functor (function object)\n";
    int s = ani::for_each(vec.begin(), vec.end(), Add()).get_sum();
    std::cout << "sum: " << s << "\n";
    
    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Testing for_each_n\n";
    size_t n = 4;
    int k = 100;
    std::cout << "Testing with a regular function\n";
    // std::vector<int>::iterator it = vec.begin();
    auto [x, y]= ani::for_each_n(vec.begin(), n, add_and_print);
    std::cout << *x << "----" << y << "\n";

    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";
    
    std::cout << "Testing find\n";
    std::cout << "ani::find\n";
    auto [it, f] = ani::find(vec.begin(), vec.end(), 7);
    if (f) std::cout << "Found 7 at " << *it << "\n";
    else std::cout << "Couldn't find 7\n";
    
    // std::find
    std::cout << "std::find\n";
    std::vector<int>::iterator it1 = std::find(vec.begin(), vec.end() - 3, 1);
    if (it1 != vec.end()) std::cout << "Found 1 at " << *it1 << "\n";
    else std::cout << "Couldn't find 1\n"; 
    
    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    auto [it11, f1] = ani::find(vec.begin(), vec.end() - 3, 1);
    if (f) std::cout << "Found 1 at " << *it1 << "\n";
    else "Couldn't find 1\n";
    
    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Testing find_if\n";

    auto [it_if, f_if] = ani::find_if(vec.begin(), vec.end(), OddCount());
    auto [it_iff, f_iff] = ani::find_if(vec.begin(), vec.end(), OddCount());
    if (f_if) {
        std::cout << "Found at " << *it_if << "\n";
        std::cout << "Found at : " << std::distance(vec.begin(), it_if) << "\n";
    }
    else  std::cout << "Couldn't find\n";

    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Total Odd count " << OddCount().get_count() << "\n";

    std::cout << "Testing find_if_not\n";
    auto [itt, ff] = ani::find_if_not(chars.begin(), chars.end(), isdigit);
    if (ff) std::cout << "The first not digit " << *itt << "\n";
    else std::cout << "Vector contains only digits\n";

    std::cout << std::setfill(' ') << std::setw(30) << "" << std::setfill(' ') << "\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Testing search\n";
    return (0);
}