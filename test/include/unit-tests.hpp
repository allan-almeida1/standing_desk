#ifndef MY_TEST_FRAMEWORK_UNIT_TESTS_HPP
#define MY_TEST_FRAMEWORK_UNIT_TESTS_HPP

#include <functional>
#include <iostream>
#include <map>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

bool test_failed = false;
bool all_tests_passed = true;

// Define a type alias for test case functions
using TestFunction = std::function<void()>;

// Define a global vector to store test cases
static std::map<std::string, TestFunction> &get_test_functions()
{
    static std::map<std::string, TestFunction> test_functions;
    return test_functions;
}

#define TEST_CASE(name)                                                        \
    void name##_test_case();                                                   \
    namespace                                                                  \
    {                                                                          \
    struct Test##name                                                          \
    {                                                                          \
        Test##name()                                                           \
        {                                                                      \
            get_test_functions().insert(                                       \
                std::make_pair(#name, name##_test_case));                      \
        }                                                                      \
    } test_##name;                                                             \
    }                                                                          \
    void name##_test_case()

#define ASSERT_TRUE(expr)                                                      \
    test_failed = false;                                                       \
    if (!(expr))                                                               \
    {                                                                          \
        std::cerr << ANSI_COLOR_RED << "Assertion failed: "                    \
                  << "\n Expected: true\n Received: " << #expr                 \
                  << "\n Which expands to: " << expr << ANSI_COLOR_RESET       \
                  << std::endl;                                                \
        test_failed = true;                                                    \
        all_tests_passed = false;                                              \
        return;                                                                \
    }

#define ASSERT_FALSE(expr)                                                     \
    test_failed = false;                                                       \
    if (expr)                                                                  \
    {                                                                          \
        std::cerr << ANSI_COLOR_RED << "Assertion failed: "                    \
                  << "\n Expected: false\n Received: " << #expr                \
                  << "\n Which expands to: " << expr << ANSI_COLOR_RESET       \
                  << std::endl;                                                \
        test_failed = true;                                                    \
        all_tests_passed = false;                                              \
        return;                                                                \
    }

#define ASSERT_EQUAL(a, b)                                                     \
    test_failed = false;                                                       \
    if ((a) != (b))                                                            \
    {                                                                          \
        std::cerr << ANSI_COLOR_RED << "Assertion failed: "                    \
                  << "\n Expected: " << #a << "\n Which expands to: " << a     \
                  << "\n Received: " << #b << "\n Which expands to: " << b     \
                  << ANSI_COLOR_RESET << std::endl;                            \
        test_failed = true;                                                    \
        all_tests_passed = false;                                              \
        return;                                                                \
    }

#define ASSERT_NOT_EQUAL(a, b)                                                 \
    test_failed = false;                                                       \
    if ((a) == (b))                                                            \
    {                                                                          \
        std::cerr << ANSI_COLOR_RED << "Assertion failed: " << #a              \
                  << " == " << #b << ANSI_COLOR_RESET << std::endl;            \
        test_failed = true;                                                    \
        all_tests_passed = false;                                              \
        return;                                                                \
    }

void RUN_ALL_TESTS()
{
    for (const auto &test : get_test_functions())
    {
        std::cout << ANSI_COLOR_GREEN << "[RUNNING] " << test.first
                  << ANSI_COLOR_RESET << std::endl;
        test.second();
        if (!test_failed)
        {
            std::cout << ANSI_COLOR_GREEN << "[PASSED] " << test.first
                      << ANSI_COLOR_RESET << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << ANSI_COLOR_RED << "[FAILED] " << test.first
                      << ANSI_COLOR_RESET << std::endl
                      << std::endl;
        }
    }

    if (all_tests_passed)
    {
        std::cout << ANSI_COLOR_GREEN << "All tests passed!" << ANSI_COLOR_RESET
                  << std::endl;
    }
    else
    {
        std::cout << ANSI_COLOR_RED << "Some tests failed!" << ANSI_COLOR_RESET
                  << std::endl;
    }
}

#endif // MY_TEST_FRAMEWORK_UNIT_TESTS_HPP