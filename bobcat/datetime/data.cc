#include "datetime.ih"

unordered_map<string, DateTime::ZoneData>   DateTime::ZoneNames::s_zone = 
{
    {"CET", ZoneData{ 60, DSTSpec{ 60 } } }
};
    
unordered_map<DateTime const *, unique_ptr<DateTime::Pimpl>> 
                                                  DateTime::Pimpl::s_pimpl;
mutex DateTime::Pimpl::s_mutex;

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
        //   1           2
        R"_(^(\w+)\s*:\s*(-?\d+)\s+)_"      // ID : zoneshift: minutes
        // 3
        "("
        //  4           5   6
        R"_((true|false)(\s+(\d+))?|)_"     // true/false [nMinutes shift]
        //  7   
        R"_((\d+)|)_"                       // nMinutes shift

                                            // hhmm hhmm [nMinutes shift]
        //  8           9        10  11
        R"_((\d{3,4})\s+(\d{3,4})(\s+(-?\d+))?)_"
        ")$",
        true, 12
    };

