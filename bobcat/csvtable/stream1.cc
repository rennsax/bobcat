//#define XERR
#include "csvtable.ih"

void CSVTable::stream(std::ostream &out)
{
    if (d_idx != 0)                 // not at the beginning of a row
        row();                      // then end the current row

    char fillChar = d_out->fill();          // keep the current fillChar

    streamReset();                          // reset *d_out to its original
                                            // settings

    d_out = &out;                           // switch stream
    streamFlags();

    out.fill(fillChar);
}
