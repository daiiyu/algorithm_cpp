//
// Created by daiyuz on 7/2/20.
//


#include "gtest/gtest.h"
#include "maxValue.hpp"
#include "ugly_number.h"

TEST(Solution, maxValue)
{
    vector<vector<int>> testCase1{{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> testCase2{{1,2,5},{3,2,1}};
    Solution solution;

    EXPECT_EQ(12, solution.maxValue(testCase1));
    EXPECT_EQ(9, solution.maxValue(testCase2));
}

TEST(SolutionUglyNumber, uglyNumber)
{
    SolutionUglyNumber solutionUglyNumber;

    EXPECT_EQ(1, solutionUglyNumber.nthUglyNumber(1));
    EXPECT_EQ(2, solutionUglyNumber.nthUglyNumber(2));
    EXPECT_EQ(12, solutionUglyNumber.nthUglyNumber(10));
}