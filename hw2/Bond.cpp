#include "Bond.h"

Bond::Bond() : expirationDate("01/01/0000"), frequencyOfPayments(0.0), couponRate(0.0) {}

Bond::Bond(const std::string& expirationDate, double frequencyOfPayments, double couponRate)
    : expirationDate(expirationDate), frequencyOfPayments(frequencyOfPayments), couponRate(couponRate) {}

Bond::Bond(const Bond& other)
    : expirationDate(other.expirationDate), frequencyOfPayments(other.frequencyOfPayments), couponRate(other.couponRate) {}

Bond::~Bond() {}

std::string Bond::ToString() const {
    return "Bond (" + expirationDate + "," + std::to_string(frequencyOfPayments) + "," + std::to_string(couponRate) + ")";
}
