
#ifndef _STREX_STRING_H_
#define _STREX_STRING_H_

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

#include "lexical_cast.h"

namespace strex
{
    template <typename CharT>
    struct ComposeTraits {};

    template <>
    struct ComposeTraits<char>
    {
        static const char placeholder = '%';

        static int char_to_int(char c)
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
    };

    template <>
    struct ComposeTraits<wchar_t>
    {
        static const wchar_t placeholder = L'%';

        static int char_to_int(wchar_t c)
        {
            switch (c)
            {
                case L'0':
                    return 0;
                case L'1':
                    return 1;
                case L'2':
                    return 2;
                case L'3':
                    return 3;
                case L'4':
                    return 4;
                case L'5':
                    return 5;
                case L'6':
                    return 6;
                case L'7':
                    return 7;
                case L'8':
                    return 8;
                case L'9':
                    return 9;
                default:
                    throw std::logic_error("not a number");
            }
        }
    };

    /**
     * Compose string.
     *
     * @param format the format string.
     **/
    template <typename CharT, typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    std::basic_string<CharT> _compose(const std::basic_string<CharT>& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
    {
        typedef std::basic_string<CharT> string_t;
        CharT pl = ComposeTraits<CharT>::placeholder;

        std::vector<string_t> args(10);
        args[0] = lexical_cast<string_t>(arg0);
        args[1] = lexical_cast<string_t>(arg1);
        args[2] = lexical_cast<string_t>(arg2);
        args[3] = lexical_cast<string_t>(arg3);
        args[4] = lexical_cast<string_t>(arg4);
        args[5] = lexical_cast<string_t>(arg5);
        args[6] = lexical_cast<string_t>(arg6);
        args[7] = lexical_cast<string_t>(arg7);
        args[8] = lexical_cast<string_t>(arg8);
        args[9] = lexical_cast<string_t>(arg9);

        std::basic_string<CharT> result;

        for (unsigned int i = 0; i < format.size(); i++)
        {
            if (format[i] == pl)
            {
                if (i + 1 < format.size())
                {
                    int idx = ComposeTraits<CharT>::char_to_int(format[i + 1]);
                    result += args.at(idx);
                    i++;
                }
                else
                {
                    throw std::logic_error("% at end of string.");
                }
            }
            else
            {
                result.push_back(format[i]);
            }
        }

        return result;
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
    {
        return _compose<char>(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, "");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, "", "");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, "", "", "");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, arg5, "", "", "", "");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
    {
        return compose(format, arg0, arg1, arg2, arg3, arg4, "", "", "", "", "");
    }

    template <typename T0, typename T1, typename T2, typename T3>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3)
    {
        return compose(format, arg0, arg1, arg2, arg3, "", "", "", "", "", "");
    }

    template <typename T0, typename T1, typename T2>
    std::string compose(const std::string& format, T0 arg0, T1 arg1, T2 arg2)
    {
        return compose(format, arg0, arg1, arg2, "", "", "", "", "", "", "");
    }

    template <typename T0, typename T1>
    std::string compose(const std::string& format, T0 arg0, T1 arg1)
    {
        return compose(format, arg0, arg1, "", "", "", "", "", "", "", "");
    }

    template <typename T0>
    std::string compose(const std::string& format, T0 arg0)
    {
        return compose(format, arg0, "", "", "", "", "", "", "", "", "");
    }

    inline
    std::string compose(const std::string& format)
    {
        return compose(format, "", "", "", "", "", "", "", "", "", "");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9)
    {
        return _compose<wchar_t>(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, L"");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, L"", L"");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, arg4, arg5, arg6, L"", L"", L"");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, arg4, arg5, L"", L"", L"", L"");
    }

    template <typename T0, typename T1, typename T2, typename T3, typename T4>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3, T4 arg4)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, arg4, L"", L"", L"", L"", L"");
    }

    template <typename T0, typename T1, typename T2, typename T3>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2, T3 arg3)
    {
        return wcompose(format, arg0, arg1, arg2, arg3, L"", L"", L"", L"", L"", L"");
    }

    template <typename T0, typename T1, typename T2>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1, T2 arg2)
    {
        return wcompose(format, arg0, arg1, arg2, L"", L"", L"", L"", L"", L"", L"");
    }

    template <typename T0, typename T1>
    std::wstring wcompose(const std::wstring& format, T0 arg0, T1 arg1)
    {
        return wcompose(format, arg0, arg1, L"", L"", L"", L"", L"", L"", L"", L"");
    }

    template <typename T0>
    std::wstring wcompose(const std::wstring& format, T0 arg0)
    {
        return wcompose(format, arg0, L"", L"", L"", L"", L"", L"", L"", L"", L"");
    }

    inline
    std::wstring wcompose(const std::wstring& format)
    {
        return wcompose(format, L"", L"", L"", L"", L"", L"", L"", L"", L"", L"");
    }
}

#endif
