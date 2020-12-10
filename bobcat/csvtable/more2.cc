//#define XERR
#include "csvtable.ih"

void CSVTable::more(std::string const &text, unsigned idx)
{
    idx = checkInsertIdx(idx);

    CSVTabIns tabIns{ &d_idx, *d_out, d_format, idx, d_sep, true };
    tabIns(text);
}
