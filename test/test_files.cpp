
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
    
    TEST(get_dir_seperator)
    {
#ifdef _WIN32
        CHECK_EQUAL('\\', strex::get_dir_seperator());
#else
        CHECK_EQUAL('/', strex::get_dir_seperator());
#endif    
    }
    
    TEST(simple_join_path)
    {
#ifdef _WIN32
        CHECK_EQUAL("foo\\bar", strex::join_path("foo", "bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo\\", "bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo", "\\bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo\\", "\\bar"));
        
        CHECK_EQUAL("foo\\bar", strex::join_path("foo/", "bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo", "/bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo/", "/bar"));
        
        CHECK_EQUAL("foo\\bar", strex::join_path("foo/", "\\bar"));
        CHECK_EQUAL("foo\\bar", strex::join_path("foo\\", "/bar"));
#else
        CHECK_EQUAL("foo/bar", strex::join_path("foo", "bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo/", "bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo", "/bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo/", "/bar"));
        
        CHECK_EQUAL("foo/bar", strex::join_path("foo\\", "bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo", "\\bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo\\", "\\bar"));
        
        CHECK_EQUAL("foo/bar", strex::join_path("foo/", "\\bar"));
        CHECK_EQUAL("foo/bar", strex::join_path("foo\\", "/bar"));
#endif    
    }
    
    TEST(get_dir)
    {
        CHECK_EQUAL("foo", strex::get_dir("foo/bar"));
        CHECK_EQUAL("foo", strex::get_dir("foo\\bar"));
    }
}