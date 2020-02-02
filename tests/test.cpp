#include "pch.h"
#include "../src/utility.hpp"

using namespace std::string_literals;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(UtilityFunctions, JoinStrings) {
    auto target{ "Hello, world"s };
    std::vector<std::string> test_case{ "Hello"s, "world"s };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}

TEST(UtilityFunctions, JoinIntegers) {
    auto target{ "3, 1, 4, 1, 59"s };
    std::vector<int> test_case{ 3, 1, 4, 1, 59 };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}

TEST(UtilityFunctions, JoinLongs) {
    auto target{ "3, 1, 4, 1, 59"s };
    std::vector<long> test_case{ 3, 1, 4, 1, 59 };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}

TEST(UtilityFunctions, JoinFloats) {
    auto target{ "3.14, 2.73, 1.5"s };
    std::vector<float> test_case{ 3.14f, 2.73f, 1.5f };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}

TEST(UtilityFunctions, JoinDoubles) {
    auto target{ "3.14, 2.73, 1.5"s };
    std::vector<double> test_case{ 3.14, 2.73, 1.5 };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}

TEST(UtilityFunctions, JoinBooleans) {
    auto target{ "true, true, false, true, false"s };
    std::vector<bool> test_case{ true, true, false, true, false };
    auto result = non_std::join(test_case);
    EXPECT_EQ(target, test_case);
}
