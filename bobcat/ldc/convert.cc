#include "ldc.ih"

void LDC::convert()
{
    while (*d_begin.valuePtr >= d_radix)   // reducible values are available
    {
        reduce();                           // reduce d_begin till all the
                                            // value's bytes were processed

        swap();                             // continue with the div 10 value

    }

    if (*d_begin.valuePtr != 0)
        d_converted += '0' + *d_begin.ptr;  // add the remaining != 0 quotient
                                            // as the final (MS) digit

                                            // the MSD is not at idx 0 and is
                                            // therefore first displayed.
    reverse(d_converted.begin(), d_converted.end());    
}
