//#define XERR
#include "csvtable.ih"

CSVTabIns CSVTable::more(unsigned idx)
{
    idx = checkInsertIdx(idx);

    return CSVTabIns{ &d_idx, *d_out, d_format, idx, d_sep, true };
}
