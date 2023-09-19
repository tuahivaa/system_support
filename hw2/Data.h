#ifndef EXCELDATA_H
#define EXCELDATA_H

#include <map>
#include <string>

class Data {
public:
    Data();

    bool loadFromFile(const std::string& filePath);

    double getInterestRate(double maturityTime);

    const std::map<double, double>& getData() const;
private:
    std::map<double, double> data;
};

#endif