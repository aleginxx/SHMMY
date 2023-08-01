#include <iostream>
#include "babyratio.hpp"

int main() {
    rational a(3, 8);
    rational b(-2, 11);
    a.div(b).print();
    std::cout << std::endl;
    // a.print();
    // std::cout << " should still be 1/2" << std::endl;
}