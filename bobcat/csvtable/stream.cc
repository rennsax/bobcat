//#define XERR
#include "csvtable.ih"

void CSVTable::stream(std::ostream &out)
{
    char fillChar = d_out->fill();          // use fillChar for out

    streamReset();                          // reset *d_out to its original
                                            // settings

    d_flags = out.flags();                  // obtain the stream's flags,
    d_precision = out.precision();          // precision, and fill char
    d_fillChar = out.fill();

    d_out = &out;                           // switch stream

    out.setf(ios::fixed, ios::floatfield);
    out.fill(fillChar);
}
