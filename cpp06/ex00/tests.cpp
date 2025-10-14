
#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

void test(const std::string& str)
{
    std::cout << "Input: " << str << std::endl;
    ScalarConverter::convert(str);
    std::cout << "------------------------" << std::endl;
}

void testChar()
{
    test("a");
    test("Z");
    test(" ");
    test("\n");
    test("\t");
    test("~");
    test("\x7F"); // DEL character
}

void testNumber()
{
    test("0");
    test("5");
    test("31");
    test("32");
    test("33");
    test("126");
    test("127");
    test("0.9");
    test("0.9999999999999");
    test("42");
    test("-42");
    test("42.0");
    test("-42.0");
    test("42.0f");
    test("-42.0f");
    test("42.f");
    test(".42f");
    test(".f");
    test("2147483647"); // INT_MAX
    test("-2147483648"); // INT_MIN
    test("2147483648"); // INT_MAX + 1
    test("-2147483649"); // INT_MIN - 1
    test("3.14f");
    test("-3.14f");
    test("3.4028235e+38f"); // FLT_MAX
    test("-3.4028235e+38f"); // -FLT_MAX
    test("3.4028236e+38f"); // FLT_MAX + 1
    test("-3.4028236e+38f"); // -FLT_MAX - 1
    test("2.2250738585072014e-308"); // DBL_MIN
    test("-2.2250738585072014e-308"); // -DBL_MIN
    test("1.7976931348623157e+308"); // DBL_MAX
    test("-1.7976931348623157e+308"); // -DBL_MAX
    test("1.7976931348623158e+308"); // DBL_MAX + 1
    test("-1.7976931348623158e+308"); // -DBL_MAX - 1
}

void testSpecial()
{
    test("nan");
    test("nanf");
    test("+inf");
    test("-inf");
    test("+inff");
    test("-inff");
}

void testInvalid()
{
    test("abc");
    test("12a34");
    test("++42");
    test("--42");
    test("3.14.15");
    test("3.14f15");
    test("");
    test(" ");
    test("!@#$%^&*()");
}

void testEdgeCases()
{
    test("127"); // Max char value
    test("128"); // Beyond char range
    test("-129"); // Below char range
    test("255"); // Extended ASCII
    test("256"); // Beyond extended ASCII
    test("3.4028235e+38f"); // FLT_MAX
    test("3.4028236e+38f"); // FLT_MAX + 1
    test("1.7976931348623157e+308"); // DBL_MAX
    test("1.7976931348623158e+308"); // DBL_MAX + 1
}

int main()
{
    std::cout << "=== Character Tests ===" << std::endl;
    testChar();

    std::cout << "=== Number Tests ===" << std::endl;
    testNumber();

    std::cout << "=== Special Floating-Point Values ===" << std::endl;
    testSpecial();

    std::cout << "=== Invalid Input Tests ===" << std::endl;
    testInvalid();

    std::cout << "=== Edge Case Tests ===" << std::endl;
    testEdgeCases();

    return 0;
}
