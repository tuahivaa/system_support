#include "test.h"
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <cmath>
#include <iomanip> 

#include "Bond.h"


using namespace std;

Test::Test() {
    a = Bond("11/19/2035", 0.5, 0.08);
}


void Test::runTests() {
    
    std::unordered_map<double, double> data;

    // Open the Excel CSV file
    std::ifstream file("./Bond_Ex3.csv");
    if (!file.is_open()) {
        std::cerr << "TESTING Error opening the CSV file." << std::endl;
    }

    std::string firstLine;
    std::getline(file, firstLine);
    // Read and parse the CSV file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream linestream(line);
        std::string key_str, value_str;

        
        // Split the line into key and value using a comma delimiter
        if (std::getline(linestream, key_str, ',') && std::getline(linestream, value_str)) {
            try {
                double key = std::stod(key_str);
                double value = std::stod(value_str);
                data[key] = value;
            } catch (const std::exception& e) {
                std::cerr << "TESTING Error parsing data: " << e.what() << std::endl;
            }
        }
    }

    test1(data);
    test2();



    

}

void Test::test1(unordered_map<double, double> d){
    cout << "Running Test 1: Accessing values..." << endl;
    unordered_map<double, double> data = d;
    assert(data[8.9945] == 0.0068875);
    assert(data[8.989] == 0.006775);
    assert(data[8.9562] == 0.0066063);
    cout << "Running Test 1: PASSED" << endl;
}

void Test::test2(){
    cout << "Running Test 2: Bond Pricing..." << endl;
    double t = round(a.PriceBond(4.2,0.5,0.08,0.07) * 1000.0 ) / 1000.0 ;
    // cout << t << endl;
    assert( t == 103.145);
    cout << "Running Test 2: PASSED" << endl;
}
