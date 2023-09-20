This is a C++ program that demonstrates bond pricing and data analysis. The program reads financial data from a CSV file, performs calculations on bond pricing, and accesses data using C++ classes. Below, you'll find a description of the code, its purpose, and how to use it.


1. Introduction<a name="introduction"></a>

This program is designed to perform the following tasks:

Read financial data from a CSV file named "Bond_Ex3.csv."
Calculate the time difference between two dates in years.
Access values from a dictionary-like data structure.
Calculate the price of a bond using provided parameters.
2. Dependencies<a name="dependencies"></a>
The program requires the following libraries and components:

C++ Standard Library
<iostream>: For input and output operations.
<vector>: For working with vectors.
<unordered_map>: For creating a dictionary-like data structure.
<ctime>: For handling date and time calculations.

3. Getting Started<a name="getting-started"></a>

To compile and run this program, follow these steps:

Ensure you have a C++ compiler installed (e.g., g++).
Download the source code files (Bond.h, Bond.cpp, Data.h, Data.cpp, Test.h, Test.cpp, and main.cpp) to a local directory.
Place the CSV file "Bond_Ex3.csv" in the same directory as the source code files.

4. How to Use<a name="how-to-use"></a>

To use this program, follow these steps:

g++ main.cpp -o main.cpp

Run the compiled program:

./bond_pricing


The program will perform the following actions:

Read financial data from "Bond_Ex3.csv" and store it in a dictionary-like data structure.
Run a series of tests using the Test class to check the functionality of the code.
Calculate the time difference in years between two specified dates.
Access a specific value from the data dictionary based on a given key.
Create a bond object and calculate its price based on provided parameters.
The results will be printed to the console.