//#define XERR
#include "csvtable.ih"

CSVTable::CSVTable(ostream &out, string const &sep)
:
    d_out(&out),
    d_sep(sep),

    d_flags(out.flags()),               // original stream flags
    d_precision(out.precision()),
    d_fillChar(out.fill())
{
    out.setf(ios::fixed, ios::floatfield);
}
