//#define XERR
#include "csvtable.ih"

    // insert fields values into *d_out
void CSVTable::operator()(string const &text)
{
    streamReset();

    CSVTabIns tabIns{ *d_out, d_format, d_sep };
    tabIns(text);
}
