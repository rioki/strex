
#include <UnitTest++/UnitTest++.h>

#include <strex/strings.h>

SUITE(lexcial_cast)
{
    TEST(explode)
    {
        std::string pattern = "one;two;three";
        std::vector<std::string> bits = strex::explode(pattern, ";");
        
        CHECK_EQUAL(3, bits.size());
        CHECK_EQUAL("one", bits.at(0));
        CHECK_EQUAL("two", bits.at(1));
        CHECK_EQUAL("three", bits.at(2));
    }
    
    TEST(explode2)
    {
        std::string pattern = ";two;three";
        std::vector<std::string> bits = strex::explode(pattern, ";");
        
        CHECK_EQUAL(3, bits.size());
        CHECK_EQUAL("", bits.at(0));
        CHECK_EQUAL("two", bits.at(1));
        CHECK_EQUAL("three", bits.at(2));
    }
    
    TEST(explode3)
    {
        std::string pattern = "one;two;";
        std::vector<std::string> bits = strex::explode(pattern, ";");
        
        CHECK_EQUAL(3, bits.size());
        CHECK_EQUAL("one", bits.at(0));
        CHECK_EQUAL("two", bits.at(1));
        CHECK_EQUAL("", bits.at(2));
    }    
}