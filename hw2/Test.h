#ifndef TEST
#define TEST

#include <unordered_map>
#include "Bond.h"



class Test {
public:
    Test();
    void runTests();

private:
    void test1(unordered_map<double, double> d);
    void test2();
    Bond a;

};

#endif // EXCEL_READER_TEST_HPP
