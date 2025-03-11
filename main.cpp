#include "algorithms.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

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

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::vector<std::string> text = {"Hello", "darkness", "my", "old", "friend"};

    // Calling with a regular function
    std::cout << "Test 1: for_each with regular function\n";
    for_each(vec.begin(), vec.end(), add_and_print);
    
    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    // Calling with lambda function
    std::cout << "Test 2: for_each with lambda functions\n";
    for_each(vec.begin() + 1, vec.end() - 1, [](int& x) {
        std::cout << x + 7 << "\n";
    });

    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";

    std::cout << "Test 2.1: for_each with lambda functions on string\n";
    for_each(text.begin(), text.end(), [](const std::string& i) {
        std::cout << "length of " << i << " is " << i.length() << "\n"; 
    });

    std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << "\n";
    
    // for_each returns the function object state
    std::cout << "Test 3: Calling for_each with functor (function object)\n";
    int s = for_each(vec.begin(), vec.end(), Add()).get_sum();
    std::cout << "sum: " << s << "\n";
  
    return (0);
}