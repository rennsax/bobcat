//#define XERR
#include "csvtabins.ih"

CSVTabIns::CSVTabIns(ostream &out, vector<FMT> const &format, 
                     string const &sep)
:
    d_idx(0),
    d_out(&out),
    d_format(format),
    d_sep(sep),
    d_useExtraFMT(false)
{}
