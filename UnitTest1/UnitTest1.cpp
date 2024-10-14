#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(SumNegativesFunctionTests)
    {
    public:
        TEST_METHOD(TestSumNegativesWithNoNegatives)
        {
            // Test case with no negative values
            double arr[] = { 1.0, 2.0, 3.0, 4.0 };
            const int size = sizeof(arr) / sizeof(arr[0]);
            Assert::AreEqual(0, SumNegatives(arr, size), L"Expected sum is 0 when there are no negative values.");
        }

        TEST_METHOD(TestSumNegativesWithSingleNegative)
        {
            // Test case with a single negative value
            double arr[] = { -1.0, 2.0, 3.0, 4.0 };
            const int size = sizeof(arr) / sizeof(arr[0]);
            Assert::AreEqual(0, SumNegatives(arr, size), L"Expected sum is 0 when there is only one negative value.");
        }
    };
}