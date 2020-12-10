//#define XERR
#include "csvtable.ih"

void CSVTable::stream(string const &fname, ios::openmode mode)
{
    if (d_idx != 0)                 // not at the beginning of a row
        row();                      // then end the current row

    char fillChar = d_out->fill();          // keep the current fillChar

    streamReset();                          // reset *d_out to its original
                                            // settings

    d_strPtr = unique_ptr<std::ofstream>{ 
                    new ofstream(Exception::factory<ofstream>(fname, mode))
                };

    d_out = d_strPtr.get();
    streamFlags();

    d_out->fill(fillChar);
}
