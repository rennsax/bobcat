#include "datetime.ih"

unordered_map<string, int>   DateTime::s_zone = 
{
    {"CET",      60},
    {"CEST",    120},
};
    
mutex DateTime::s_mutex;
unordered_map<DateTime const *, DateTime::ZoneData> DateTime::s_pimpl;

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

