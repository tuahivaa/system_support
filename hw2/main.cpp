#include <iostream>

#include "Bond.h"
#include "Bond.cpp"

using namespace std;

int main() {

    // Create a new semi-annually compounded bond
    Bond customBond("11/19/2035", 0.5, 0.08);

    // Print its characteristics using the ToString() function
    cout << "Custom Bond: " << customBond.ToString() << endl;

    cout<< "answer: " << customBond.PriceBond(4.2,0.5,0.08,0.07) << endl;


    return 0;
}
