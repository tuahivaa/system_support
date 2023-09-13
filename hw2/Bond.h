#ifndef BOND_H
#define BOND_H

#include <iostream>
#include <string>

class Bond {
private:
    std::string expirationDate;
    double frequencyOfPayments;
    double couponRate;

public:
    Bond();
    Bond(const std::string& expirationDate, double frequencyOfPayments, double couponRate);
    Bond(const Bond& other);
    ~Bond();

    std::string ToString() const;
    double PriceBond(double timeToMaturity, double frequency, double couponRate, double interestRate) const;
};

#endif