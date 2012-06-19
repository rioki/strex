
#include "strings.h"

namespace strex
{
//------------------------------------------------------------------------------
    std::vector<std::string> explode(const std::string& str, const std::string& delim)
    {
        std::vector<std::string> gibs;
        size_t start = 0;
        size_t end = 0;

        while ((start != std::string::npos) && (start < str.size()))
        {
            end = str.find(delim, start);

            std::string gib;
            if (end == std::string::npos)
            {
                gib = str.substr(start);
                start = std::string::npos;
            }
            else
            {
                gib = str.substr(start, end - start);
                start = end + delim.size();
            }
            gibs.push_back(gib);
        }
        
        // special case, when the delimiter is at the end
        if (start == str.size())
        {
            gibs.push_back(std::string());
        }

        return gibs;
    }
    
}

