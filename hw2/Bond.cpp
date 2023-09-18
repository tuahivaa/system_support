#include "Bond.h"
#include <cmath>

using namespace std;
// Default constructor
Bond::Bond() : expirationDate("01/01/0000"), frequencyOfPayments(0.0), couponRate(0.0) {}

// Constructor with parameters
Bond::Bond(const std::string& expirationDate, double frequencyOfPayments, double couponRate)
    : expirationDate(expirationDate), frequencyOfPayments(frequencyOfPayments), couponRate(couponRate) {}

// Copy constructor
Bond::Bond(const Bond& other)
    : expirationDate(other.expirationDate), frequencyOfPayments(other.frequencyOfPayments), couponRate(other.couponRate) {}

// Destructor
Bond::~Bond() {}

// ToString function
std::string Bond::ToString() const {
    return "Bond (" + expirationDate + "," + std::to_string(frequencyOfPayments) + "," + std::to_string(couponRate) + ")";
}

// Bond pricing function
double Bond::PriceBond(double timeToMaturity, double frequency, double c, double i_rate) const {
    /*
    double couponPayment = couponRate * 100; // Assuming face value  100
    double discountedCashFlow = 0.0;

    for (int i = 1; i <= (timeToMaturity * frequencyOfPayments); ++i) {
        double discountFactor = 1 / pow(1 + (currentInterestRate / frequencyOfPayments), i);
        discountedCashFlow += couponPayment * discountFactor;
    }

    // Add the face value at maturity
    discountedCashFlow += 100 * pow(1 + (currentInterestRate / frequencyOfPayments), timeToMaturity * frequencyOfPayments);

    */

    double discountedCashFlow = 0.0;
    double paymentDue = 0.0;
    double discountFactor = 0.0;
    double presentValue = 0.0;

    int integerPart = static_cast<int>(timeToMaturity);
    double fractionalPart = timeToMaturity - integerPart;
    std::cout << "Fractional part: " << fractionalPart << std::endl;

    double couponPayment = 100 * c * frequency;
    for (int i = 1; i<(integerPart*2)+1; i++){

        if (i == (integerPart*2+1)-1){
            if (fractionalPart == 0){
                couponPayment+=100;
            }
        }
        
        discountFactor = exp(-i*frequency*i_rate);
        discountedCashFlow += couponPayment * discountFactor;

        cout << "for i;" << i << ", amount= " << couponPayment << ", discountFacotr= " << discountFactor << " discountedCF= " << discountedCashFlow << endl;




        if(i == (integerPart*2+1)-1){
            cout << (integerPart*2+1)-1 << endl;
            if(fractionalPart > 0){
                cout << "couponPayment: " << couponPayment << " fraction: " <<  fractionalPart << " couponRate: " << couponRate << endl;
                cout << "Amount: " << (couponRate*100)*fractionalPart+100 << endl;

                discountFactor = exp(-i_rate*timeToMaturity);
                cout << "final discount Factor: " << discountFactor << endl;

                double pv = discountFactor*((couponRate*100)*fractionalPart+100);
                cout << "PV: " << pv <<endl;
                discountedCashFlow += pv;
                //couponPayment += (couponRate*100)*fractionalPart+100;
                //cout<< "inside if statement: " << couponPayment << endl;
            }
            // else{
            //     cout << "esle statement" << endl;
            //     couponPayment+=100;
            //     discountedCashFlow += couponPayment * discountFactor;
            // }
            
        }

        
    }


    return discountedCashFlow;
}
