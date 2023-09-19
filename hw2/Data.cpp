#include "Data.h"
#include <fstream>
#include <sstream>

Data::Data() {
    // Constructor
}

bool Data::loadFromFile(const std::string& filePath) {
    // Open the Excel file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double maturityTime, interestRate;
        if (iss >> maturityTime >> interestRate) {
            data[maturityTime] = interestRate;
        }
    }

    file.close();
    
    return true; 
}

double Data::getInterestRate(double maturityTime) {
    
    auto it = data.find(maturityTime);
    if (it != data.end()) {
        return it->second;
    } else {
        return 0.0;
    }
}

const std::map<double, double>& Data::getData() const {
    // Return a reference to the underlying data (the entire map)
    return data;
}