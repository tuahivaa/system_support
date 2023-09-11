#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

double average(const std::map<std::string, double>& dateToRate, const std::string& userDate) {
    double average = 0.0;
    int numRates = 0;

    for (const auto& pair : dateToRate) {
        if (pair.first <= userDate) {
            average += pair.second;
            numRates++;
        } else {
            break; // Stop when we reach the user's date
        }
    }

    if (numRates > 0) {
        average /= numRates;
    }

    return average;
}

double find_rate(const std::map<std::string, double>& dateToRate, const std::string& userDate) {
    auto it = dateToRate.find(userDate);
    if (it != dateToRate.end()) {
        return it->second;
    } else {
        return -1.0;
    }
}


int main()
{
    vector<double> rate;
    vector<string> date;

    ifstream file("./hw1_H.15_Baa_Data.csv");

    for (int i = 0; i < 6; ++i) {
        string line;
        if (!getline(file, line)) {
            cerr << "Error reading header line " << i + 1 << std::endl;
            return 1;
        }
    }

// code for loading rate and date vectors from the file hw1_H.15_Baa_Data.csv
// the headers should be handled properly. do not delete them manually

   map<string, double> dateToRate;

   string line;
   while (getline(file, line)) {
        istringstream iss(line);
        string dateStr, rateStr;
        
        if (getline(iss, dateStr, ',')) {
            if (getline(iss, rateStr, ',')) {
                double rate = stod(rateStr);
                dateToRate[dateStr] = rate;
            }
        }
    }

   file.close();


   while(true){

      string userDate;
      cout << "Enter a date (YYYY-MM): ";
      cin >> userDate;

      if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting program." << std::endl;
            break;
        }


      double r = find_rate(dateToRate, userDate);

      if (r<0){
        cout << "Couldn't find the date, make sure it follows this Format (YYYY-MM)" << endl;
      } else{
        double a = average(dateToRate, userDate);

        cout << "Rate for " << userDate << ": " << r << endl;
        cout << "Difference between this rate the average rate since 1919-01 is: " << (r-a) << endl;
        cout << "The average rate since 1919-01 is: " << a <<endl;
      }

      

   }

   return 0.0;
}

