
#ifndef _STREX_FILES_H_
#define _STREX_FILES_H_

#include <string>

namespace strex
{
    /**
     * Check if a file exists.
     *
     * @param name the name of the file
     * @return true if the file exists
     **/
    bool file_exists(const std::string& name);

    /**
     * Write a File
     *
     * @param name the name of the file
     * @param contents the contents of the file
     **/
    void write_file(const std::string& name, const std::string& contents);
    
    /**
     * Read a File
     *      
     * @param name the name of the file
     * @return The contents of the file.
     **/
    std::string read_file(const std::string& name);
    
    /**
     * Delete a file.
     *
     * @param name the name of the file
     **/
    void delete_file(const std::string& name);
}

#endif
