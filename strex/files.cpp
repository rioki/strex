
#include "files.h"

#include <cstdio>
#include <stdexcept>
#include "compose.h"

namespace strex
{
//------------------------------------------------------------------------------
    bool file_exists(const std::string& name)
    {
        FILE* fh = fopen(name.c_str(), "r");
        if (fh != NULL)
        {
            fclose(fh);
            return true;
        }
        return false;
    }

//------------------------------------------------------------------------------
    void write_file(const std::string& name, const std::string& contents)
    {
        FILE* fh = NULL;
        try
        {
            fh = fopen(name.c_str(), "wb");
            if (fh == NULL)
            {
                throw std::runtime_error(compose("Could not open %0 for writing.", name));
            }
            
            size_t wcnt = 0;
            wcnt = fwrite(contents.c_str(), 1, contents.size(), fh);
            if (wcnt != contents.size())
            {
                throw std::runtime_error(compose("Failed to write %0.", name));
            }
            
            fclose(fh);
        }
        catch (...) 
        {
            fclose(fh);
            throw;
        }
    }
    
//------------------------------------------------------------------------------
    std::string read_file(const std::string& name)
    {
        FILE* fh = NULL;
        try
        {
            fh = fopen(name.c_str(), "rb");
            if (fh == NULL)
            {
                throw std::runtime_error(compose("Could not open %0 for reading.", name));
            }
            
            if (fseek(fh, 0, SEEK_END) != 0)
            {
                throw std::logic_error("Failed to seek to end.");
            }
            
            long size = ftell(fh);
            if (size == -1)
            {
                throw std::logic_error("Could not determine size of file.");
            }
            rewind(fh);
            
            std::vector<char> buff(size);
            
            size_t rcnt = 0;
            rcnt = fread(&buff[0], 1, size, fh);
                        
            if (rcnt != static_cast<size_t>(size))
            {
                throw std::runtime_error(compose("Failed to read %0.", name));
            }
            
            fclose(fh);
            
            return std::string(buff.begin(), buff.end());
        }
        catch (...) 
        {
            fclose(fh);
            throw;
        }
    }
    
//------------------------------------------------------------------------------
    void delete_file(const std::string& name)
    {
        if (remove(name.c_str()) != 0)
        {
            throw std::runtime_error(compose("Failed to delete %0.", name));
        }
    }
}

