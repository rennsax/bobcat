#include "datetime.ih"

unordered_map<string, DateTime::DSTSpec>   DateTime::ZoneNames::s_zone = 
{
    {"CET", DSTSpec{ 60 } }
};
    
unordered_map<DateTime const *, unique_ptr<DateTime::DSTInfo>> 
                                                  DateTime::DSTInfo::s_pimpl;
mutex DateTime::DSTInfo::s_mutex;

char const *DateTime::s_month[] =
{
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
};

char const *DateTime::s_day[] =
{
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"
};

Pattern DateTime::ZoneNames::s_spec           // string to match assumed
    {                                       // trimmed, used by match.cc 
        //   1
        R"_(^(\w+)\s*:\s*)_"                // ID :
        // 2
        "("
        //  3           4   5
        R"_((true|false)(\s+(\d+))?|)_"     // true/false [nMinutes shift]
        //  6   
        R"_((\d+)|)_"                       // nMinutes shift

                                            // hh:mm hh:mm [nMinutes shift]
        //  7           8        9   10
        R"_((\d{3,4})\s+(\d{3,4})(\s+(\d+))?)_"
        ")$",
        true, 11
    };

