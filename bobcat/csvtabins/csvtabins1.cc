//#define XERR
#include "csvtabins.ih"

CSVTabIns::CSVTabIns(unsigned *tabIdx, ostream &out, 
                     vector<FMT> const &format, 
                     unsigned startIdx, string const &sep, bool more)
:
    d_tabIdx(tabIdx),
    d_idx(startIdx),
    d_out(&out),
    d_format(format),
    d_sep(sep),
    d_useExtraFMT(false),
    d_more(more)
{
    if (startIdx != 0)
    {
        d_idx = 0;
        for (; startIdx--; )
            insert(' ');
    }
}

