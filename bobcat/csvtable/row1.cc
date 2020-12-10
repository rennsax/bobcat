//#define XERR
#include "csvtable.ih"

CSVTabIns CSVTable::row(unsigned idx)
{
    idx = checkInsertIdx(idx);

    return CSVTabIns{ &d_idx, *d_out, d_format, idx, d_sep, false};
}
