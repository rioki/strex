
#include <UnitTest++/UnitTest++.h>

#include <strex/files.h>

SUITE(files)
{
    TEST(read_write_file)   
    {
        std::string text = "This is a test.\nFor reading a file.\n";
        
        strex::write_file("text.txt", text);
        
        std::string text2 = strex::read_file("text.txt");
        CHECK_EQUAL(text, text2);
        
        strex::delete_file("text.txt");
        CHECK(strex::file_exists("text.txt") == false);        
    }
}