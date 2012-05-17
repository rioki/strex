
#include <UnitTest++/UnitTest++.h>

#include <strex/lexical_cast.h>

SUITE(lexcial_cast)
{
    TEST(int_to_string)
    {
        int i = 1236;
        std::string s = strex::lexical_cast<std::string>(i);
        CHECK_EQUAL("1236", s);
    }

    TEST(string_to_int)
    {
        std::string s = "1236";
        int i = strex::lexical_cast<int>(s);
        CHECK_EQUAL(1236, i);
    }

    TEST(int_to_wstring)
    {
        int i = 1236;
        std::wstring s = strex::lexical_cast<std::wstring>(i);
        CHECK(L"1236" == s);
    }

    TEST(wstring_to_int)
    {
        std::wstring s = L"1236";
        int i = strex::lexical_cast<int>(s);
        CHECK_EQUAL(1236, i);
    }

    TEST(throw_nonsense_cast)
    {
        float f = 12.0;
        CHECK_THROW(strex::lexical_cast<int>(f), strex::bad_lexical_cast);
    }

    TEST(throw_bad_format)
    {
        std::string s = "1236 32";
        CHECK_THROW(strex::lexical_cast<int>(s), strex::bad_lexical_cast);
    }

    TEST(chars_to_int)
    {
        int i = strex::lexical_cast<int>("1236");
        CHECK_EQUAL(1236, i);
    }

    TEST(wchars_to_int)
    {
        int i = strex::lexical_cast<int>(L"1236");
        CHECK_EQUAL(1236, i);
    }
}
