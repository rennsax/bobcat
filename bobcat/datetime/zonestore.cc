#include "datetime.ih"

DateTime::Zone const &DateTime::Zone::store(
                                string const &name, 
                                string const &shift, string const &dstSpec,
                                string const &dstBegin, string const &dstEnd)
{
    requireAlpha(name);
    return storeIUO(name, shift, dstSpec, dstBegin, dstEnd);
}
