#include "datetime.ih"

// static
void DateTime::DSTSpec::split(uint8_t *mon, uint8_t *day,
                              std::string const &in)
{
    int mmdd = stoul(in);

    *mon = mmdd / 100 - 1;
    *day = mmdd % 100;

    tm ts{0};
    ts.tm_mon = *mon;
    ts.tm_mday = *day;

    if (mktime(&ts) == -1 or ts.tm_mon != *mon or ts.tm_mday != *day)
        throw 1;
}
