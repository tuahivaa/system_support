#include <iostream>

#include "Bond.h"
#include "Bond.cpp"
#include "Data.h"
#include "Data.cpp"
#include <vector>
#include <unordered_map>
#include "Test.h"
#include "Test.cpp"


using namespace std;

//  Bond_Ex3.csv

int main() {


    std::unordered_map<double, double> data;

    // Open the Excel CSV file
    std::ifstream file("./Bond_Ex3.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening the CSV file." << std::endl;
        return 1;
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
                std::cerr << "Error parsing data: " << e.what() << std::endl;
            }
        }
    }

    




    Test test;
    test.runTests();










    // Access values from the dictionary
    double desiredKey = 0; // Example key
    auto it = data.find(desiredKey);
    if (it != data.end()) {
        double desiredValue = it->second;
        std::cout << "Value at key " << desiredKey << " is " << desiredValue << std::endl;
    } else {
        std::cerr << "Key not found in the dictionary." << std::endl;
    }


    // Data excelFile;
    // string filePath = "./Bond_Ex3.csv";

    // if (excelFile.loadFromFile(filePath)) {
    //     // Data loaded successfully

    //     // Example: Get interest rate for maturity time 8.989
    //     double maturityTime = 9;
    //     double interestRate = excelFile.getInterestRate(maturityTime);

    //     std::cout << "Interest rate for maturity time " << maturityTime << ": " << interestRate << std::endl;
    
        
    
    
    
    
    // } else {
    //     std::cerr << "Failed to load data from the Excel file." << std::endl;
    // }

    // Create a new semi-annually compounded bond
    Bond customBond("11/19/2035", 0.5, 0.08);

    // Print its characteristics using the ToString() function
    // cout << "Custom Bond: " << customBond.ToString() << endl;

    cout<< "Answer: " << customBond.PriceBond(4.2,0.5,0.08,0.07) << endl;


    return 0;
}
