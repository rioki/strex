
#include "strings.h"

namespace strex
{
//------------------------------------------------------------------------------
    int char_to_int(char c)    
    {
        switch (c)
        {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            default:
                throw std::logic_error("not a number");
        }
    }

//------------------------------------------------------------------------------    
    std::string compose(const std::string& format)
    {
        return compose(format, "", "", "", "", "", "", "", "", "", "");
    }   
    
//------------------------------------------------------------------------------
    std::vector<std::string> explode(const std::string& str, const std::string& delimiter)
    {
        std::vector<std::string> gibs;
        size_t start = 0;
        size_t end = 0;

        while ((start != std::string::npos) && (start < str.size()))
        {
            end = str.find(delimiter, start);

            std::string gib;
            if (end == std::string::npos)
            {
                gib = str.substr(start);
                start = std::string::npos;
            }
            else
            {
                gib = str.substr(start, end - start);
                start = end + delimiter.size();
            }
            gibs.push_back(gib);
        }

        return gibs;
    }
    
}

