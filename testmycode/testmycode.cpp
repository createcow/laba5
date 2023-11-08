#include "CppUnitTest.h"
#include "YourCode.h" // Include your code header here

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(YourCodeTests) {
public:
    TEST_METHOD(Test_function_validInput) {
        double result = function(5.0, 2.0);
        Assert::AreEqual(1.0 / 2.0 - 1.0 / 1.0, result, 0.0001);
    }

    TEST_METHOD(Test_function_invalidInput) {
        // Test for invalid n value (less than 4)
        try {
            double result = function(3.0, 2.0);
            Assert::Fail(L"Exception should have been thrown");
        }
        catch (const InvalidInputException& e) {
            // Exception expected
        }
    }

    TEST_METHOD(Test_function_negativeX) {
        double result = function(6.0, -1.0);
        Assert::AreEqual(1.0 / (-1.0) - 1.0 / 1.0, result, 0.0001);
    }

    TEST_METHOD(Test_function_zeroX) {
        double result = function(7.0, 0.0);
        Assert::AreEqual(1.0 / 0.0 - 1.0 / 1.0, result, 0.0001);
    }

    TEST_METHOD(Test_function_positiveX) {
        double result = function(5.0, 2.0);
        Assert::AreEqual(1.0 / (2.0 - 0 + 2.0 * 0) + 1.0 / (2.0 - 0 + 2.0 * 1), result, 0.0001);
    }
};
