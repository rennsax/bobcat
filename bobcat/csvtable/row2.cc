//#define XERR
#include "csvtable.ih"

void CSVTable::row(string const &text, unsigned idx)
{
    streamReset();

    CSVTabIns tabIns{ &d_idx, *d_out, d_format, idx, d_sep, false };
    tabIns(text);

}
