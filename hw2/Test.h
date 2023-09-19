#include <unordered_map>

#ifndef TEST
#define TEST

class Test {
public:
    Test();
    void runTests();

private:
    void test1(unordered_map<double, double> d);
    void test2();

};

#endif // EXCEL_READER_TEST_HPP
