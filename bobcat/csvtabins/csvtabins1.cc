//#define XERR
#include "csvtabins.ih"

CSVTabIns::CSVTabIns(ostream &out, vector<FMT> const &format, unsigned idx, 
                     string const &sep, bool more)
:
    d_idx(idx),
    d_out(&out),
    d_format(format),
    d_sep(sep),
    d_useExtraFMT(false),
    d_more(more)
{}
