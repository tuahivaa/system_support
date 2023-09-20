#include <iostream>

#include "Bond.h"
#include "Bond.cpp"
#include "Data.h"
#include "Data.cpp"
#include <vector>
#include <unordered_map>
#include "Test.h"
#include "Test.cpp"
#include <ctime>
#include <iostream>


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




    std::tm start_date = {0, 0, 0, 3, 7, 115};  // August 3, 2015 (month is 0-based)
    std::tm end_date = {0, 0, 0, 31, 11, 120};  // December 31, 2020 (month is 0-based)

    // Convert the dates to time_t
    std::time_t start_time = std::mktime(&start_date);
    std::time_t end_time = std::mktime(&end_date);

    // Calculate the time difference in seconds
    std::time_t difference = end_time - start_time;

    // Calculate the number of days in the difference
    int days = difference / (60 * 60 * 24);

    // Print the time difference in days
    // std::cout << "Time difference in days: " << days << std::endl;
    
    cout << "Time difference in years: " << days/365.00 << endl;





    // Access values from the dictionary
    double desiredKey = 5.411; // Example key
    auto it = data.find(desiredKey);
    double desiredValue;
    if (it != data.end()) {
        desiredValue = it->second;
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

    cout<< "Answer: " << customBond.PriceBond(desiredKey,0.5,0.05,desiredValue) << endl;

    











    return 0;
}
