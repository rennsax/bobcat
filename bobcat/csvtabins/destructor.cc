//#define XERR
#include "csvtabins.ih"

CSVTabIns::~CSVTabIns()
{
    if (d_more)
        return;

    if (*d_idx != 0)             // something has been inserted
    {
        for (; *d_idx != d_format.size(); )  // fill remaining columns with 
            insert(' ');                    // spaces

        *d_out << '\n';         // then end the line
        *d_idx = 0;             // and back to column 0
    }
}
