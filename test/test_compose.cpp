
#include <UnitTest++/UnitTest++.h>

#include <strex/compose.h>

SUITE(test_compose)
{
    TEST(no_args)
    {
        std::string s = strex::compose("This is a test.");
        CHECK_EQUAL("This is a test.", s);
    }

    TEST(no_argsw)
    {
        std::wstring s = strex::wcompose(L"This is a test.");
        CHECK(L"This is a test." == s);
    }

    TEST(arg1)
    {
        std::string s = strex::compose("%0", 10);
        CHECK_EQUAL("10", s);
    }

    TEST(args1w)
    {
        std::wstring s = strex::wcompose(L"%0", 10);
        CHECK(L"10" == s);
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

    TEST(args3w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2", 10, 9, 8);
        CHECK(L"10, 9, 8" == s);
    }

    TEST(arg4)
    {
        std::string s = strex::compose("%0, %1, %2, %3", 10, 9, 8, 7);
        CHECK_EQUAL("10, 9, 8, 7", s);
    }

    TEST(args4w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3", 10, 9, 8, 7);
        CHECK(L"10, 9, 8, 7" == s);
    }

    TEST(arg5)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4", 10, 9, 8, 7, 6);
        CHECK_EQUAL("10, 9, 8, 7, 6", s);
    }

    TEST(args5w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4", 10, 9, 8, 7, 6);
        CHECK(L"10, 9, 8, 7, 6" == s);
    }

    TEST(arg6)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5", 10, 9, 8, 7, 6, 5);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5", s);
    }

    TEST(args6w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4, %5", 10, 9, 8, 7, 6, 5);
        CHECK(L"10, 9, 8, 7, 6, 5" == s);
    }

    TEST(arg7)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6", 10, 9, 8, 7, 6, 5, 4);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4", s);
    }

    TEST(args7w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4, %5, %6", 10, 9, 8, 7, 6, 5, 4);
        CHECK(L"10, 9, 8, 7, 6, 5, 4" == s);
    }

    TEST(arg8)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7", 10, 9, 8, 7, 6, 5, 4, 3);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3", s);
    }

    TEST(args8w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4, %5, %6, %7", 10, 9, 8, 7, 6, 5, 4, 3);
        CHECK(L"10, 9, 8, 7, 6, 5, 4, 3" == s);
    }

    TEST(arg9)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7, %8", 10, 9, 8, 7, 6, 5, 4, 3, 2);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3, 2", s);
    }

    TEST(args9w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4, %5, %6, %7, %8", 10, 9, 8, 7, 6, 5, 4, 3, 2);
        CHECK(L"10, 9, 8, 7, 6, 5, 4, 3, 2" == s);
    }

    TEST(arg10)
    {
        std::string s = strex::compose("%0, %1, %2, %3, %4, %5, %6, %7, %8, %9, GO!", 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
        CHECK_EQUAL("10, 9, 8, 7, 6, 5, 4, 3, 2, 1, GO!", s);
    }

    TEST(args10w)
    {
        std::wstring s = strex::wcompose(L"%0, %1, %2, %3, %4, %5, %6, %7, %8, %9, GO!", 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
        CHECK(L"10, 9, 8, 7, 6, 5, 4, 3, 2, 1, GO!" == s);
    }
}
