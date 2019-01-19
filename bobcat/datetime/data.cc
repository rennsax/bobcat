#include "datetime.ih"

unordered_map<string, int>   DateTime::ZoneNames::s_zone = 
{
    {"CET",      60},
    {"CEST",    120},
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

