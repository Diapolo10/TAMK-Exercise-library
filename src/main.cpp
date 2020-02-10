#include "utility.hpp"

const std::vector<long> num_test_data {3, 2, 1, 22, -8, 13, 19, 5};
const std::vector<std::string> str_test_data{ "Hello", "world" };

// Global tracker that keeps count on all test cases
int test_case_count{};
int completed_test_case_count{};

template <typename T>
bool test_case_eq(T test, T expected) {
    
    ++test_case_count;
    bool result = test == expected;

    if (result) {
        ++completed_test_case_count;
    }

    return result;
}


int main() {

    // Testing non_std
    if (!(test_case_eq(non_std::string_split(non_std::string_join(str_test_data), ", "), str_test_data))) {
        std::cerr << "non_std base test failed\n";
    }
    if (!(test_case_eq(non_std::string_join(str_test_data, ""), std::string{"Helloworld"}))) {
        std::cerr << "non_std::string_join did not join empty delimiters\n";
    }
    if (!(test_case_eq(non_std::string_join(str_test_data, "OwO"), std::string{ "HelloOwOworld" }))) {
        std::cerr << "non_std::string_join did not join empty delimiters\n";
    }


    // Testing itertools
    if (!(test_case_eq(non_std::itertools::max(num_test_data), 22L))) {
        std::cerr << "non_std::itertools::max did not find largest number\n";
    }
    if (!(test_case_eq(non_std::itertools::max(str_test_data), std::string{ "world" }))) {
        std::cerr << "non_std::itertools::max did not find largest string\n";
    }
    if (!(test_case_eq(non_std::itertools::min(num_test_data), -8L))) {
        std::cerr << "non_std::itertools::min did not find smallest number\n";
    }
    if (!(test_case_eq(non_std::itertools::min(str_test_data), std::string{ "Hello" }))) {
        std::cerr << "non_std::itertools::min did not find smallest string\n";
    }
    if (!(test_case_eq(non_std::itertools::fmap(non_std::functools::inc<long>, num_test_data), std::vector<long>{4, 3, 2, 23, -7, 14, 20, 6}))) {
        std::cerr << "non_std::itertools::fmap did not apply inc-function correctly\n";
    }
    if (!(test_case_eq(non_std::itertools::fmap(non_std::functools::dec<long>, num_test_data), std::vector<long>{2, 1, 0, 21, -9, 12, 18, 4}))) {
        std::cerr << "non_std::itertools::max did not apply dec-function correctly\n";
    }

    // Testing math
    if (!(test_case_eq(non_std::math::sum(num_test_data), 57L))) {
        std::cerr << "non_std::math::sum did not sum integers correctly\n";
    }

    std::cout << "Result: " << completed_test_case_count << "/" << test_case_count << " test cases finished successfully.\n";

    return 0;
}