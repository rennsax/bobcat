#include "iostreambuf.ih"

int IOStreambuf::sync()
{        
    d_out->flush();
    return not d_out->good();
}
