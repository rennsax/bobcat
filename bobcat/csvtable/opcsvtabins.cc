//#define XERR
#include "csvtable.ih"

CSVTable::operator CSVTabIns()
{
    return CSVTabIns{ *d_out, d_format, d_sep };
}
