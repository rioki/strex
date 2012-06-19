
#include <UnitTest++/UnitTest++.h>

#include <strex/strings.h>

SUITE(strings)
{
    TEST(int_to_string)
    {
        int i = 1236;
        std::string s = strex::to_string(i);
        CHECK_EQUAL("1236", s);
    }

    TEST(string_to_int)
    {
        std::string s = "1236";
        int i = strex::from_string<int>(s);
        CHECK_EQUAL(1236, i);
    }

    TEST(throw_bad_format)
    {
        std::string s = "1236 32";
        CHECK_THROW(strex::from_string<int>(s), std::invalid_argument);
    }

    TEST(chars_to_int)
    {
        int i = strex::from_string<int>("1236");
        CHECK_EQUAL(1236, i);
    }

    TEST(no_args)
    {
        std::string s = strex::compose("This is a test.");
        CHECK_EQUAL("This is a test.", s);
    }

    TEST(arg1)
    {
        std::string s = strex::compose("%0", 10);
        CHECK_EQUAL("10", s);
    }

    TEST(arg2)
    {
        std::string s = strex::compose("%0, %1", 10, 9);
        CHECK_EQUAL("10, 9", s);
    }

    TEST(arg3)
    {
        std::string s = strex::compose("%0, %1, %2", 10, 9, 8);
        CHECK_EQUAL("10, 9, 8", s);
    }

    TEST(arg4)
    {
        std::string s = strex::compose("%0, %1, %2, %3", 10, 9, 8, 7);
        CHECK_EQUAL("10, 9, 8, 7", s);
    }

    TEST(arg5)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4", 10, 9, 8, 7, 6);
        CHECK_EQUAL("10, 9, 8, 7, 6", s);
    }

    TEST(arg6)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5", 10, 9, 8, 7, 6, 5);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5", s);
    }

    TEST(arg7)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6", 10, 9, 8, 7, 6, 5, 4);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4", s);
    }

    TEST(arg8)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7", 10, 9, 8, 7, 6, 5, 4, 3);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3", s);
    }

    TEST(arg9)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7, %8", 10, 9, 8, 7, 6, 5, 4, 3, 2);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3, 2", s);
    }

    TEST(arg10)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7, %8, %9, GO!", 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3, 2, 1, GO!", s);
    }
}
