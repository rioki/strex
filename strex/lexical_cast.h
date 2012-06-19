
#ifndef _STREX_LEXICAL_CAST_H_
#define _STREX_LEXICAL_CAST_H_

#include <typeinfo>
#include <sstream>
#include <string>

namespace strex
{
    /**
     * Exception throw when a lexical_cast fails to convert two types.
     **/
    class bad_lexical_cast : public std::bad_cast
    {
    public:
        bad_lexical_cast()
        : std::bad_cast() {}

        virtual const char* what() const throw ()
        {
            return "bad_lexical_cast";
        }
    };

    template <typename ToT>
    struct LexicalTraits
    {
        template <typename FromT>
        ToT convert(FromT value)
        {
            throw bad_lexical_cast();
        }

        ToT convert(const std::string& str)
        {
            std::stringstream buff(str);
            ToT value;
            buff >> value;
            if (buff.eof())
            {
                return value;
            }
            else
            {
                throw bad_lexical_cast();
            }
        }

        ToT convert(const char* str)
        {
            return convert(std::string(str));
        }

        ToT convert(const std::wstring& str)
        {
            std::wstringstream buff(str);
            ToT value;
            buff >> value;
            if (buff.eof())
            {
                return value;
            }
            else
            {
                throw bad_lexical_cast();
            }
        }

        ToT convert(const wchar_t* str)
        {
            return convert(std::wstring(str));
        }
    };

    template <>
    struct LexicalTraits<std::string>
    {
        template <typename FromT>
        std::string convert(FromT value)
        {
            std::stringstream buff;
            buff << value;
            return buff.str();
        }
    };

    template <>
    struct LexicalTraits<std::wstring>
    {
        template <typename FromT>
        std::wstring convert(FromT value)
        {
            std::wstringstream buff;
            buff << value;
            return buff.str();
        }
    };


    /**
     * Lexical Cast
     *
     * Convert a value from string and from string.
     **/
    template <typename ToT, typename FromT>
    ToT lexical_cast(FromT value)
    {
        LexicalTraits<ToT> traits;
        return traits.convert(value);
    }
}

#endif
