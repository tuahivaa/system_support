#include <iostream>

#include "Bond.h"
#include "Bond.cpp"

int main() {

    // Create a new semi-annually compounded bond
    Bond customBond("11/19/2035", 0.5, 0.07);

    // Print its characteristics using the ToString() function
    std::cout << "Custom Bond: " << customBond.ToString() << std::endl;

    return 0;
}
